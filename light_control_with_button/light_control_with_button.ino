const int BUTTON = 2;
const int LED = 12;

int StateButton;

void setup()
{
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  StateButton = digitalRead(BUTTON);
  Serial.print("Value : ");
  Serial.println(StateButton);

  
  if (StateButton == HIGH)
  {
    digitalWrite(LED, HIGH);
  } 
  else{
    digitalWrite(LED, LOW);
  }
}
