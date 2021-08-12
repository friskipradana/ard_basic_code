#define ledPinR A4
#define ledPinG A5


int buttonValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPinR, OUTPUT);
  pinMode(ledPinG, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonValue = analogRead(A0);
  Serial.println(buttonValue);
  if (buttonValue >= 953 && buttonValue <= 1000  ) {
    digitalWrite(ledPinR, HIGH);
  } else if (buttonValue >= 761 && buttonValue <= 950 ) {
    digitalWrite(ledPinG, HIGH);
  } else if (buttonValue >= 451 && buttonValue <= 700 ) {
    digitalWrite(ledPinR, HIGH);
    digitalWrite(ledPinG, HIGH);
  } else {
    digitalWrite(ledPinR, LOW);
    digitalWrite(ledPinG, LOW);


  }
  delay(200);

}
