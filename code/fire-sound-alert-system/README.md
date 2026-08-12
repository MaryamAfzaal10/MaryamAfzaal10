# Fire & Sound Alert System

A safety monitoring system that watches for flame and loud sound at the same time, displaying live status on an LCD and sounding a buzzer when something is detected.

**📹 Demo video:** [see the demo-video folder](./demo-video)
**📄 Code:** [FireSoundAlert.ino](./FireSoundAlert.ino)

<br/>

## 🔩 Hardware Used

| Component | Quantity | Purpose |
|---|---|---|
| Arduino Uno | 1 | Main microcontroller |
| Flame Sensor (HW-484) | 1 | Detects fire/flame |
| Sound Sensor Module | 1 | Detects loud noise |
| Active Buzzer | 1 | Audible alert |
| 16x2 LCD Display (HD44780) | 1 | Live status display |
| Breadboard | 1 | Prototyping |
| Jumper Wires | as needed | Connections |

## 💻 Software Used

- **Arduino IDE** to write and upload the code
- Written in **C++ (Arduino framework)**
- Uses the built-in **`LiquidCrystal.h`** library to drive the 16x2 LCD in 4-bit mode

## 🔌 Pin Connections

| From | To (Arduino Pin) |
|---|---|
| LCD RS | Pin 7 |
| LCD EN | Pin 6 |
| LCD D4 | Pin 5 |
| LCD D5 | Pin 4 |
| LCD D6 | Pin 3 |
| LCD D7 | Pin 2 |
| LCD VSS, RW, K | GND |
| LCD VDD, A | 5V |
| Buzzer | Pin 8 |
| Sound Sensor OUT | Pin 9 |
| Flame Sensor DO | Pin 10 |

## ⚙️ How It Works

The Arduino continuously reads two digital sensors on every loop:

- **Flame Sensor (Pin 10):** its output goes **LOW** when flame or fire is detected.
- **Sound Sensor (Pin 9):** its output goes **HIGH** when a loud sound is picked up.

Flame detection is checked first and treated as the highest priority. If flame is detected, the LCD immediately shows a **"FIRE ALERT"** message and the buzzer beeps rapidly, a fast, urgent pattern meant to grab attention right away.

If no flame is detected but the sound sensor crosses its threshold, the LCD instead shows a **"Sound Detected"** message along with a single, shorter beep.

When neither condition is triggered, the system displays a calm **"System OK / Monitoring..."** message, so it's always clear that the system is actively running and watching, not just idle.

<br/>

---
<p align="center"><a href="../../PROJECTS.md">← Back to Projects</a></p>
