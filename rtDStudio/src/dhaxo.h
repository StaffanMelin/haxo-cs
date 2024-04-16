#pragma once

#include <fcntl.h>
#include <sys/ioctl.h>
//#include <i2c/i2ch.h>


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
#define DHAXO_PRESSURE_SAMPLES 4
#define DHAXO_PRESSURE_MAX 40000.0 // float
#define DHAXO_PRESSUE_NORMALIZED_MIN 0.15
#define DHAXO_PRESSUE_NORMALIZED_MAX 0.90

template<typename T, size_t S>
class DRingBuffer
{
	public:

		void Init(T value)
		{
			Fill(value);
		}

		void Fill(T value)
		{
			for (size_t i = 0; i < S; i++)
			{
				buffer[i] = value;
			}
		}

		void Insert(T value)
		{
			buffer[index] = value;
			index = (index + 1) % S;
		}

		T Mean()
		{
			T sum = 0;
			for (size_t i = 0; i < S; i++)
			{
				sum += (buffer[i] * buffer[i]);
				// sum += buffer[i];
			}
			return std::sqrt(sum / S);
			// return sum / S;
		}

	private:
		T buffer[S];
		size_t index;
};


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

	float Pressure();
	uint32_t Keys();

	bool get_bit_at(uint32_t input, uint8_t n);
	void set_bit_at(uint32_t* output, uint8_t n);
	void clear_bit_at(uint32_t* output, uint8_t n);
	uint8_t map_to_midi(uint32_t);

	std::map<uint32_t, uint8_t> notemap;
    DRingBuffer<float, DHAXO_PRESSURE_SAMPLES> ringbuffer;
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
	float sample_rate_;
	uint8_t channels_;
    DSound *synth_;

	//void show();
};
