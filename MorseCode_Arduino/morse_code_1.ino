#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

String morseCode(char c) {
  switch (c) {
    case 'A': return ".-";
    case 'B': return "-...";
    case 'C': return "-.-.";
    case 'D': return "-..";
    case 'E': return ".";
    case 'F': return "..-.";
    case 'G': return "--.";
    case 'H': return "....";
    case 'I': return "..";
    case 'J': return ".---";
    case 'K': return "-.-";
    case 'L': return ".-..";
    case 'M': return "--";
    case 'N': return "-.";
    case 'O': return "---";
    case 'P': return ".--.";
    case 'Q': return "--.-";
    case 'R': return ".-.";
    case 'S': return "...";
    case 'T': return "-";
    case 'U': return "..-";
    case 'V': return "...-";
    case 'W': return ".--";
    case 'X': return "-..-";
    case 'Y': return "-.--";
    case 'Z': return "--..";
    case ' ': return " ";  // Space between words
    default: return "";
  }
}

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Enter Text:");
}

void loop() {
  if (Serial.available() > 0) {
    String inputText = Serial.readString();  // ✅ Read all available text (no waiting for '\n')
    inputText.toUpperCase();                 // Convert input to uppercase

    lcd.clear();
    lcd.print("Morse:");      // Optional: Show title
    delay(1000);
    lcd.clear();

    String morse = "";

    for (int i = 0; i < inputText.length(); i++) {
      morse += morseCode(inputText.charAt(i)) + " ";
    }

    // Display Morse Code on LCD (line by line if long)
    lcd.print(morse.substring(0, 16));  // First line

    if (morse.length() > 16) {
      lcd.setCursor(0, 1);
      lcd.print(morse.substring(16, 32));  // Second line if needed
    }
  }
}
