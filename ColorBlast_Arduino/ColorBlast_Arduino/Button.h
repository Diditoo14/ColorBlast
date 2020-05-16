// Button.h

#ifndef _BUTTON_h
#define _BUTTON_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
class Button
{
private:
	//Fields
	const unsigned long debounceDelay = 50;
	unsigned long lastDebounceTime;
	int buttonState;
	int lastButtonState;
	int buttonPin;
public:
	//constructor
	Button(int butPin);
	//method for debouncing a button
	int debounce();

};

#endif

