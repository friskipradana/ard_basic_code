const int X_pin = 4;
const int Y_pin = 2;
const int SW_pin = 15;

void setup() {
  // put your setup code here, to run once:
pinMode(SW_pin, INPUT);
digitalWrite(SW_pin,HIGH);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print("Switch: ");
Serial.print(digitalRead(SW_pin));
Serial.print(" | ");
Serial.print("X-axis: ");
Serial.print(analogRead(X_pin));
Serial.print(" | ");
Serial.print("Y-axis: ");
Serial.println(analogRead(Y_pin));
delay(200);
}
