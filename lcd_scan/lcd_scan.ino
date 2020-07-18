#include <LiquidCrystal_I2C.h>
// Construct an LCD object and pass it the 
// I2C address, width (in characters) and
// height (in characters). Depending on the
// Actual device, the IC2 address may change.
LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
 lcd.begin(16,2);     // The begin call takes the width and height. This
 lcd.init();          // Should match the number provided to the constructor.
 lcd.backlight();     // Turn on the backlight.
 lcd.setCursor(0, 0); // Move the cursor characters to the right and
                      // zero characters down (line 1).
 lcd.print("HELLO");  // Print HELLO to the screen, starting at 0,0.

  
 lcd.setCursor(0, 1);    // Move the cursor to the next line and print
 lcd.print("WORLD");     // WORLD.  
  }

void loop() {
}
