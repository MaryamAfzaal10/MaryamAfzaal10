# LCD Stopwatch / Timer

A digital stopwatch built entirely with Arduino's internal timing, no RTC module needed, displaying minutes, seconds, and centiseconds on a 16x2 LCD, with Start/Pause and Reset buttons.

**📹 Demo video:** see this folder
**📄 Code:** [LCDStopwatch.ino](./LCDStopwatch.ino)

<br/>

## 🔩 Hardware Used

| Component | Quantity | Purpose |
|---|---|---|
| Arduino Uno | 1 | Main microcontroller, timing runs on `millis()` |
| 16x2 LCD Display (HD44780) | 1 | Shows MM:SS:CS |
| Push Button | 2 | Start/Pause and Reset |
| 10kΩ Potentiometer | 1 | LCD contrast control |
| Breadboard | 1 | Prototyping |
| Jumper Wires | as needed | Connections |

## 💻 Software Used

- **Arduino IDE** to write and upload the code
- Written in **C++ (Arduino framework)**
- Uses the built-in **`LiquidCrystal.h`** library to drive the 16x2 LCD in 4-bit mode
- No RTC (real-time clock) module. Timing is handled purely in software using Arduino's `millis()` function

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
| LCD V0 | Potentiometer wiper, for contrast |
| Start/Pause Button | Pin 8, other leg to GND |
| Reset Button | Pin 9, other leg to GND |

> No external resistors are needed for the buttons. The Arduino's built-in `INPUT_PULLUP` resistors are used instead.

## ⚙️ How It Works

Instead of using a real-time clock module, the stopwatch runs entirely on Arduino's `millis()` function, which counts milliseconds since the board started.

- **Start/Pause button (Pin 8):** the first press starts the timer by recording a start reference point. A second press pauses it and saves how much time has elapsed so far.
- **Reset button (Pin 9):** stops the timer completely and resets the elapsed time back to zero.
- While running, the displayed time is calculated live as the difference between the current time and the start time. While paused, it simply holds the last saved elapsed value.
- The elapsed milliseconds are converted into minutes, seconds, and centiseconds, then printed on the LCD in `MM:SS:CS` format, updating continuously.
- Both buttons use software debouncing, a short delay after each press, so a single press is never accidentally read as multiple presses.

<br/>

---
<p align="center"><a href="../../PROJECTS.md">← Back to Projects</a></p>
