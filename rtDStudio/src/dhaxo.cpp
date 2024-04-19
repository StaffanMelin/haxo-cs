#include <fstream>
#include <iostream>
#include <map>
#include <stdio.h>

#include <string>
#include <unistd.h>

#include "../rtDStudio/src/dstudio.h"
#include "dhaxo.h"



void DHaxo::Init(const Config& config)
{
	channel_ = config.channel;
	synth_ = config.synth;

    // read and parse dhaxo_notemap.json
    /*
    {
        "0": 73,
        "1": 85,
        ...
        "13444224": 58,
        "13444240": 58
        }
    }
    */
    std::ifstream file("../rtDStudio/src/dhaxo_notemap.json");
    std::string line;

    while (std::getline(file, line)) {
        if (!((line.rfind("{", 0) == 0) || (line.rfind("}", 0) == 0))) {
            // else split at : and extract string (to int) before it, and uint8_t after            
            size_t index_colon = line.find(":");
            size_t line_len = line.length();
            uint32_t map_key = std::stoi(line.substr(0, index_colon));
            // stoi() doesn't care about trailing comma
            uint8_t map_value = std::stoi(line.substr(index_colon + 1, line_len - index_colon));
            notemap[map_key] = map_value;
        }
    }
    file.close();

    for(auto it = notemap.cbegin(); it != notemap.cend(); ++it)
    {
        std::cout << it->first << " " << it->second << "\n";
    }
    std::cout << "\n";

    // I2C
    snprintf(filename, 19, "/dev/i2c-%d", adapter_nr);
    i2cfile = open(filename, O_RDWR);
    if (ioctl(i2cfile, I2C_SLAVE, addr) < 0)
    {
        exit(1); // TODO
    }

    usleep(1000); // TODO really necessary?

    // TODO set from read data
    pressure_baseline = 0;

    // GPIO

    // Open GPIO chip
    chip = gpiod_chip_open_by_name(chipname);

    // Open GPIO lines
    for (int i = 0; i < ROWS; i++)
    {
        line_r[i] = gpiod_chip_get_line(chip, pin_r[i]);
        gpiod_line_request_output(line_r[i], "example1", 1); // HI default
    }
    for (int i = 0; i < COLS; i++)
    {
        line_c[i] = gpiod_chip_get_line(chip, pin_c[i]);
        gpiod_line_request_input(line_c[i], "example1");
    }
}



uint8_t DHaxo::map_to_midi(uint32_t input)
{
    std::map<uint32_t, uint8_t>::iterator it;
    uint8_t ret;

    it = notemap.find(input);
    if (it == notemap.end())
    {
        ret = MIDI_NOTE_NONE;
    }
    else
    {
        ret = it->second;
    }

    return ret;
}



bool DHaxo::get_bit_at(uint32_t input, uint8_t n) {
    if (n < 32) {
        return (input & (1 << n)) != 0;
    } else {
        return false;
    }
}

void DHaxo::set_bit_at(uint32_t* output, uint8_t n) {
    if (n < 32) {
        *output |= (1 << n);
    }
}

void DHaxo::clear_bit_at(uint32_t* output, uint8_t n) {
    if (n < 32) {
        *output &= !(1 << n);
    }
}



// get pressure from sensor on I2C
float DHaxo::Pressure()
{
    uint8_t value[32];
	uint32_t pressure;
 	float pressure_normalized; // 0.0 - 1.0

    ssize_t bytes = read(i2cfile, value, 2);
    pressure = (value[0] << 8) | (value[1];

    std::cout << "read: " << pressure  << "\n";
    if (pressure > DHAXO_PRESSURE_START)
    {
        pressure -= DHAXO_PRESSURE_START;
    } else {
        pressure = 0;
    }

    std::cout << "read: " << pressure  << "\n";
    if (pressure > DHAXO_PRESSURE_MAX)
    {
        pressure = DHAXO_PRESSURE_MAX;
    }

    pressure_normalized = pressure / (float)DHAXO_PRESSURE_MAX;
    std::cout << "pressure: " << pressure << " norm:" << pressure_normalized << "\n";

    return pressure_normalized;
}



// GPIO
uint32_t DHaxo::Keys()
{
    static uint32_t keymap = 0;

    int key_index = 0;

    for (int r = 0; r < ROWS; r++)
    {
        gpiod_line_set_value(line_r[r], 0);
        usleep(10); // let row pin settle

        for (int c = 0; c < COLS; c++)
        {
            // keystate now
            bool is_pressed = (gpiod_line_get_value(line_c[c]) == 0);

            // keystate has changed since last check?
            if (get_bit_at(keymap, key_index) != is_pressed) {
                if (is_pressed) {
                    set_bit_at(&keymap, key_index);
                } else {
                    clear_bit_at(&keymap, key_index);
                }
            }

            key_index++;
        }
        gpiod_line_set_value(line_r[r], 1);
        usleep(10);
    }

    return keymap;
}



void DHaxo::Process()
{

    uint32_t keys = Keys();
    float pressure = Pressure();

    vol = pressure;
    if (vol != last_vol)
    {
        synth_->SetLevel(channel_, vol);
        last_vol = vol;
    }

    uint8_t note = map_to_midi(keys);
    if (note != MIDI_NOTE_NONE)
    {
        if (note != last_note)
        {
            if (vol > 0.0f)
            {
                if (last_note > 0)
                {
                    // finish old note
                    synth_->SetLevel(channel_, 0.0f); // hmmm....neccessary?
                    synth_->MidiIn(MIDI_MESSAGE_NOTEOFF + channel_, last_note, 0);
                    // start new note
                    synth_->SetLevel(channel_, vol);
                    // hmmm...vol?
                }
                synth_->MidiIn(MIDI_MESSAGE_NOTEON + channel_, note, 100);
                last_note = note;
            }
        }
        if (vol == 0.0 && last_note > 0)
        {
            synth_->MidiIn(MIDI_MESSAGE_NOTEOFF + channel_, last_note, 0);
            last_note = 0;
        }
    }

    usleep(10); // .1ms
}



void DHaxo::Exit()
{
    // Release lines and chip
    for (int r = 0; r < ROWS; r++)
    {
        gpiod_line_release(line_r[r]);
    }
    for (int c = 0; c < COLS; c++)
    {
        gpiod_line_release(line_c[c]);
    }
    gpiod_chip_close(chip);
    close(i2cfile);
}

// debug
/*
void DHaxo::show()
{
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            std::cout << +val[r][c];
        }
        std::cout << "\n";
    }
    std::cout << "\n" << keymap_ << "\n";
}*/