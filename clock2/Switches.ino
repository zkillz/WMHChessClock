void pauseSwitch() {
  if (pauseButton.pressed()) {
    reset = millis();
    pause = !pause;
  }

  if (pauseButton.released() && reset + 3000 <= millis()) {
    resetGame();
  }
}

void playerSwitch() {
  if (digitalRead(playerPin) == LOW) {
    player = true;
  }
  if (digitalRead(playerPin) == HIGH) {
    player = false;
  }
}


void scenario() {
  if (scenarioButton1.pressed()) {
    scenario1++;
    if (scenario1 > 5) {
      scenario1 = 0;
    }
  }
  if (scenarioButton2.pressed()) {
    scenario2++;
    if (scenario2 > 5) {
      scenario2 = 0;
    }
  }
}

