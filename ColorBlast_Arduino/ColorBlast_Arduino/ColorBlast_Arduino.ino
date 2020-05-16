/*
 Name:		ColorBlast_Arduino.ino
 Created:	5/16/2020 6:38:59 PM
 Author:	Didi
*/

// the setup function runs once when you press reset or power the board
#include "Levels.h"
#include "Button.h"

const int redLedPin = 6;
const int yellowLedPin = 8;
const int greenLedPin = 13;

const int btnPinTop = 2;
const int btnPinMiddle = 3;
const int btnPinButtom = 4;

//Keep default at -1;
int currentLevel = -1;
bool ledBlinking = false;

Button* btnTop = new Button(2);
Button* btnMiddle = new Button(3);
Button* btnButtom = new Button(4);

Levels* arrayOfLevels[3] = { 
    new Levels(new int[5]{ 1,2,3,2,1 }, 5, 500),
    new Levels(new int[7]{ 1,2,3,2,1,2,1 }, 7, 300),
    new Levels(new int[11]{ 1,2,3,2,1,3,1,1 }, 11, 300),
};






void setup() {
    pinMode(redLedPin, OUTPUT);
    pinMode(yellowLedPin, OUTPUT);
    pinMode(greenLedPin, OUTPUT);
    pinMode(btnPinTop, INPUT_PULLUP);
    pinMode(btnPinMiddle, INPUT_PULLUP);
    pinMode(btnPinButtom, INPUT_PULLUP);

    Serial.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop() {
   

    //StartOfGame();
    
}

String GetLevel()
{
    if (Serial.available())
    {
        if (currentLevel != -1)
        {
            return;
        }

        String myString = Serial.readString();
        myString.trim();
        if (myString.equals("one"))
        {
            currentLevel = 0;
            digitalWrite(redLedPin, HIGH);
        }
        else if (myString.equals("two"))
        {
            currentLevel = 1;
            digitalWrite(yellowLedPin, HIGH);

        }
        else if (myString.equals("three"))
        {
            currentLevel = 2;
            digitalWrite(greenLedPin, HIGH);

        }
    }
}

void StartOfGame()
{
    if (currentLevel != -1)
    {
        if (btnTop->debounce() && ledBlinking == false)
        {
            ledBlinking = true;
            arrayOfLevels[currentLevel]->StartBlinking();
            ledBlinking = false;
        }
    }
}

