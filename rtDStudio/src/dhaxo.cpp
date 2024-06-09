#include <fstream>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "../rtDStudio/src/dstudio.h"
#include "dhaxo.h"
#include "dsynth.h"

#define DEBUG

void DHaxo::Init(const Config& config)
{
	synth_ = config.synth;
    channel_ = 0;
    hexo_connected_ = config.hexo_connected;
    for (size_t i = 0; i < DHAXO_TARGET_MAX; i++)
    {
        hexo_target_[i] = config.hexo_target[i];
    }
    for (size_t i = 0; i < DHAXO_VALUE_MAX; i++)
    {
        hexo_value_[i] = 0;
    }

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
            notemap_[map_key] = map_value;
        }
    }
    file.close();

    #ifdef DEBUG
    for(auto it = notemap_.cbegin(); it != notemap_.cend(); ++it)
    {
        std::cout << it->first << " " << it->second << "\n";
    }
    std::cout << "\n";
    #endif

    // I2C
	char filename[20];
  	const int adapter_nr = 1;
	const int addr = 0x4D;

    snprintf(filename, 19, "/dev/i2c-%d", adapter_nr);
    i2cfile_ = open(filename, O_RDWR);
    if (ioctl(i2cfile_, I2C_SLAVE, addr) < 0)
    {
        exit(1); // TODO
    }

    usleep(1000); // TODO really necessary?

    // TODO calibrate pressure sensor = read when not blowing (+ 10%?)
    pressure_baseline_ = 0;

    // GPIO
	const int pin_r[DHAXO_KEY_ROWS] = {13, 12, 16, 17, 20, 22, 23, 24};
	const int pin_c[DHAXO_KEY_COLS] = {25, 26, 27};
	const char *chipname = "gpiochip0";

    // Open GPIO chip
    chip_ = gpiod_chip_open_by_name(chipname);

    // Open GPIO lines
    for (uint8_t i = 0; i < DHAXO_KEY_ROWS; i++)
    {
        line_r_[i] = gpiod_chip_get_line(chip_, pin_r[i]);
        gpiod_line_request_output(line_r_[i], "example1", 1); // HI default
    }
    for (int i = 0; i < DHAXO_KEY_COLS; i++)
    {
        line_c_[i] = gpiod_chip_get_line(chip_, pin_c[i]);
        gpiod_line_request_input(line_c_[i], "example1");
    }

    if (hexo_connected_)
    {
        // TODO error check
        serial_port_.Open("/dev/ttyACM0");
        serial_port_.SetBaudRate(LibSerial::BaudRate::BAUD_38400);
        serial_port_.SetCharacterSize(LibSerial::CharacterSize::CHAR_SIZE_8);
        serial_port_.SetFlowControl(LibSerial::FlowControl::FLOW_CONTROL_NONE);
        serial_port_.SetParity(LibSerial::Parity::PARITY_ODD);
        serial_port_.SetStopBits(LibSerial::StopBits::STOP_BITS_1) ;

        serial_buffer_next_ = 0;
    }
}



