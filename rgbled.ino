/*
 Name:		rgbled.ino
 Created:	8/5/2018 2:28:23 AM
 Author:	Matt
*/

#include "arduino.h"
#include "rgbled.h"

// build first led bulb object
rgbled led1(9, 10, 11); // 9 is the pin Red is plugged into
						// 10 is the pin Green is plugged into
						// 11 is the pin Blue is plugged into


void setup() {
	led1.green();
	delay(10);
}

// the loop function runs over and over again until power down or reset
void loop() {
	led1.showRgbColorSpectrum(10);
}
