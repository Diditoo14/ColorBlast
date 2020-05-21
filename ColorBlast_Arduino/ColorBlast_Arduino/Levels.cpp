#include "Levels.h"
Levels::Levels(int arr[], int size, int speed)
{
	correctCombination = arr;
	userCombination = new int[size];
	this->size = size;
	this->speed = speed;
}


void Levels::StartBlinking()
{
    for (int i = 0; i < this->size; i++)
    {
		//red

		if (correctCombination[i] == 1) {
			digitalWrite(6, HIGH);
			delay(this->speed);
			digitalWrite(6, LOW);
			delay(this->speed);
		}
		//Yellow
		else if (correctCombination[i] == 2) {
			digitalWrite(8, HIGH);
			delay(this->speed);
			digitalWrite(8, LOW);
			delay(this->speed);


		}
		//Green
		else if (correctCombination[i] == 3) {
			digitalWrite(13, HIGH);
			delay(this->speed);
			digitalWrite(13, LOW);
			delay(this->speed);

		}
    }
}

//stores the input of the user and returns when it shoud stop reading
bool Levels::GetInput(int valueInput)
{
	//stores the value of the pressed button in the array with user combinations
	switch (valueInput)
	{
		case 1:
			digitalWrite(6, HIGH);
			delay(1000);
			digitalWrite(6, LOW);
			userCombination[index++] = 1;
			break;
		case 2:
			digitalWrite(8, HIGH);
			delay(1000);
			digitalWrite(8, LOW);
			userCombination[index++] = 2;
			break; 
		case 3:
			digitalWrite(13, HIGH);
			delay(1000);
			digitalWrite(13, LOW);
			userCombination[index++] = 3;
			break;
	}
	//size 5
	//array limit 4

	//current item 3 - index 2
	//index at start will be 2, -> 3

	//If the item in both arrays isnt in the same position
	for (int i = 0; i < index; i++)
	{
		if (correctCombination[i] != userCombination[i])
		{
			//Display wrong combination
			digitalWrite(5, HIGH);
			delay(2000);
			digitalWrite(5, LOW);
			return false;
		}
	}

	//check if we are at the last item of the array
	if (index == size) 
	{
		//Display correct combination
		digitalWrite(12, HIGH);
		delay(2000);
		digitalWrite(12, LOW);
		return false;
	}

	return true;
}