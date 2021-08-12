#define LED 11
byte ldr = A0;
int value;


void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(ldr);
  Serial.print("Nilai LDR: ");
  Serial.println(value);

  if (value < 800) {
    digitalWrite(LED, HIGH);
    delay(5000);
  } else {
    digitalWrite(LED, LOW);
    delay(200);
  }
}
