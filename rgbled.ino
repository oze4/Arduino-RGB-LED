/*
 Name:		rgbled.ino
 Author:	Matt
 
 Sketch to control RGB LED
*/

#include "arduino.h"
#include "rgbled.h"

// build first led bulb object
rgbled led1(9, 10, 11); // 9 is the pin Red is plugged into
			// 10 is the pin Green is plugged into
			// 11 is the pin Blue is plugged into

/* ~ if you had a second RGB LED
rgbled led2(5, 6, 7) // or whichever ports on the Arduino they're plugged into
		     // 5 is the pin Red is plugged into
		     // 6 is the pin Green is plugged into
		     // 7 is the pin Blue is plugged into
*/


// "run once" - each time the Arduino boots, this runs one time
void setup() {
	led1.green();
	/* if you had a second LED
	led2.green(); */
	delay(10);
}

// this is what runs over and over and over until the Arduino is powered off
void loop() {
	led1.showRgbColorSpectrum(10);
	/* if you had a second LED
	led2.showRgbColorSpectrum(10); */
}
