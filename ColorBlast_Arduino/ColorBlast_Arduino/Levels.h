// Levels.h
#ifndef _LEVELS_h
#define _LEVELS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
class Levels
{
private: 
	int *correctCombination;
	int index = 0;
	int speed;

public:
	int size = 0;
	int* userCombination;
	Levels(int arr[], int size, int speed);
	void StartChecking();
	void StartBlinking();

};
#endif

