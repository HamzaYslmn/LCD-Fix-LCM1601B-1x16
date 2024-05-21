#include <LiquidCrystal_I2C.h>

// Initialize the LCD with 0x27 address
LiquidCrystal_I2C lcd(0x27, 16, 2);

char lcdBuffer[17] = "";  // Buffer to store current LCD content

void printToLCD(const char* text) {
  int i = 0;
  // Update only changed characters
  while (i < 16 && text[i] != '\0') {
    if (text[i] != lcdBuffer[i]) {
      lcd.setCursor(i % 8, i < 8 ? 0 : 1);
      lcd.print(text[i]);
      lcdBuffer[i] = text[i];
    }
    ++i;
  }
  while (i < 16) {
    if (lcdBuffer[i] != ' ') {
      lcd.setCursor(i % 8, i < 8 ? 0 : 1);
      lcd.print(' ');
      lcdBuffer[i] = ' ';
    }
    ++i;
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