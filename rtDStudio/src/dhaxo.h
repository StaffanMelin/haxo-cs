#pragma once

#include <fcntl.h>
#include <sys/ioctl.h>
extern "C"
{
#include <linux/i2c-dev.h>
#include <i2c/smbus.h>
}

#include <gpiod.h>
#include <map>
#include <cmath>
#include <stdio.h>
#include <iostream>

#include "dsound.h"

#define DHAXO_KEY_ROWS 8
#define DHAXO_KEY_COLS 3
#define DHAXO_PRESSURE_START 2048 // 530000
#define DHAXO_PRESSURE_MAX 3330 // 270000



class DHaxo
{
public:

	DHaxo() {}
	~DHaxo() {}

    struct Config
    {
		uint8_t channel;
        DSound *synth;
    };

	void Init(const Config&);
	void Process();
	void Exit();

private:

	// DStudio
	uint8_t channel_;
    DSound *synth_;
	// module
	std::map<uint32_t, uint8_t> notemap_;
	int32_t pressure_baseline_;
	uint8_t note_, note_last_ = MIDI_NOTE_NONE;
	float vol_, vol_last_ = 0.0;
	// i2c
	int i2cfile_;
	struct gpiod_chip *chip_;
	// gpio
	struct gpiod_line *line_r_[DHAXO_KEY_ROWS];
	struct gpiod_line *line_c_[DHAXO_KEY_COLS];

	// private methods
	float Pressure();
	uint32_t Keys();

	// helper methods
	bool get_bit_at(uint32_t input, uint8_t n);
	void set_bit_at(uint32_t* output, uint8_t n);
	void clear_bit_at(uint32_t* output, uint8_t n);
	uint8_t map_to_midi(uint32_t);

	void show(uint32_t keys)
	{
	    for (int b = 0; b < DHAXO_KEY_ROWS * DHAXO_KEY_COLS; b++)
		{
			if (get_bit_at(keys, b))
			{
				std::cout << "1";
			}
		}
		std::cout << " " << keys << "\n";
	}
};
