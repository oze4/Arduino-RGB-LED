/*
Name:    rgbled.ino
Created: 8/5/2018 2:28:23 AM
Author:  Matt
*/


#include "arduino.h"
#include "rgbled.h"
#include "multi_rgbled.h"


// build first led bulb object
rgbled led_one(9, 10, 11); // 9 is the pin Red is plugged into, 10 is the pin Green is plugged into, 11 is the pin Blue is plugged into
rgbled led_two(6, 5, 3);   // 6 is the pin Red is plugged into, 5 is the pin Green is plugged into, 3 is the pin Blue is plugged into
rgbled *leds_combined = new rgbled[2]{ led_one, led_two }; // build array of our leds
multi_rgbled ALLRGBLEDS(2, leds_combined); // create multi led object - let the object know we have 2 leds


void setup() {
	// power up protection
	delay(200);
	ALLRGBLEDS.red();
	delay(1000);
	ALLRGBLEDS.ledsOff();
	delay(1000);
}

// the loop function runs over and over again until power down or reset
void loop() {
	ALLRGBLEDS.showRgbColorSpectrum(100);
	delay(100);
	ALLRGBLEDS.mainColors(100);
}

