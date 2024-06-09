/*
  Hexo

  Expression pedal interface for the Haxophone

  https://github.com/StaffanMelin/haxo-cs

  staffan.melin@oscillator.se

  License: LGPL3

  Version: 20240530
  
*/

#include <HCSR04.h>

// select the pin for the LED
uint8_t pin_ctrl_pitch = 1;
uint8_t pin_ctrl_mod = 2;
uint8_t pin_led = 13;
uint8_t pin_trig = 8;
uint8_t pin_echo = 7;

// prep for calibration
#define CTRL_PITCH_MIN 1440
#define CTRL_PITCH_MAX 2740
#define CTRL_PITCH_MID 2080
uint16_t ctrl_pitch_min = CTRL_PITCH_MIN;
uint16_t ctrl_pitch_max = CTRL_PITCH_MAX;
uint16_t ctrl_pitch_mid = CTRL_PITCH_MID;
#define CTRL_MOD_MIN 1750
#define CTRL_MOD_MAX 2900
uint16_t ctrl_mod_min = CTRL_MOD_MIN;
uint16_t ctrl_mod_max = CTRL_MOD_MAX;
// dist: distance in mm's, upper bound = freeze previous value
#define CTRL_DIST_MIN 0
#define CTRL_DIST_MAX 200
uint16_t ctrl_dist_min = CTRL_DIST_MIN;
uint16_t ctrl_dist_max = CTRL_DIST_MAX;

// read value coming from the sensor
uint16_t ctrl_pitch_val = 0;
uint16_t ctrl_mod_val = 0;
uint16_t ctrl_dist_val = 0;
uint16_t ctrl_dist_val_prev = 0;

// store normalized value
float ctrl_pitch_norm;
float ctrl_mod_norm;
float ctrl_dist_norm;

// blink
bool blink = false;

 // initialisation class HCSR04 (trig pin , echo pin)
HCSR04 hc(pin_trig, pin_echo);



void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(pin_led, OUTPUT);

  // Set analog out resolution to max, 10-bits
  analogWriteResolution(10);

  // Set analog input resolution to max, 12-bits
  analogReadResolution(12);

  Serial.begin(38400);
}



void loop() {

  // read
  /*
    dist: cm
  */

  // normalized: map() and constrain()
  // not done in haxophone as it has no knowledge of the physical properties of the sensors

  // read pitch wheel
  ctrl_pitch_val = analogRead(pin_ctrl_pitch);
  ctrl_pitch_norm = map(
                    constrain(ctrl_pitch_val, ctrl_pitch_min, ctrl_pitch_max),
                    ctrl_pitch_min, ctrl_pitch_max, 
                    -1000, 1000
                    ) / 1000.0f;
  
  // read mod wheel
  //    mod: 1410 - 2080 - 2740 (calculated mid 2075)
  ctrl_mod_val = analogRead(pin_ctrl_mod);
  ctrl_mod_norm = map(
                    constrain(ctrl_mod_val, ctrl_mod_min, ctrl_mod_max),
                    ctrl_mod_min, ctrl_mod_max, 
                    0, 1000
                    ) / 1000.0f;
  
  // read distance, convert to whole mm's
  float ctrl_dist_valf = hc.dist(); // cm
  ctrl_dist_val = (int)(ctrl_dist_valf * 10); // mm, int
  if (ctrl_dist_val > ctrl_dist_max)
  {
    ctrl_dist_val = ctrl_dist_val_prev;
  } else {
    ctrl_dist_val_prev = ctrl_dist_val;
  }
  ctrl_dist_norm = map(
                    ctrl_dist_val,
                    ctrl_dist_min, ctrl_dist_max, 
                    0, ctrl_dist_max
                    ) / (float)ctrl_dist_max;
  
  // write to serial port
  // 3 decimal places

  Serial.print(ctrl_pitch_norm, 3);
  Serial.print(",");
  Serial.print(ctrl_mod_norm, 3);
  Serial.print(",");
  Serial.print(ctrl_dist_norm, 3);
  Serial.println("");

  digitalWrite(pin_led, blink);
  blink = !blink;

  delay(60);
}
