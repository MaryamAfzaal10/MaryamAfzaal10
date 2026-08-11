/*
  Fire + Sound Alert System
  - Flame sensor (HW-484) -> Pin 10 (DO)
  - Sound sensor -> Pin 9 (OUT)
  - Buzzer -> Pin 8
  - LCD shows live status
*/
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
const int buzzerPin = 8;
const int soundPin = 9;
const int flamePin = 10;
unsigned long messageTime = 0;
const unsigned long messageDuration = 2000; // how long alert stays on screen
bool showingAlert = false;
void setup() {
  lcd.begin(16, 2);
  pinMode(buzzerPin, OUTPUT);
  pinMode(soundPin, INPUT);
  pinMode(flamePin, INPUT);
  lcd.setCursor(0, 0);
  lcd.print("Alert System");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");
  delay(1500);
  lcd.clear();
}
void loop() {
  bool flameDetected = (digitalRead(flamePin) == LOW);   // HW-484: LOW = flame detected
  bool soundDetected = (digitalRead(soundPin) == HIGH);  // sound module: HIGH = loud sound
  if (flameDetected) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("!! FIRE ALERT !!");
    lcd.setCursor(0, 1);
    lcd.print("Flame detected!");
    // fast continuous beeping for fire
    for (int i = 0; i < 3; i++) {
      digitalWrite(buzzerPin, HIGH);
      delay(100);
      digitalWrite(buzzerPin, LOW);
      delay(100);
    }
    return; // skip rest of loop, re-check immediately
  }
  if (soundDetected) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sound Detected!");
    lcd.setCursor(0, 1);
    lcd.print("Noise nearby");
    digitalWrite(buzzerPin, HIGH);
    delay(150);
    digitalWrite(buzzerPin, LOW);
    delay(1000); // keep message visible briefly
    return;
  }
  // Idle state - nothing detected
  lcd.setCursor(0, 0);
  lcd.print("System OK      ");
  lcd.setCursor(0, 1);
  lcd.print("Monitoring...  ");
  digitalWrite(buzzerPin, LOW);
  delay(200);
}
