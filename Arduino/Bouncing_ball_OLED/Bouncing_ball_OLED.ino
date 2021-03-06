/*
 * TME Education, 2020.
 * Made by tesfamichael Molla Ali, TME Education Ambassador in Ethiopia.
 * Bouncing ball using OLED display.
*/

// Declearing libraries
#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 
// Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int x = 10, y = 10;   // X and Y Coordinates
int vx = 3, vy = 1;   // X and Y velocities

void setup() {
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

}

void loop() {
  // put your main code here, to run repeatedly:
  display.clearDisplay();
  moves();  // Update coordinates
  display.fillCircle(x, y, 1, WHITE);    // Create the circle with new coordinates
  display.display();    // Update screen
  
}

void moves() {
  // move to the prefered position based on velocities
    x += vx;
    y += vy;

  
  // Handle jumping out of the screen 
    if( 0 > x || x >= SCREEN_WIDTH ) {
       vx = -vx;
       x = -x;
       if( 0 > x ) 
          x += SCREEN_WIDTH << 1;
    }

    if( 0 > y || y >= SCREEN_HEIGHT ) {
       vy = -vy;
       y = -y;
       if( 0 > y )
          y += SCREEN_HEIGHT << 1;
    }
 
}
