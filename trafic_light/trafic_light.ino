#define LEDR 11
#define LEDY 10
#define LEDG 9

int DELAY_RED = 5000; // 5 second
int DELAY_YELLOW = 2000; // 2 second
int DELAY_GREEN = 5000; // 5 second


void setup() {
  pinMode(LEDR,OUTPUT);
  pinMode(LEDY, OUTPUT);
  pinMode(LEDG, OUTPUT);
}

void loop() {  
  red_light();
  delay(DELAY_RED);
  yellow_light();
  delay(DELAY_YELLOW);
  green_light();
  delay(DELAY_GREEN);

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
