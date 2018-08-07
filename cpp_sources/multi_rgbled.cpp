/*
Source code for 'multi_rgbled.h'
This class allows you to control an RGB LED on an Arduino Uno

Author: Matt Oestreich
*/


#include "arduino.h"
#include "rgbled.h"
#include "multi_rgbled.h"


multi_rgbled::multi_rgbled(int connectedRgbLeds, rgbled *leds)
{
	this->CONNECTED_RGBLEDS = connectedRgbLeds;
	for (int i = 0; i < this->CONNECTED_RGBLEDS; i++) {
		this->allRgbLeds[i]._redPin = leds[i]._redPin;
		this->allRgbLeds[i]._greenPin = leds[i]._greenPin;
		this->allRgbLeds[i]._bluePin = leds[i]._bluePin;
	}
};

void multi_rgbled::mainColors(int changeDelay)
{
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


void multi_rgbled::showRgb(int color)
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
	
	for (int i = 0; i < this->CONNECTED_RGBLEDS; i++) {
		analogWrite(this->allRgbLeds[i]._redPin, redIntensity);
		analogWrite(this->allRgbLeds[i]._greenPin, greenIntensity);
		analogWrite(this->allRgbLeds[i]._bluePin, blueIntensity);
		delay(200);
	}

}

void multi_rgbled::showRgbColorSpectrum(int fadeDelay)
{
	for (int x = 0; x < 768; x++)
	{
		showRgb(x);
		delay(fadeDelay);
	}
}

void multi_rgbled::red()
{
	for (int i = 0; i < this->CONNECTED_RGBLEDS; i++) {
		digitalWrite(this->allRgbLeds[i]._redPin, HIGH);
		digitalWrite(this->allRgbLeds[i]._greenPin, LOW);
		digitalWrite(this->allRgbLeds[i]._bluePin, LOW);
	}
}

void multi_rgbled::green()
{
	for (int i = 0; i < this->CONNECTED_RGBLEDS; i++) {
		digitalWrite(this->allRgbLeds[i]._redPin, LOW);
		digitalWrite(this->allRgbLeds[i]._greenPin, HIGH);
		digitalWrite(this->allRgbLeds[i]._bluePin, LOW);
	}
}

void multi_rgbled::blue()
{
	for (int i = 0; i < this->CONNECTED_RGBLEDS; i++) {
		digitalWrite(this->allRgbLeds[i]._redPin, LOW);
		digitalWrite(this->allRgbLeds[i]._greenPin, LOW);
		digitalWrite(this->allRgbLeds[i]._bluePin, HIGH);
	}
}

void multi_rgbled::yellow()
{
	for (int i = 0; i < this->CONNECTED_RGBLEDS; i++) {
		digitalWrite(this->allRgbLeds[i]._redPin, HIGH);
		digitalWrite(this->allRgbLeds[i]._greenPin, HIGH);
		digitalWrite(this->allRgbLeds[i]._bluePin, LOW);
	}
}

void multi_rgbled::cyan()
{
	for (int i = 0; i < this->CONNECTED_RGBLEDS; i++) {
		digitalWrite(this->allRgbLeds[i]._redPin, LOW);
		digitalWrite(this->allRgbLeds[i]._greenPin, HIGH);
		digitalWrite(this->allRgbLeds[i]._bluePin, HIGH);
	}
}

void multi_rgbled::purple()
{
	for (int i = 0; i < this->CONNECTED_RGBLEDS; i++) {
		digitalWrite(this->allRgbLeds[i]._redPin, HIGH);
		digitalWrite(this->allRgbLeds[i]._greenPin, LOW);
		digitalWrite(this->allRgbLeds[i]._bluePin, HIGH);
	}
}

void multi_rgbled::white()
{
	for (int i = 0; i < this->CONNECTED_RGBLEDS; i++) {
		digitalWrite(this->allRgbLeds[i]._redPin, HIGH);
		digitalWrite(this->allRgbLeds[i]._greenPin, HIGH);
		digitalWrite(this->allRgbLeds[i]._bluePin, HIGH);
	}
}

void multi_rgbled::ledsOff()
{
	for (int i = 0; i < this->CONNECTED_RGBLEDS; i++) {
		digitalWrite(this->allRgbLeds[i]._redPin, LOW);
		digitalWrite(this->allRgbLeds[i]._greenPin, LOW);
		digitalWrite(this->allRgbLeds[i]._bluePin, LOW);
	}
}
