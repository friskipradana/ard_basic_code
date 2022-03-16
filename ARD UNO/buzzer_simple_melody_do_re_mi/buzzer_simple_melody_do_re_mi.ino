#define BUZZER_PIN 8

void setup() {
  //DO, RE, MI, FA, SOL, LA, SI, DO
  // {PIN,FREQUENCY,DELAY}
  tone(BUZZER_PIN, 262); delay(500);
  tone(BUZZER_PIN, 294); delay(500);
  tone(BUZZER_PIN, 330); delay(500);
  tone(BUZZER_PIN, 349); delay(500);
  tone(BUZZER_PIN, 395); delay(500);
  tone(BUZZER_PIN, 440); delay(500);
  tone(BUZZER_PIN, 494); delay(500);
  tone(BUZZER_PIN, 523); delay(500);
  noTone(BUZZER_PIN); delay(500);

}

void loop() {

}
