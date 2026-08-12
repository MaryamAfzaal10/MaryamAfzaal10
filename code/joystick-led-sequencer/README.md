# Joystick-Controlled RGB LED Sequencer

A joystick-based light sequencer. Pushing the joystick left or right steps forward or backward through three LEDs (Green, Blue, Yellow), lighting exactly one at a time.

**📹 Demo video:** see this folder
**📄 Code:** [JoystickControl.ino](./JoystickControl.ino)

<br/>

## 🔩 Hardware Used

| Component | Quantity | Purpose |
|---|---|---|
| Arduino Uno | 1 | Main microcontroller |
| 2-axis Analog Joystick Module | 1 | Direction input (only the X-axis is used) |
| Green LED | 1 | Sequencer output, Step 1 |
| Blue LED | 1 | Sequencer output, Step 2 |
| Yellow LED | 1 | Sequencer output, Step 3 |
| 220Ω Resistor | 3 | Current-limiting, one per LED |
| Breadboard | 1 | Prototyping |
| Jumper Wires | as needed | Connections |

## 💻 Software Used

- **Arduino IDE** to write and upload the code
- Written in **C++ (Arduino framework)**, using `analogRead()` and `digitalWrite()`, no external libraries required

## 🔌 Pin Connections

| From | To (Arduino Pin) |
|---|---|
| Joystick GND | GND |
| Joystick +5V | 5V |
| Joystick VRx (X-axis output) | A0 |
| Joystick VRy, SW | Not used, left unconnected |
| Green LED anode, through a 220Ω resistor | Digital Pin 5 |
| Blue LED anode, through a 220Ω resistor | Digital Pin 6 |
| Yellow LED anode, through a 220Ω resistor | Digital Pin 7 |
| All three LED cathodes | GND |

## ⚙️ How It Works

The joystick's X-axis output is read on analog pin **A0**, which returns a value between 0 and 1023 (around 512 when the stick is at rest/centered).

- Pushing the stick **left** (reading below 300) moves the sequence **forward**, lighting the next LED in order: Green then Blue then Yellow.
- Pushing the stick **right** (reading above 700) moves the sequence **backward**: Yellow then Blue then Green.
- A `currentLED` variable, which can be 0, 1, or 2, tracks which LED should currently be lit. The `updateLEDs()` function turns on only that one LED and keeps the other two off.
- The index is clamped between 0 and 2 so it never goes out of range, and a short delay after each move prevents the joystick from triggering multiple steps from a single push.

<br/>

---
<p align="center"><a href="../../PROJECTS.md">← Back to Projects</a></p>
