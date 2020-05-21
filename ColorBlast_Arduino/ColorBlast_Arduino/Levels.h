// Levels.h
#ifndef _LEVELS_h
#define _LEVELS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "Button.h"

class Levels
{
private: 
	//Fields:
	int *correctCombination;  //dynamic array for storing the correct combination of LEDs
	int index = 0;
	int speed;                //variable for showing the speed of the changing LEDs in the array
	Button btn1;
	Button btn2;
	Button btn3;

public:
	//Fields:
	int size = 0;            //variable for showing the size of the array
	int* userCombination;    //dynamic array for storing the user combination of push-buttons
	
							 
	//Methods:

	//Constructor:
	Levels(int arr[], int size, int speed);
	//Levels(int arr[], int size, int speed);

	
	void StartBlinking();    //function for making the LEDs start blinking
	bool GetInput(int inputValue);         //function for getting the value of the buttons

};
#endif

