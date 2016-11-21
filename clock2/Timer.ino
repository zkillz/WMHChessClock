void timer() {
  if (player) {
    mins = p1Time[0];
    secs = p1Time[1];
  }

  if (!player) {
    mins = p2Time[0];
    secs = p2Time[1];
  }

  if (secs <= 0) {
    mins--;
    secs = 60;
  }

  secs--;

  if (mins == 1 && secs == 0) {
    playTone();
  }

  if (mins == 0 && secs < 5) {
    playTone();
  }

  if (mins == 0 && secs == 0) {
    pause = !pause;
  }

  if (player) {
    p1Time[0] = mins;
    p1Time[1] = secs;
  }

  if (!player) {
    p2Time[0] = mins;
    p2Time[1] = secs;
  }
}

