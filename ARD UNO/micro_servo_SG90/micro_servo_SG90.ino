#include <Servo.h>
#define Servo_Pin 6
Servo Myservo;


void setup(){
  Myservo.attach(Servo_Pin);
}

void loop(){
  Myservo.write(0);
  delay(1000);
  Myservo.write(360);
  delay(1000);
}
