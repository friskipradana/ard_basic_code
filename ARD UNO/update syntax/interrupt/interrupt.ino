#include<TimerOne.h>

const int led = 13, buzz = 9, btn = 5;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(btn, INPUT);
    Timer1.initialize(10000);
    Timer1.attachInterrupt(ledBlink);
}

void loop() {
  tone(buzz, 1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzz);     // Stop sound...
  delay(1000);        // ...for 1sec
}
void ledBlink() {
  if (digitalRead(btn)) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }

}
