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

void Levels::StartChecking() 
{
	//const int btnPinTop = 2;
	//const int btnPinMiddle = 3;
	//const int btnPinButtom = 4;


}