//This sketch is for setting time on the ds1307 module.
//This is because if the project is reset then the attiny again sets the default time on the rtc module
// to prevent that we seperately set time on rtc module using the arduino uno and attiny85 only reads time...
#include <Wire.h>
#include "RTClib.h"

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
