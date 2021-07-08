
int ledPins[]= {11,10,9};
int pinCount=3;
int delays[]={5000,2000,5000};
int lightstateOn[]={1,1,1};
int lightstateOff[]={0,0,0};


void setup() {
  for(int i = 0; i < pinCount ; i++){
  pinMode(ledPins[i],OUTPUT);

  }
}

void loop() {  
   for(int x = 0; x < pinCount ; x++){
  digitalWrite(ledPins[x], lightstateOn[x]);
  delay(delays[x]);
  digitalWrite(ledPins[x], lightstateOff[x]);

  }
}
