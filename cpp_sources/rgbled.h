// rgbled.h

#ifndef _RGBLED_h
#define _RGBLED_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class rgbled
{
	public:
		rgbled(int redPin, int greenPin, int bluePin);
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
		void ledOff();

	private:
		int _redPin;
		int _greenPin;
		int _bluePin;
};

#endif

