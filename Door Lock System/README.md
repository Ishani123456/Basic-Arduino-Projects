# Arduino Door Lock System (Password: 1234)

## Project Overview

This project is a simple and effective digital door lock system using an Arduino Uno R3. It features a 4x4 keypad for password input, a 16x2 LCD display for user interaction, a micro servo motor for locking/unlocking, and a piezo buzzer for audio feedback.

When the correct 4-digit code (`1234`) is entered:
- The LCD displays "Access Granted"
- The servo rotates to unlock the door
- The buzzer plays a success tone

If the password is incorrect:
- The LCD displays "Access Denied"
- The buzzer emits an error beep

---

## Components Used

| Component       | Quantity |
|----------------|----------|
| Arduino Uno R3 | 1        |
| 4x4 Keypad     | 1        |
| 16x2 LCD       | 1        |
| Micro Servo    | 1        |
| Piezo Buzzer   | 1        |
| Jumper Wires   | As needed |

---

## How It Works

1. LCD prompts: `"Enter Password:"`
2. User enters a 4-digit code via keypad.
3. If correct:
   - LCD shows `"Access Granted"`
   - Servo unlocks the door
   - Buzzer plays success tone
4. If incorrect:
   - LCD shows `"Access Denied"`
   - Buzzer plays error tone
5. System resets and waits for another input.

---

## Circuit Connections

### LCD (16x2) to Arduino (4-bit Mode)

| LCD Pin | Arduino Pin |
|---------|-------------|
| SCL     | A5          |
| SDA     | A4          |
| VCC     | 5V          |
| GND     | GND         |

### Keypad

- Connect keypad's 8 pins to Arduino digital pins. Here, it is connected from 2 to 9
- Define the pin mapping in your code

### Servo Motor

- Signal pin to Pin 11
- VCC to 5V
- GND to GND

### Piezo Buzzer

- Positive pin to Pin 10
- GND to GND

---

## Files Included

- `Door_Lock_System.ino` – Arduino source code
- `README.md` – Project documentation
- Door Lock System Tinkercad.png

---

## How to Use:
click on this link to simulate: https://www.tinkercad.com/things/1LJYQKbnl07-door-lock-system

---

## Default Password

```cpp
char correctPassword[5] = "1234";


