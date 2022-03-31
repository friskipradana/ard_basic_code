#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library.
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define BTN_UP 4
#define BTN_DOWN 5


boolean stateBtnUP = false;
boolean stateBtnDOWN = false;
boolean stateBtnOK = false;

boolean laststateBtnUP = false;
boolean laststateBtnDOWN = false;
boolean laststateBtnOK = false;

boolean UP = false;
boolean DOWN = false;
boolean OK = false;

int menu = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  //  testdrawstyles();    // Draw 'stylized' characters
  testdrawstyles();

}

void testdrawstyles(void) {
  display.clearDisplay();
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(30, 15);            // Start at top-left corner
  display.println(F("Menu Ver 1"));
  display.display();
  delay(2000);
}



void loop() {
  updateMenu();
  stateBtnUP = digitalRead(BTN_UP);
  stateBtnDOWN = digitalRead(BTN_DOWN);
  //  stateBtnOK = digitalRead(TOUCH);

  UpPressed();
  DownPressed();
  OKPressed();

  if (UP) {
    UP = false;
    menu--;
    updateMenu();
    if (menu < 1) {
      menu = 4;
    }
    Serial.print(menu);
    delay(300);
  }
  if (DOWN) {
    DOWN = false;
    menu++;
    updateMenu();
    if (menu > 4) {
      menu = 1;
    }
    Serial.print(menu);
    delay(300);
  }


}
void UpPressed() {
  if (stateBtnUP != laststateBtnUP) {
    if (stateBtnUP == 0) {
      UP = true;
    }
    delay(50);
  }
  laststateBtnUP = stateBtnUP;
}
void DownPressed() {
  if (stateBtnDOWN != laststateBtnDOWN) {
    if (stateBtnDOWN == 0) {
      DOWN = true;
    }
    delay(50);
  }
  laststateBtnDOWN = stateBtnDOWN;
}
void OKPressed() {
  if (stateBtnOK != laststateBtnOK) {
    if (stateBtnOK == 0) {
      OK = true;
    }
    delay(50);
  }
  laststateBtnOK = stateBtnOK ;
}
void updateMenu() {

  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1:
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(30, 0);
      display.println(F("Daftar Menu"));
      display.setCursor(0, 14);
      display.println(F("> Menu Item 1"));
      display.println(F("  Menu Item 2"));
      display.display();
      break;
    case 2:
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(30, 0);
      display.println(F("Daftar Menu"));
      display.setCursor(0, 14);
      display.println(F("  Menu Item 1"));
      display.println(F("> Menu Item 2"));
      display.display();
      break;
    case 3:
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(30, 0);
      display.println(F("Daftar Menu"));
      display.setCursor(0, 14);
      display.println(F("> Menu Item 3"));
      display.println(F("  Menu Item 4"));
      display.display();
      break;
    case 4:
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(30, 0);
      display.println(F("Daftar Menu"));
      display.setCursor(0, 14);
      display.println(F("  Menu Item 3"));
      display.println(F("> Menu Item 4"));
      display.display();
      break;
    case 5:
      menu = 4;
      break;

    default:
      break;
  }

}
