#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define BTN_UP 4
#define BTN_DOWN 5
#define TOUCH 10

boolean stateBtnUP = false;
boolean stateBtnDOWN = false;
boolean stateBtnOK = false;

boolean laststateBtnUP = false;
boolean laststateBtnDOWN = false;
boolean laststateBtnOK = false;

boolean UP = false;
boolean DOWN = false;
boolean OK = false;

int page = 1;
int item = 1;

void setup() {
  Serial.begin(9600);

  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);
  pinMode(TOUCH, INPUT_PULLUP);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  testdrawstyles();
}

void testdrawstyles(void) {
  display.clearDisplay();
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(30, 15);            // Start at top-left corner
  display.println(F("Menu Ver 2"));
  display.display();
  delay(2000);
}


void loop() {
  show();
  stateBtnUP = digitalRead(BTN_UP);
  stateBtnDOWN = digitalRead(BTN_DOWN);
  stateBtnOK = digitalRead(TOUCH);

  UpPressed();
  DownPressed();
  OKPressed();

  if (UP && page == 1) {
    UP = false;
    item--;
    if (item < 1) {
      item = 4;
    }
    Serial.print(item);
    delay(300);
  }
  if (DOWN && page == 1) {
    DOWN = false;
    item++;
    if (item > 4) {
      item = 1;
    }
    Serial.print(item);
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
void show() {
  if (page == 1) {
    display.clearDisplay();
    display.setTextSize(1);             // Normal 1:1 pixel scale
    display.setTextColor(SSD1306_WHITE);        // Draw white text
    display.setCursor(30, 0);            // Start at top-left corner
    display.println(F("DAFTAR MENU"));
    delay(100);
  }
  if (item == 1 ) {
    display.setCursor(5, 14);            // Start at top-left corner
    display.println(F("> menu 1 "));
  } else {
    display.setCursor(5, 14);            // Start at top-left corner
    display.println(F("  menu 1 "));
  }
  if (item == 2 ) {
    display.setCursor(70, 14);            // Start at top-left corner
    display.println(F("> menu 2 "));
  } else {
    display.setCursor(70, 14);            // Start at top-left corner
    display.println(F("  menu 2 "));
  }
  if (item == 3 ) {
    display.setCursor(5, 24);            // Start at top-left corner
    display.println(F("> menu 3 "));
  } else {
    display.setCursor(5, 24);            // Start at top-left corner
    display.println(F("  menu 3 "));
  }
  if (item == 4 ) {
    display.setCursor(70, 24);            // Start at top-left corner
    display.println(F("> menu 4 "));
  } else {
    display.setCursor(70, 24);            // Start at top-left corner
    display.println(F("  menu 4 "));
  }
  display.display();
}
