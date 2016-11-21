void pinSetup() {
  pinMode(p1LEDPin, OUTPUT);
  pinMode(p2LEDPin, OUTPUT);
  pinMode(pauseLEDPin, OUTPUT);

  pinMode(playerPin, INPUT);
  digitalWrite(playerPin, HIGH);
}

void buttonSetup() {
  pauseButton.begin();
  scenarioButton1.begin();
  scenarioButton2.begin();
}

void timerSetup() {
  //p.every(1000,playTone);
  t.every(1000, timer);
  s.every(1000, serialWrite);

  p1Time[0] = p2Time[0] = timeTot = 60;
  p1Time[1] = p2Time[1] = 0;
}

void lcdSetup() {
  lcd.begin(16, 2);
  lcd.clear();

  player1 = "LEFT";
  player2 = "RIGHT";
}

void lcdStart() {
  lcd.setCursor(0, 0);
  lcd.print(player1);
  lcd.setCursor(0, 1);
  time1 = p1Time[0];
  time2 = p1Time[1];
  lcd.print(timePad(time1) + ":" + timePad(time2));

  lcd.setCursor(11, 0);
  lcd.print(player2);
  lcd.setCursor(11, 1);
  time1 = p2Time[0];
  time2 = p2Time[1];
  lcd.print(timePad(time1) + ":" + timePad(time2));
}

void resetGame() {
  playTone();

  p1Time[0] = p2Time[0] = timeTot;
  p1Time[1] = p2Time[1] = 0;
  scenario1 = scenario2 = 0;

  pause = true;

  lcdStart();
}

