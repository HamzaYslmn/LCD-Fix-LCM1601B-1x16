#include <LiquidCrystal_I2C.h>

// Initialize the LCD with 0x27 address
LiquidCrystal_I2C lcd(0x27, 16, 2);

void printToLCD(const char* text) {
  lcd.clear();  // Clear the display
  for (int i = 0; i < 16 && text[i] != '\0'; ++i) {
    lcd.setCursor(i % 8, i < 8 ? 0 : 1);
    lcd.print(text[i]);
  }
}

void setup() {
  lcd.init();
  lcd.backlight();
  printToLCD("Hello World!");  // Print the text using the function
}

void loop() {
  printToLCD("Hello World!");
  delay(30000);
}
