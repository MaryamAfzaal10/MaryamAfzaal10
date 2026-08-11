int joyX = A0;
int greenLED = 5, blueLED = 6, yellowLED = 7;
int currentLED = 0;

void setup(){
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  updateLEDs();
}

void loop(){
  int xValue = analogRead(joyX);

  if (xValue < 300) {              // forward (Green->Blue->Yellow)
    currentLED++;
    if (currentLED > 2) currentLED = 2;
    updateLEDs();
    delay(300);
  }
  else if (xValue > 700) {         // backward (Yellow->Blue->Green)
    currentLED--;
    if (currentLED < 0) currentLED = 0;
    updateLEDs();
    delay(300);
  }
}

void updateLEDs(){
  digitalWrite(greenLED, currentLED == 0 ? HIGH : LOW);
  digitalWrite(blueLED, currentLED == 1 ? HIGH : LOW);
  digitalWrite(yellowLED, currentLED == 2 ? HIGH : LOW);
}
