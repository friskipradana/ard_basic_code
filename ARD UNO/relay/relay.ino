#define pin 4
 
void setup(){
pinMode(pin, OUTPUT);
}
 
void loop() {
digitalWrite(pin, HIGH);
delay(5000);
digitalWrite(pin, LOW);
delay(5000);
}
 
