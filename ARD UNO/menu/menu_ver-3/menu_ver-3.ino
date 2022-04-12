#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <TimerOne.h>

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

#define outputA 12     //CLK pada pin D6
#define outputB 11     //DT pada pin D7
#define button 10      //SW pada pin D8

int aLastState;       //Variabel kondisi terakhir
int aState;
int counter = 0;
int page = 1;

void setup() {
  Serial.begin(9600);
  pinMode (outputA, INPUT_PULLUP); //Sertting sebagai input pullup
  pinMode (outputB, INPUT_PULLUP);
  pinMode (button, INPUT_PULLUP);


  Timer1.initialize(1000);
  Timer1.attachInterrupt(rotary); // blinkLED to run every 0.15 seconds


  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }

  testdrawstyles();
  aLastState = digitalRead(outputA);
  Serial.println(aLastState);
}

void rotary(void) {
  aState = digitalRead(outputA);
  if (aState != aLastState) {             //Jika ada perubahan kondisi, maka
    if (digitalRead(outputB) != aState) { //Jika berputar ke kiri, maka
      counter ++;                         //Nilai bertambah
    } else {                              //Jika berputar ke kanan, maka
      counter --;                         //Nilai berkurang
    }
    Serial.print("Position: ");
    Serial.println(counter);              //Tampilkan nilai
  }
  aLastState = aState;                    //Rekam kondisi

  if (digitalRead(button) == LOW) {       //Jika tombol ditekan, maka
    Serial.println("Button pressed");     //Tampilkan text
    delay(200);                           //Jeda pembacaan 200ms
  }
}


void testdrawstyles(void) {
  display.clearDisplay();
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(30, 15);            // Start at top-left corner
  display.println(F("Menu Ver 3"));
  display.display();
  delay(2000);
}

void loop() {
  view();
  limit();

}

void view() {
  display.clearDisplay();
  if (page == 1) {
    display.clearDisplay();
    display.setTextSize(1);             // Normal 1:1 pixel scale
    display.setTextColor(SSD1306_WHITE);        // Draw white text
    display.setCursor(30, 0);            // Start at top-left corner
    display.println(F("DAFTAR MENU"));
    delay(100);
  }
  if (counter >= 0 && counter <= 5 ) {
    display.setCursor(5, 14);            // Start at top-left corner
    display.println(F("> menu 1 "));
  } else {
    display.setCursor(5, 14);            // Start at top-left corner
    display.println(F("  menu 1 "));
  }
  if (counter > 5 && counter <= 10) {
    display.setCursor(70, 14);            // Start at top-left corner
    display.println(F("> menu 2 "));
  } else {
    display.setCursor(70, 14);            // Start at top-left corner
    display.println(F("  menu 2 "));
  }
  if (counter > 10 && counter <= 15 ) {
    display.setCursor(5, 24);            // Start at top-left corner
    display.println(F("> menu 3 "));
  } else {
    display.setCursor(5, 24);            // Start at top-left corner
    display.println(F("  menu 3 "));
  }
  if (counter > 15  && counter <= 20 ) {
    display.setCursor(70, 24);            // Start at top-left corner
    display.println(F("> menu 4 "));
  } else {
    display.setCursor(70, 24);            // Start at top-left corner
    display.println(F("  menu 4 "));
  }
  display.display();
}
void limit() {
  if (counter > 20)
  {
    counter = 20;
  }
  if (counter < 0)
  {
    counter = 0;
  }
}
