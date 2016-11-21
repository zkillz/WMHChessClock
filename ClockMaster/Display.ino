
//void ledFade() {
//  analogWrite(pauseLEDPin, 255 - fade);
//
//  fade = fade + fadeSwitch;
//
//  if (fade >= 255) {
//    fade = 255;
//    fadeSwitch = -5;
//  }
//  if (fade <= 0) {
//    fade = 0;
//    fadeSwitch = 5;
//  }
//}

void playerLED() {
  if (player) {
    digitalWrite(pauseLEDPin, LOW);
    digitalWrite(p1LEDPin, HIGH);
    digitalWrite(p2LEDPin, LOW);
  }
  else {
    digitalWrite(pauseLEDPin, LOW);
    digitalWrite(p2LEDPin, HIGH);
    digitalWrite(p1LEDPin, LOW);
  }
}

void pauseLED() {
  digitalWrite(pauseLEDPin, HIGH);
  digitalWrite(p1LEDPin, LOW);
  digitalWrite(p2LEDPin, LOW);
}

void lcdTimer() {

  if (player) {
    lcd.setCursor(0, 1);
    time1 = p1Time[0];
    time2 = p1Time[1];
  }
  if (!player) {
    lcd.setCursor(11, 1);
    time1 = p2Time[0];
    time2 = p2Time[1];
  }

  lcd.print(timePad(time1) + ":" + timePad(time2));
}

void lcdNames() {
  lcd.setCursor(0, 0);
  lcd.print("                ");
  
  lcd.setCursor(0, 0);
  lcd.print(namePad(player1,player2));
}

void lcdScenario() {
  lcd.setCursor(6, 1);
  lcd.print(scenario1);
  lcd.setCursor(9, 1);
  lcd.print(scenario2);
}

String timePad(String text) {
  if (text.length() == 1) {
    return "0" + text;
  }
  else {
    return text;
  }
}

String namePad(String name1, String name2){
  int len = 16 - name1.length() - name2.length();
  int i;
  String pad = "";
  for (i = 0; i < len; i++){
    pad = pad + " ";
  }
  return name1 + pad + name2;
}

