#define LEDRPWM 1
int i =0;


void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  for (i = 0; i < 255; i++) {
    analogWrite(LEDRPWM, i);
    delay(5);
  }
  for (i = 255; i > 0; i--) {
    analogWrite(LEDRPWM, i);
    delay(5);
  }
  
}
