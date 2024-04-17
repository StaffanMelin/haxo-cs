# haxo-cs

Prerelease, only example 12 working (for the Haxo). The rest is from a previous project (reference). More to come -- soon! :)

Code for making sounds with the [Haxophone](https://www.crowdsupply.com/cardona-bits/haxophone).

Combining my DSound software synth library (based on Daisy SP) with the [Haxophone hardware](https://github.com/cardonabits/haxo-hw).

Code is running on an Raspberry Pi 4B using the current Lite (headless) Raspian OS.

License: GPL3

## Setting up

Install raspi lite

`sudo raspi-config`

* expand file system
* enable i2c
* gpio is already enabled

edit /boot/firmware/config.txt
```
# Enable audio (loads snd_bcm2835)
# dtparam=audio=on
dtoverlay=max98357a
```

### I2C

`sudo apt install libi2c-dev`

Test:

`i2cdetect -l`

### GPIO

libgpiod already installed

`sudo apt install libgpiod-dev`

Test:
`gpiodetect`
`gpioinfo`

### RtAudio

`sudo apt install libasound2-dev libevent-dev`

Needs:
* libasound2 libasound2-data *libasound2-dev
* +libevent-pthread-... *libevent-dev
*=not already installed

##
