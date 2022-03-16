#include<EEPROM.h>
byte value;
void setup() {
  Serial.begin(9600);
  EEPROM.write(0, 200);

}

void loop() {
  value = EEPROM.read(0);
  Serial.println(value);
  delay(1000);
}
