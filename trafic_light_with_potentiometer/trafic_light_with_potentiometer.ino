#define LEDR 11
#define LEDY 10
#define LEDG 9
#define Potentiometer A0

int sensorValue;

void setup() {
  pinMode(LEDR,OUTPUT);
  pinMode(LEDY, OUTPUT);
  pinMode(LEDG, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(Potentiometer);
  Serial.print("Level : ");
  Serial.println(sensorValue);
  
  red_light();
  delay(sensorValue);
  yellow_light();
  delay(sensorValue);
  green_light();
  delay(sensorValue);

}
void red_light(){
  digitalWrite(LEDR, HIGH);
  digitalWrite(LEDY, LOW);
  digitalWrite(LEDG, LOW);
}
void yellow_light(){
  digitalWrite(LEDR, LOW);
  digitalWrite(LEDY, HIGH);
  digitalWrite(LEDG, LOW);
}
void green_light(){
  digitalWrite(LEDR, LOW);
  digitalWrite(LEDY, LOW);
  digitalWrite(LEDG, HIGH);
}
