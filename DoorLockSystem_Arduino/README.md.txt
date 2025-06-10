 Door Lock System Using Arduino

 Overview
This project simulates a basic electronic door lock using Arduino, keypad, servo motor, and LCD. The circuit was built and tested in Tinkercad.

 Components Used
- Arduino Uno
- 4x4 Keypad
- Servo Motor
- I2C LCD Display
- Jumper wires

Functionality
- Waits for 4-digit password.
- If correct, unlocks via servo motor.
- Displays messages on the LCD.

Circuit Diagram
![Circuit Image](Door Lock System.png)

 Code
See `door_lock_system1.ino`.

 How to Simulate
Open the `.ino` file in Tinkercad or Arduino IDE, connect components as shown in the image, and run the simulation.

Code explanation:

#include <Servo.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

Servo lockServo;
 =Creates an object called lockServo
LiquidCrystal_I2C lcd(0x27, 16, 2);
 =Indicates that a 16x2 LCD is used, where 0x27 is the I2C address of the LCD used.

// Keypad setup
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
 =Creates a 2D array and instructs which character is returned when it is being pressed
byte rowPins[ROWS] = {9, 8, 7, 6};    
byte colPins[COLS] = {5, 4, 3, 2};
 =Mentions all the necessary connections made between the keypad and the arduino
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
 =creates an object called keypad

if (key) {
    if (key == '#') {
      if (input == password) {
  lcd.clear();
  lcd.print("Access Granted");

  digitalWrite(10, HIGH);  // Buzzer ON
  delay(1000);              // Beep for 200ms
  digitalWrite(10, LOW);   // Buzzer OFF

  lockServo.write(90);     // Unlock
  delay(3000);             // Stay unlocked
  lockServo.write(0);      // Lock again

  lcd.clear();
  lcd.print("Enter Password:");
}

# key indicates that you're done entering the password. If the password is right, then buzzer turns on where digitalWrite(10, HIGH) indicates buzzer is connected to pin 10 and HIGH indicates its making sound. delay(1000) indicates its going to buzz for 1 second ( 1000 milliseconds ) before it turns off again.

else {
        lcd.clear();
        lcd.print("Access Denied");
        delay(2000);
        lcd.clear();
        lcd.print("Enter Password:");
      }
      input = "";
    } else if (key == '*') {
      input = "";
      lcd.clear();
      lcd.print("Enter Password:");
    } else {
      input += key;
      lcd.setCursor(0, 1);
      lcd.print(input);
    }
  }
}

else, if the input is wrong then the lcd prints access denied. If a character is being typed in then it gets added on to the input and the gets printed below 'Enter Password", indicated by the code lcd.setCursor(0, 1), where 0 represents column and 1 represents rows. 