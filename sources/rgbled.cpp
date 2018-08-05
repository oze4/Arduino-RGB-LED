/*
Source code for 'rgbled.h'
This class allows you to control an RGB LED on an Arduino Uno

Author: Matt Oestreich
*/

#include "arduino.h"
#include "rgbled.h"


rgbled::rgbled(int redPin, int greenPin, int bluePin)
{
	_redPin = redPin;
	_greenPin = greenPin;
	_bluePin = bluePin;
};

void rgbled::mainColors(int changeDelay)
{
	ledOff();
	delay(changeDelay);
	red();
	delay(changeDelay);
	green();
	delay(changeDelay);
	blue();
	delay(changeDelay);
	yellow();
	delay(changeDelay);
	cyan();
	delay(changeDelay);
	purple();
	delay(changeDelay);
	white();
	delay(changeDelay);
}

void rgbled::showRgb(int color)
{
	int redIntensity;
	int greenIntensity;
	int blueIntensity;

	if (color <= 255)          // zone 1
	{
		redIntensity = 255 - color;    // red goes from on to off
		greenIntensity = color;        // green goes from off to on
		blueIntensity = 0;             // blue is always off
	}
	else if (color <= 511)     // zone 2
	{
		redIntensity = 0;                     // red is always off
		greenIntensity = 255 - (color - 256); // green on to off
		blueIntensity = (color - 256);        // blue off to on
	}
	else // color >= 512       // zone 3
	{
		redIntensity = (color - 512);         // red off to on
		greenIntensity = 0;                   // green is always off
		blueIntensity = 255 - (color - 512);  // blue on to off
	}

	analogWrite(_redPin, redIntensity);
	analogWrite(_bluePin, blueIntensity);
	analogWrite(_greenPin, greenIntensity);
}

void rgbled::showRgbColorSpectrum(int fadeDelay)
{
	int x;
	for (x = 0; x < 768; x++)
	{
		showRgb(x);
		delay(fadeDelay);
	}
}

void rgbled::red()
{
	digitalWrite(_redPin, HIGH);
	digitalWrite(_greenPin, LOW);
	digitalWrite(_bluePin, LOW);
}

void rgbled::green()
{
	digitalWrite(_redPin, LOW);
	digitalWrite(_greenPin, HIGH);
	digitalWrite(_bluePin, LOW);
}

void rgbled::blue()
{
	digitalWrite(_redPin, LOW);
	digitalWrite(_greenPin, LOW);
	digitalWrite(_bluePin, HIGH);
}

void rgbled::yellow()
{
	digitalWrite(_redPin, HIGH);
	digitalWrite(_greenPin, HIGH);
	digitalWrite(_bluePin, LOW);
}

void rgbled::cyan()
{
	digitalWrite(_redPin, LOW);
	digitalWrite(_greenPin, HIGH);
	digitalWrite(_bluePin, HIGH);
}

void rgbled::purple()
{
	digitalWrite(_redPin, HIGH);
	digitalWrite(_greenPin, LOW);
	digitalWrite(_bluePin, HIGH);
}

void rgbled::white()
{
	digitalWrite(_redPin, HIGH);
	digitalWrite(_greenPin, HIGH);
	digitalWrite(_bluePin, HIGH);
}

void rgbled::ledOff()
{
	digitalWrite(_redPin, LOW);
	digitalWrite(_greenPin, LOW);
	digitalWrite(_bluePin, LOW);
}
