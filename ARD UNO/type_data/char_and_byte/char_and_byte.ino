char myChar = 'A';
byte myByte = 0; // range 0-255



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(myByte);
  Serial.print(" ");
  Serial.println(myChar);
  myByte = myByte + 1;
  myChar = myChar + 1;
  delay(200);
}
