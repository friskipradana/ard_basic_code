#define btn_1 4
#define btn_2 5
#define led 13

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(btn_1, INPUT);
  pinMode(btn_2, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  Serial.print(digitalRead(btn_1));
  Serial.println(digitalRead(btn_2));

  if (digitalRead(btn_1) == true || digitalRead(btn_2) == true) {
    digitalWrite(led, HIGH);
    delay(50);
  } else {
    digitalWrite(led, LOW);
  }
  if (digitalRead(btn_1) == true && digitalRead(btn_2) == true ) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
  delay(100);
  // put your main code here, to run repeatedly:

}
