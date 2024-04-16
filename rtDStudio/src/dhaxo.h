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

#include "dsound.h"

#define ROWS 8
#define COLS 3
#define DHAXO_PRESSURE_START 530000
#define DHAXO_PRESSURE_MAX 270000



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

	float Pressure();
	uint32_t Keys();

	bool get_bit_at(uint32_t input, uint8_t n);
	void set_bit_at(uint32_t* output, uint8_t n);
	void clear_bit_at(uint32_t* output, uint8_t n);
	uint8_t map_to_midi(uint32_t);

	std::map<uint32_t, uint8_t> notemap;
	int32_t pressure_baseline;

	uint8_t note, last_note = 0;
	float vol, last_vol = 0.0;

	// i2c
	int adapter_nr = 1;
	char filename[20];
	int i2cfile;
	int addr = 0x4D;
	uint8_t reg = 0x10;
	char buf[10];

	// gpio
	int pin_r[ROWS] = {13, 12, 16, 17, 20, 22, 23, 24};
	int pin_c[COLS] = {25, 26, 27};
	const char *chipname = "gpiochip0";
	struct gpiod_chip *chip;
	struct gpiod_line *line_r[ROWS];
	struct gpiod_line *line_c[COLS];

	// DStudio
	uint8_t channel_;
    DSound *synth_;

	//void show();
};
