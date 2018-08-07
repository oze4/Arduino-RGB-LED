/*
Header file for 'multi_rgbled.cpp'
This class allows you to control an RGB LED on an Arduino Uno

Author: Matt Oestreich
*/

#ifndef _MULTI_RGBLED_h
#define _MULTI_RGBLED_h

#if defined(ARDUINO) && ARDUINO >= 100

#include "arduino.h"

#else

#include "WProgram.h"

#endif

using namespace std;


class multi_rgbled
{



private:
	int CONNECTED_RGBLEDS = 0;
	rgbled *allRgbLeds;

public:
	multi_rgbled(int connectedRgbLeds, rgbled *leds);
	void mainColors(int changeDelay);
	void showRgb(int color);
	void showRgbColorSpectrum(int fadeDelay);
	void red();
	void green();
	void blue();
	void yellow();
	void cyan();
	void purple();
	void white();
	void ledsOff();

};

#endif

