# haxo-cs

Prerelease, More to come -- soon! Check the issues for what will happen.

Code for making sounds with the [Haxophone](https://www.crowdsupply.com/cardona-bits/haxophone).

Combining my DSound software synth library (based on Daisy SP) with the [Haxophone hardware](https://github.com/cardonabits/haxo-hw).

Audio: [demo0.ogg](https://github.com/StaffanMelin/haxo-cs/blob/master/demo0.ogg) (All sounds from example-12-haxo demo project, incuding fx, running on the RPi.)

Code is running on an Raspberry Pi 4B using the current Lite (headless) Raspian OS.

As for now, the magic happens mainly in [dhaxo.cpp](https://github.com/StaffanMelin/haxo-cs/blob/master/rtDStudio/src/dhaxo.cpp).

License: GPL3

Contact: staffan.melin@oscillator.se

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
