#include <Servo.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

Servo lockServo;
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Keypad setup
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};    
byte colPins[COLS] = {5, 4, 3, 2};    
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Password
String password = "1234";
String input = "";

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");

  lockServo.attach(11);
  delay(300); // let servo initialize
  lockServo.write(0); // locked position
  pinMode(10, OUTPUT);
  digitalWrite(10, LOW); // Ensure buzzer is off at start

}

void loop() {
  char key = keypad.getKey();
  
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


















