int latchPin = 0;
int clockPin = 4;
int dataPin = 3;
byte leds = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  leds = 0;
  UpdateShiftRegister();

  delay(500);
  for (int i = 0; i < 3; i++) {
    bitSet(leds, i);
    UpdateShiftRegister();
    delay(500);
  }

}

void UpdateShiftRegister() {

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, leds);
  digitalWrite(latchPin, HIGH);

}
