#include <LiquidCrystal_I2C.h>

// Initialize the LCD with 0x27 address
LiquidCrystal_I2C lcd(0x27, 16, 2);

char lcdBuffer[17] = "";  // Buffer to store current LCD content

void printToLCD(const char* text) {
  for (int i = 0; i < 16; ++i) {
    if (text[i] != lcdBuffer[i]) {
      lcd.setCursor(i % 8, i < 8 ? 0 : 1);
      lcd.print(text[i]);
      lcdBuffer[i] = text[i];
    }
    if (text[i] == '\0') {
      // Fill the rest of the buffer with spaces
      for (int j = i; j < 16; ++j) {
        if (lcdBuffer[j] != ' ') {
          lcd.setCursor(j % 8, j < 8 ? 0 : 1);
          lcd.print(' ');
          lcdBuffer[j] = ' ';
        }
      }
      break;
    }
  }
}

void setup() {
  lcd.init();
  lcd.backlight();
  printToLCD("Hello World!");  // Print the text using the function
}

void loop() {
  printToLCD("Hello World!");
  delay(1000);
  printToLCD("Hello Arduino!");
  delay(1000);
  printToLCD("Hello LCD!");
  delay(1000);
}