void setup() {
  // put your setup code here, to run once:
  pinMode(0, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(0, 3);
  delay(1000);
  analogWrite(0, 0);
  delay(1000);
}
