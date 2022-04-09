#include <Keypad.h>
const byte rows = 4;
const byte cols = 4;
char keys[rows][cols] = {
  {'1', '2', '3', '4'},
  {'5', '6', '7', '8'},
  {'9', '0', '+', '-'},
  {'.', '*', '/', '='}

};
byte rowPins[rows] = {A3, A2, A1, A0};
byte colPins[cols] = {5, 6, 7, 8};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);



void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:

}

void loop() {

  char key = keypad.getKey();
  if (key != NO_KEY) {
    Serial.println(key);
  }
  // put your main code here, to run repeatedly:

}
