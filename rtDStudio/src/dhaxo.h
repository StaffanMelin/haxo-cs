#pragma once

extern "C"
{
#include <linux/i2c-dev.h>
#include <i2c/smbus.h>
}
#include <sys/ioctl.h>
#include <fcntl.h>
#include <gpiod.h>
#include <map>

#include "dsound.h"

#define ROWS 8
#define COLS 3

class DHaxo
{
public:

	DHaxo() {}
	~DHaxo() {}

    struct Config
    {
    	float sample_rate;
		uint8_t channels;
        DSound *synth;
    };

	void Init(const Config&);
	void Process();
	void Exit();

private:

	bool get_bit_at(uint32_t input, uint8_t n);
	void set_bit_at(uint32_t* output, uint8_t n);
	void clear_bit_at(uint32_t* output, uint8_t n);
	uint32_t keymap_;
	std::map<uint32_t, uint8_t> notemap;
	// i2c
	int adapter_nr = 1;
	char filename[20];
	int i2cfile;
	int addr = 0x4D;
	uint8_t reg = 0x10;
	int32_t res;
	char buf[10];

	// gpio
	int pin_r[ROWS] = {13, 12, 16, 17, 20, 22, 23, 24};
	int pin_c[COLS] = {25, 26, 27};
	const char *chipname = "gpiochip0";
	struct gpiod_chip *chip;
	struct gpiod_line *line_r[ROWS];
	struct gpiod_line *line_c[COLS];
	int val[ROWS][COLS];

	// DStudio
	float sample_rate_;
	uint8_t channels_;
    DSound *synth_;

};
