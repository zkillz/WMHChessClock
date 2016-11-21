void serialWrite() {
  Serial.print(player1);
  Serial.print(" ");
  Serial.print(timePad(String(p1Time[0])) + ":" + timePad(String(p1Time[1])));
  Serial.print(" ");
  Serial.print(scenario1);
  Serial.print(" ");
  Serial.print(player2);
  Serial.print(" ");
  Serial.print(timePad(String(p2Time[0])) + ":" + timePad(String(p2Time[1])));
  Serial.print(" ");
  Serial.print(scenario2);
  Serial.println();
}

void serialRead() {
  if (Serial.available()) {
    while (Serial.available()) {
      
      if (rt) {
        timeTot = Serial.parseInt();
        rt = false;
        break;
      }
      
      readChar = Serial.read();
      if (!reading) {
        if (readChar == 35) {
          reading = rp1 = true;
          player1 = "";
          Serial.flush();
          break;
        }
        if (readChar == 36) {
          reading = rp2 = true;
          player2 = "";
          Serial.flush();
          break;
        }
        if (readChar == 37) {
          reading = rt = true;
          timeTot = "";
          Serial.flush();
          break;
        }
      }

      if (reading) {
        if (readChar == 35) {
          reading = rp1 = false;
          Serial.flush();
          lcdNames();
        }
        if (readChar == 36) {
          reading = rp2 = false;
          Serial.flush();
          lcdNames();
        }
        if (readChar == 37) {
          reading = rt = false;
          Serial.flush();
          resetGame();
        }
        if (rp1) {
          player1 = player1 + readChar;
        }
        if (rp2) {
          player2 = player2 + readChar;
        }
      }
    }
  }
}

