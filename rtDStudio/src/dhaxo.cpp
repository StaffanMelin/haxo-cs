#include <unistd.h>
#include <iostream>

#include "dhaxo.h"

#include <stdio.h>

void DHaxo::Init()
{
    // I2C
    snprintf(filename, 19, "/dev/i2c-%d", adapter_nr);
    file = open(filename, O_RDWR);
    if (ioctl(file, I2C_SLAVE, addr) < 0)
    {
        exit(1);
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

void DHaxo::Process()
{
    // I2C
    res = i2c_smbus_read_word_data(file, reg);

    // GPIO
    for (int r = 0; r < ROWS; r++)
    {
        gpiod_line_set_value(line_r[r], 0);
        usleep(10); // let row pin settle
        for (int c = 0; c < COLS; c++)
        {
            val[r][c] = gpiod_line_get_value(line_c[c]);
        }
        gpiod_line_set_value(line_r[r], 1);
        usleep(10);
    }

    std::cout << "\n";
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            std::cout << val[r][c] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    usleep(100000);
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
}
