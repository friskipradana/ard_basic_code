
#define LEDRPWM 3
#define BUZZ 1
int i = 0;

#include "TinyWireM.h"
#include <Tiny4kOLED.h>
#include <TinyRTClib.h>

RTC_DS1307 rtc;


uint8_t width = 128;
uint8_t height = 32;


void setup() {
  // put your setup code here, to run once:
  oled.begin(width, height, sizeof(tiny4koled_init_128x32br), tiny4koled_init_128x32br);
  oled.setFont(FONT8X16);
  oled.clear();
  oled.on();



  rtc.begin();

  if (! rtc.isrunning()) {
    //    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(__DATE__, __TIME__));
  }

  pinMode(BUZZ, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  DateTime now = rtc.now();
  oled.setCursor(0, 0);
  oled.print(now.year(), DEC);
  oled.print('/');
  oled.print(now.month(), DEC);
  oled.print('/');
  oled.print(now.day(), DEC);
  oled.print(' ');
  oled.setCursor(0, 2);
  oled.print(now.hour(), DEC);
  oled.print(':');
  oled.print(now.minute(), DEC);
  oled.print(':');
  oled.print(now.second(), DEC);
  oled.print(" ");

  delay(1000);



  for (i = 0; i < 255; i++) {
    analogWrite(LEDRPWM, 255);
    analogWrite(BUZZ, 3);
    delay(5);

  }
  for (i = 255; i > 0; i--) {
    analogWrite(LEDRPWM, 0);
    analogWrite(BUZZ, 0);
    delay(5);

  }


}
