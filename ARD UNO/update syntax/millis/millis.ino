unsigned long interval = 1000;
unsigned long start = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long now = millis();
  if (now - start >= interval) {
    start = now;
    Serial.println(now);
    Serial.println(start);
    Serial.println("print");

  }
}
