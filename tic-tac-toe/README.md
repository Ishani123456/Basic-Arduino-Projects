# Arduino LCD Tic-Tac-Toe Game

This project is a two-player Tic-Tac-Toe game built using Arduino UNO, a 4x4 Keypad, and a 16x2 LCD display. It simulates a turn-based game where players alternate placing X and O using the keypad. The game board is displayed on the LCD using a paging system.

## Features

* Two-player support (X and O)
* Input via 4x4 matrix keypad (keys 1-9)
* Game board displayed on a 16x2 LCD
* Paging system to view all 3 game rows (switch pages using `#` key)
* `*` key to reset the game at any time
* Automatically detects win and draw conditions

---

## Components Used

This project is built and simulated in Tinkercad. No physical hardware required.

* Arduino Uno R3
* 16x2 LCD Display
* 10k Potentiometer (for LCD contrast)
* 4x4 Keypad
* Breadboard and Jumper Wires

---

## Keypad Layout

```
1 | 2 | 3 | A
4 | 5 | 6 | B
7 | 8 | 9 | C
* | 0 | # | D
```

* Keys `1-9`: Place your X or O on the board
* `*`: Reset the game
* `#`: Switch between board pages (to view all rows)

---

##  How It Works

* The game board is stored in a 3x3 character array.
* The LCD can only show 2 rows, so we switch pages to view all 3 rows.
* After every move, the game checks for a win or draw.
* A message is displayed on the LCD if someone wins or the game ends in a draw.

---


## Learnings & Concepts

* LCD interfacing and character display
* Keypad input mapping
* Game logic (arrays, win/draw detection)
* Paging system for multi-row display

---

## How to Simulate in Tinkercad

* Click on the given link and click on 'Tinker this' to simulate: https://www.tinkercad.com/things/4dy4GinBS92-tic-tac-toe

---

## License

This project is open source and free to use under the [MIT License](LICENSE).

---
