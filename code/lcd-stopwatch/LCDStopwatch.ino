/*
  LCD Stopwatch / Timer Project
  - No RTC needed, uses Arduino's internal millis() timer
  - Button 1 (pin 8)  -> Start / Pause
  - Button 2 (pin 9)  -> Reset
  - Shows MM:SS:CS (minutes : seconds : centiseconds) on 16x2 LCD
  Wiring:
  LCD RS -> Arduino pin 7
  LCD EN -> Arduino pin 6
  LCD D4 -> Arduino pin 5
  LCD D5 -> Arduino pin 4
  LCD D6 -> Arduino pin 3
  LCD D7 -> Arduino pin 2
  LCD VSS, RW, K -> GND
  LCD VDD, A -> 5V
  LCD V0 -> Potentiometer wiper (or GND if no pot)
  Button 1 -> one leg to Arduino pin 8, other leg to GND
  Button 2 -> one leg to Arduino pin 9, other leg to GND
  (No resistors needed - we use Arduino's built-in pull-up resistors)
*/
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
const int startPauseBtn = 8;
const int resetBtn = 9;
unsigned long elapsedTime = 0;   // total time counted so far (ms)
unsigned long startTime = 0;     // when the current "run" started
bool running = false;
// for button debouncing
bool lastStartState = HIGH;
bool lastResetState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 200;
void setup() {
  lcd.begin(16, 2);
  pinMode(startPauseBtn, INPUT_PULLUP);
  pinMode(resetBtn, INPUT_PULLUP);
  lcd.setCursor(0, 0);
  lcd.print("LCD Stopwatch");
  delay(1500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("00:00:00");
  lcd.setCursor(0, 1);
  lcd.print("Press Start");
}
void loop() {
  bool startState = digitalRead(startPauseBtn);
  bool resetState = digitalRead(resetBtn);
  unsigned long now = millis();
  // Start / Pause button
  if (startState == LOW && lastStartState == HIGH && (now - lastDebounceTime > debounceDelay)) {
    lastDebounceTime = now;
    if (!running) {
      // starting: remember when we started this run
      startTime = now - elapsedTime;
      running = true;
    } else {
      // pausing: save how much time has passed
      elapsedTime = now - startTime;
      running = false;
    }
  }
  lastStartState = startState;
  // Reset button
  if (resetState == LOW && lastResetState == HIGH && (now - lastDebounceTime > debounceDelay)) {
    lastDebounceTime = now;
    running = false;
    elapsedTime = 0;
  }
  lastResetState = resetState;
  // update elapsed time live while running
  unsigned long displayTime = running ? (now - startTime) : elapsedTime;
  int minutes = (displayTime / 60000) % 60;
  int seconds = (displayTime / 1000) % 60;
  int centis  = (displayTime / 10) % 100;
  lcd.setCursor(0, 0);
  if (minutes < 10) lcd.print("0");
  lcd.print(minutes);
  lcd.print(":");
  if (seconds < 10) lcd.print("0");
  lcd.print(seconds);
  lcd.print(":");
  if (centis < 10) lcd.print("0");
  lcd.print(centis);
  lcd.print("  ");
  lcd.setCursor(0, 1);
  lcd.print(running ? "Running...  " : "Paused/Ready");
}
