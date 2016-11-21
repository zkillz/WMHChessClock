void playTone() {
  toneTime = millis();
  while (millis() - toneTime < 300) {
    analogWrite(speakerPin, 200);
  }
  analogWrite(speakerPin, 0);
}

void playLongTone() {
  tonTime = millis();
  while (millis() - tonTime < 1000) {
    analogWrite(speakerPin, 200);
  }
  analogWrite(speakerPin, 0);
}

