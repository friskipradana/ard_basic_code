#define outputA 12     //CLK pada pin D6
#define outputB 11     //DT pada pin D7
#define button 10      //SW pada pin D8

int counter = 0;      //Variabel penghitung nilai
int aState;           //Variabel kondisi
int aLastState;       //Variabel kondisi terakhir

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

void setup() {
  Serial.begin(9600);
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  // Clear the buffer
  display.clearDisplay();

  display.setTextColor(SSD1306_WHITE);
  display.setCursor(30, 10);
  display.print("Rotary Encoder");
  display.display();
  delay(1000); // Pause for 2 seconds



  pinMode (outputA, INPUT_PULLUP); //Sertting sebagai input pullup
  pinMode (outputB, INPUT_PULLUP);
  pinMode (button, INPUT_PULLUP);
  aLastState = digitalRead(outputA);  //Baca kondisi terakhir CLK
}

void loop() {
  aState = digitalRead(outputA);          //Baca kondisi CLK
  if (aState != aLastState) {             //Jika ada perubahan kondisi, maka
    if (digitalRead(outputB) != aState) { //Jika berputar ke kiri, maka
      counter ++;                         //Nilai bertambah
    } else {                              //Jika berputar ke kanan, maka
      counter --;                         //Nilai berkurang
    }
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.setTextSize(1);
    display.print("Position: ");
    display.setCursor(0, 10);
    display.setTextSize(2);
    display.println(counter);              //Tampilkan nilai
    display.display();
  }
  aLastState = aState;                    //Rekam kondisi

  if (digitalRead(button) == LOW) {       //Jika tombol ditekan, maka
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("Button pressed");     //Tampilkan text
    delay(200);                           //Jeda pembacaan 200ms
    display.display();

  }

}
