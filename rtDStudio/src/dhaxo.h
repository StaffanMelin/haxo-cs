#pragma once

extern "C"
{
#include <linux/i2c-dev.h>
#include <i2c/smbus.h>
}
#include <sys/ioctl.h>
#include <fcntl.h>

#include <gpiod.h>

#define ROWS 8
#define COLS 3

class DHaxo
{
public:
	Haxo() {}
	~Haxo() {}
	void Init();
	void Process();
	void Exit();

private:
	// i2c
	int adapter_nr = 1;
	char filename[20];
	int file;
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
};
