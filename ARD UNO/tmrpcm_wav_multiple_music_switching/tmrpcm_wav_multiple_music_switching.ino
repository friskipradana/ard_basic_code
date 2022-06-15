#include <SD.h>                      // need to include the SD library
//#define SD_ChipSelectPin 53  //example uses hardware SS pin 53 on Mega2560
#define SD_ChipSelectPin 10  //using digital pin 4 on arduino nano 328, can use other pins
#include <TMRpcm.h>           //  also need to include this library...
#include <SPI.h>
#define BTN1 2
#define BTN2 3
#define BTN3 7

TMRpcm tmrpcm;   // create an object for use in this sketch

unsigned long time = 0;

void setup() {
  pinMode(BTN1, INPUT);
  pinMode(BTN2, INPUT);
  pinMode(BTN3, INPUT);


  tmrpcm.speakerPin = 9; //5,6,11 or 46 on Mega, 9 on Uno, Nano, etc
  //Complimentary Output or Dual Speakers:
  //pinMode(10,OUTPUT); Pin pairs: 9,10 Mega: 5-2,6-7,11-12,46-45

  Serial.begin(115200);
  pinMode(13, OUTPUT); //LED Connected to analog pin 0
  if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");
    return;   // don't do anything more if not

  }
  else {
    Serial.println("SD ok");
  }
  //tmrpcm.play("letme.wav"); //the sound file "music" will play each time the arduino powers up, or is reset;


}



void loop() {
  if (digitalRead(BTN1) == 1 && !tmrpcm.isPlaying()) {
    tmrpcm.play("satu.wav"); //the sound file "music" will play each time the arduino powers up, or is reset;
  }
  if (digitalRead(BTN2) == 1 && !tmrpcm.isPlaying()) {
    tmrpcm.play("dua.wav"); //the sound file "music" will play each time the arduino powers up, or is reset;
  }
  if (digitalRead(BTN3) == 1 && !tmrpcm.isPlaying()) {
    tmrpcm.play("tiga.wav"); //the sound file "music" will play each time the arduino powers up, or is reset;
  }


  //blink the LED manually to demonstrate music playback is independant of main loop
  if (tmrpcm.isPlaying() && millis() - time > 50 ) {
    digitalWrite(13, !digitalRead(13));
    time = millis();
  } else if (millis() - time > 500) {
    digitalWrite(13, !digitalRead(13));
    time = millis();
  }

}
