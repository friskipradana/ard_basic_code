#define btn_1 4
#define btn_2 5
#define led 13
#define buzz 9
#define ldr A0
int i;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(btn_1, INPUT);
  pinMode(btn_2, INPUT);
  pinMode(ldr, INPUT);
}

void loop() {

  if (digitalRead(btn_1)) {
    Serial.println("btn-1");
    i++;
    delay(100);
  }
  if (digitalRead(btn_2)) {
    Serial.println("btn-2");
    i--;
    delay(100);
  }

  switch (i) {
    case 1:
      Serial.print("case 1");
      Serial.println(" [led]");
      digitalWrite(led, HIGH);
      delay(50);
      digitalWrite(led, LOW);
      delay(50);
      break;
    case 2:
      Serial.print("case 2");
      Serial.println(" [buzz]");
      tone(buzz, 1000);
      delay(100);
      noTone(buzz);
      delay(100);
      break;
    case 3:
      Serial.print("case 3");
      Serial.println(" [ldr]");
      Serial.println(analogRead(ldr));
      delay(50);
      break;

    default:
      Serial.println("case 0");
      delay(100);
      break;

  }
  //  min max logic
  if (i > 3 ) {
    i = 3;
  }else if (i < 0 ) {
    i = 0;
  }
  Serial.println(i);
}
