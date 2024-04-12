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
    std::cout << "Init DHaxo\n";
    
    sample_rate_ = config.sample_rate;
	channels_ = config.channels;
	synth_ = config.synth;

    keymap_ = 0;

    // read and parse dhaxo_notemap.json
    /*
    {
        "0": 73,
        "1": 85,
        "32": 74,
        "33": 86,
        ...
        "13444224": 58,
        "13444240": 58
        }
    }
    */
    std::ifstream file("../rtDStudio/src/dhaxo_notemap.json");
    std::string line;

    while (std::getline(file, line)) {
        //output.append(line);
        if (!((line.rfind("{", 0) == 0) || (line.rfind("}", 0) == 0))) {
            // else split at : and extract string (to int) before it, and uint8_t after
            
            size_t index_colon = line.find(":");
            size_t line_len = line.length();
            std::cout << line << "\n";
            uint32_t map_key = std::stoi(line.substr(0, index_colon));
            // stoi() doesn't care about trailing comma
            uint8_t map_value = std::stoi(line.substr(index_colon + 1, line_len - index_colon));
            // data strcut? std::map
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
    std::cout << "map2midii in:" << input << "\n";

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

    std::cout << "Map to note:" << +ret << "\n";

    std::cout << "map2midix\n";
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




void DHaxo::Process()
{

    // I2C
    res = i2c_smbus_read_word_data(i2cfile, reg);

    // GPIO
    int key_index = 0;

    for (int r = 0; r < ROWS; r++)
    {
        gpiod_line_set_value(line_r[r], 0);
        usleep(10); // let row pin settle
        for (int c = 0; c < COLS; c++)
        {
            val[r][c] = gpiod_line_get_value(line_c[c]);
            // keystate now
            bool is_pressed = (gpiod_line_get_value(line_c[c]) == 0);
            // keystate has changed?
            if (get_bit_at(keymap_, key_index) != is_pressed) {
                show();
                if (is_pressed) {
                    std::cout << "pressed:" << key_index << "\n";
                    set_bit_at(&keymap_, key_index);
                    // send to mixer
                    uint8_t note = map_to_midi(keymap_);
                    if (note != MIDI_NOTE_NONE)
                    {
                        synth_->MidiIn(MIDI_MESSAGE_NOTEON + 0, note, 100);
                        std::cout << "DHaxo Note on\n";
                    }
                } else {
                    uint8_t note = map_to_midi(keymap_);
                    clear_bit_at(&keymap_, key_index);
                    if (note != MIDI_NOTE_NONE)
                    {
                        synth_->MidiIn(MIDI_MESSAGE_NOTEOFF + 0, note, 100);
                        std::cout << "DHaxo Note off\n";
                    }
                }
            }
            key_index++;
        }
        gpiod_line_set_value(line_r[r], 1);
        usleep(10);
    }

    // get MIDI from keys
    // ie map keymap_ to MIDI note
    // get/set VOLume from pressure
    // synth_->MidiIn(status, d0, d1);



    usleep(10);

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
}