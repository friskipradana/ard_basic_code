void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //single exsecute
  for (int i = 0; i <= 4; i++) {
    Serial.println("data5x");
    delay(500);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //loop exsecute
  for (int i = 0; i <= 4; i++) {
    Serial.println(i);
    delay(500);
  }
  int i = 0;
  while (i <= 5) {
    Serial.print("while ");
    Serial.println(i);
    delay(500);
    i++;
  }

}
