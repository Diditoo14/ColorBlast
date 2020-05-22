/*
 Name:		ColorBlast_Arduino.ino
 Created:	5/16/2020 6:38:59 PM
 Author:	Didi
*/

// the setup function runs once when you press reset or power the board
#include "Levels.h"
#include "Button.h"

//declare LEDs
const int redLedPin = 6;
const int yellowLedPin = 8;
const int greenLedPin = 13;

//declare buttons
const int btnPinTop = 2;
const int btnPinMiddle = 3;
const int btnPinButtom = 4;

//stores current level (0,1,2)
//Keep default at -1;
int currentLevel = 3;
//indicates if the correct combination is showing at the moment
bool ledBlinking = false;

//indicates if the system is taking the user input
bool inputReading = false;

//debounce objects for the buttons
Button* btnTop = new Button(2);
Button* btnMiddle = new Button(3);
Button* btnBottom = new Button(4);

//declare the predefined levels
Levels* arrayOfLevels[4] = { 
    new Levels(new int[5]{ 1,2,3,2,1 }, 5, 500),
    new Levels(new int[7]{ 1,2,3,2,1,2,1 }, 7, 300),
    new Levels(new int[8]{ 1,2,3,2,1,3,1,1 }, 8, 300),
    new Levels(new int[11]{ 3,1,3,2,2,3,1,2,3,1,1 }, 11, 300),
};



void setup() {
    pinMode(redLedPin, OUTPUT);
    pinMode(yellowLedPin, OUTPUT);
    pinMode(greenLedPin, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(12, OUTPUT);

    pinMode(btnPinTop, INPUT_PULLUP);
    pinMode(btnPinMiddle, INPUT_PULLUP);
    pinMode(btnPinButtom, INPUT_PULLUP);

    Serial.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop() {
   
    //GetLevel();
    StartOfGame();
    ReadButtonInput();

}

//reads serial which level is selected from the user
void GetLevel()
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


//shows the blinking combination
void StartOfGame()
{
    if (currentLevel != -1)
    {
        //btnTop->debounce() &&  ?????
        if (ledBlinking == false && inputReading == false)
        {
            if (!btnTop->debounce()) return;
            ledBlinking = true;
            arrayOfLevels[currentLevel]->StartBlinking();
            ledBlinking = false;

            inputReading = true;
        }
    }
}

// 
void ReadButtonInput()
{
    if (inputReading)
    {
        //red LED
        if (btnTop->debounce())
        {
            arrayOfLevels[currentLevel]->GetInput(1);
        }
        //yellow LED
        if (btnMiddle->debounce())
        {
            arrayOfLevels[currentLevel]->GetInput(2);
        }
        //green LED
        if (btnBottom->debounce())
        {
            arrayOfLevels[currentLevel]->GetInput(3);
        }
    }
    
}