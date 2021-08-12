#define LEDR A4 //Analog Pin ARD UNO
#define LEDG A5

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LEDR, HIGH);
  delay(2000);
  digitalWrite(LEDR, LOW);
  delay(2000);


  digitalWrite(LEDG, HIGH);
  delay(2000);
  digitalWrite(LEDG, LOW);
  delay(2000);
}
