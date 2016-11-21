#include <LiquidCrystal.h>
#include <Button.h>
#include <Timer.h>

//objects
Timer t;
Timer p;
Timer s;
LiquidCrystal lcd(7, A7, 5, A6, 3, 2);
Button pauseButton(18);
Button scenarioButton1(A2);
Button scenarioButton2(A1);

//pins
int p1LEDPin = 15;
int p2LEDPin = 14;
int pauseLEDPin = 16;
int pausePin = 18;
int scenarioPin1 = 19;
int scenarioPin2 = 20;
int playerPin = 21;
int speakerPin = 9;

//variables
bool player = false;
bool pause = true;
long reset = 0;
long toneTime = 0;
int scenario1 = 0;
int scenario2 = 0;
int mins, secs;
int p1Time[2], p2Time[2], timeTot;
String time1, time2;
String player1, player2;
char readChar;
bool reading, rp1, rp2, rt, lcdup;
//int fade = 0;
//int fadeSwitch = 2;

void setup() {
  Serial.begin(9600);

  pinSetup();
  buttonSetup();
  timerSetup();
  lcdSetup();
  lcdStart();
}

void loop() {
  serialRead();
  pauseSwitch();
  playerSwitch();
  scenario();

  if (!pause) {
    t.update();
    playerLED();
    lcdTimer();
    lcdScenario();
  }
  
  if (pause) {
    pauseLED();
    lcdScenario();
  }
}
