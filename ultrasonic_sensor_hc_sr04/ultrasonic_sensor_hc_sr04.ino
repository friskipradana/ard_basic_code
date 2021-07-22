#define transmitter A2
#define receiver 9
long durasi, jarak;
void setup() {
  // put your setup code here, to run once:
  pinMode(A2, OUTPUT);
  pinMode(9, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // this program bellow will be trigger ultrasonic audio
  digitalWrite(transmitter, LOW);
  delayMicroseconds(8);
  digitalWrite(transmitter, HIGH);
  delayMicroseconds(8);
  digitalWrite(transmitter, LOW);
  delayMicroseconds(8);
 
  
  durasi = pulseIn(receiver, HIGH); //recieve ultrasonic audio
  jarak = (durasi / 2) / 29.1;      // durasi to (cm)
  Serial.print(jarak);
  Serial.println("cm");
  delay(100);
}
