#include "TinyWireM.h"
#include "TinyOzOLED.h"
void setup() {
  OzOled.init();
//  OzOled.setInverseDisplay();  // Invert display
  OzOled.printString("Hi there!");
    OzOled.printString("Hi there!");
}
void loop() {
  // put your main code here, to run repeatedly:
}
