void setup() {
  // put your setup code here, to run once:
  pinMode(A1,INPUT);
  pinMode(A4,OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
 
 int touch = digitalRead(A1);
 Serial.println(touch);
 if(touch == HIGH) {
  digitalWrite(A4,HIGH);
 }else {
  digitalWrite(A4,LOW);
 }
}
