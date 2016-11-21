void playTone() {
  toneTime = millis();
  while (millis() - toneTime < 300) {
    analogWrite(speakerPin, 200);
  }
  analogWrite(speakerPin, 0);
}