uint8_t DHaxo::map_to_midi(uint32_t input)
{
    std::map<uint32_t, uint8_t>::iterator it;
    uint8_t ret;

    it = notemap_.find(input);
    if (it == notemap_.end())
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
// value is normalized from 0.0-1.0
float DHaxo::Pressure()
{
    uint8_t value[32];
	uint32_t pressure;
 	float pressure_normalized; // 0.0 - 1.0
    #ifdef DEBUG
    static uint32_t pmin = 3000;
    static uint32_t pmax = 0;
    #endif

    ssize_t bytes = read(i2cfile_, value, 2);
    pressure = (value[0] << 8) | (value[1]);

    #ifdef DEBUG
    if (pmin > pressure)
        pmin = pressure;
    if (pmax < pressure)
        pmax = pressure;
    std::cout << "read: " << pressure  << " pmin:" << pmin << " pmax:" << pmax << "\n";
    #endif

    if (pressure > DHAXO_PRESSURE_START)
    {
        pressure -= DHAXO_PRESSURE_START;
    } else {
        pressure = 0;
    }

    if (pressure > DHAXO_PRESSURE_MAX)
    {
        pressure = DHAXO_PRESSURE_MAX;
    }

    pressure_normalized = pressure / (float)DHAXO_PRESSURE_MAX;

    return pressure_normalized;
}



// GPIO
uint32_t DHaxo::Keys()
{
    static uint32_t keymap = 0;
    uint8_t key_index = 0;

    for (uint8_t r = 0; r < DHAXO_KEY_ROWS; r++)
    {
        gpiod_line_set_value(line_r_[r], 0);
        usleep(10); // let row pin settle

        for (uint8_t c = 0; c < DHAXO_KEY_COLS; c++)
        {
            // keystate now
            bool is_pressed = (gpiod_line_get_value(line_c_[c]) == 0);

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
        gpiod_line_set_value(line_r_[r], 1);
        usleep(10);
    }

    return keymap;
}



void DHaxo::DispatchController(DSynth::Param controller_target, float controller_value)
{

    // 
    // !!!neg values (mod wheel: )
    /*
        float 0.0 - 1.0 or -1.0 - 1.0
        value_normalized can be negative (eg mod wheel)
        but negative values are only allowed/working for:
            transpose, tune, detune
            DSYNTH_PARAM_TUNE,
            DSYNTH_PARAM_DETUNE,
            DSYNTH_PARAM_TRANSPOSE,
    */
   DSynth::Param target = hexo_target_[controller_target];
   if (!(target == DSynth::DSYNTH_PARAM_TUNE ||
       target == DSynth::DSYNTH_PARAM_DETUNE ||
       target == DSynth::DSYNTH_PARAM_TRANSPOSE))
    {
        controller_value = abs(controller_value);
    }

    synth_->ChangeParam(target, controller_value);

}



void DHaxo::Process()
{
    uint32_t keys = Keys();
    float pressure = Pressure();
    #ifdef DEBUG
    std::cout << "dhaxo pressure: " << pressure  << "  keys " << keys << "\n";
    #endif

    vol_ = pressure;
    if (vol_ != vol_last_)
    {
        synth_->SetLevel(channel_, vol_);
        vol_last_ = vol_;
    }

    uint8_t note_ = map_to_midi(keys);
    if (note_ != MIDI_NOTE_NONE)
    {
        if (note_ != note_last_)
        {
            if (vol_ > 0.0f)
            {
                if (note_ > 0)
                {
                    // finish old note
                    synth_->SetLevel(channel_, 0.0f); // TODO neccessary? Doesn't let note finish env. OK for mono though.
                    synth_->MidiIn(MIDI_MESSAGE_NOTEOFF + channel_, note_last_, 0);
                    // start new note
                    synth_->SetLevel(channel_, vol_);
                }
                synth_->MidiIn(MIDI_MESSAGE_NOTEON + channel_, note_, 100);
                note_last_ = note_;
            }
        }
        if (vol_ < 0.05f && note_last_ > 0)
        {
            synth_->MidiIn(MIDI_MESSAGE_NOTEOFF + channel_, note_last_, 0);
            note_last_ = 0;
        }
    } else {
        // no note, in control mode?
        if (pressure < 0.1f)
        {
            // up
            #ifdef DEBUG
            show(keys);
            #endif
            // down

        }
    }

    // TODO NOTE if target is pressure/volume/amp then
    // controller will "overwrite" pressure sensor
    // ie TARGET_AMP is stupid?
    if (hexo_connected_)
    {
        /*
            Format of input:
            <pitch>,<modwheel>,<distancesensor>\n

            pitch = read value from analog pot, int
            modwheel = read value from analog pot, int
            distance sensor = distance in cm's, int

            so the targets and values must match per index
            ie
            order of received value -> hexo_value_[n]
            hexo_value_[n] is sent to hexo_target_[n]
        */

        //int available = serial_port_.GetNumberOfBytesAvailable() > 0;
        uint8_t hexo_controller = 0;
        while (serial_port_.GetNumberOfBytesAvailable() > 0)
        {
            char c;
            serial_port_.ReadByte(c);
            serial_buffer_[serial_buffer_next_++] = c;
            if (c == '\n')
            {
                char *token;
                char *sbuffer;
                char *token_end;
                sbuffer = serial_buffer_;
                // we now have a line of values, 16bit ints separated by commas
                while ((token = strsep(&sbuffer,";")) != NULL)
                {
                    float token_value = strtof(token, &token_end);

                    hexo_value_[hexo_controller] = token_value;

                    hexo_controller++;
                }
                serial_buffer_next_ = 0;
                for (uint8_t i = 0; i < (hexo_controller - 1); i++)
                {
                    DispatchController(hexo_target_[i], hexo_value_[i]);
                }
            }
        }
    }

    usleep(10); // .01ms
}



void DHaxo::Exit()
{
    // Release lines and chip
    for (int r = 0; r < DHAXO_KEY_ROWS; r++)
    {
        gpiod_line_release(line_r_[r]);
    }
    for (int c = 0; c < DHAXO_KEY_COLS; c++)
    {
        gpiod_line_release(line_c_[c]);
    }
    gpiod_chip_close(chip_);
    close(i2cfile_);

    if (hexo_connected_)
    {
        serial_port_.Close();
        // delete serial_buffer_;
    }
}
