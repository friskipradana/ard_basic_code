const int buzzer = 8; //buzzer to arduino pin 13

void setup(){
  
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 7 as an output
//  Serial.begin(9600);

}

void loop(){ 
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1sec
  
}
