/* Program Membaca Input Dari Rotary Encoder dibuat oleh Indobot */

#define outputA 12     //CLK pada pin D6
#define outputB 11     //DT pada pin D7
#define button 10      //SW pada pin D8

int counter = 0;      //Variabel penghitung nilai
int aState;           //Variabel kondisi
int aLastState;       //Variabel kondisi terakhir

void setup() { 
  pinMode (outputA,INPUT_PULLUP); //Sertting sebagai input pullup
  pinMode (outputB,INPUT_PULLUP);
  pinMode (button,INPUT_PULLUP);
    
  Serial.begin (9600);                //Mulai komunikasi serial
  aLastState = digitalRead(outputA);  //Baca kondisi terakhir CLK
} 
void loop() { 
  aState = digitalRead(outputA);          //Baca kondisi CLK
  if (aState != aLastState){              //Jika ada perubahan kondisi, maka
    if (digitalRead(outputB) != aState) { //Jika berputar ke kiri, maka
      counter ++;                         //Nilai bertambah
    } else {                              //Jika berputar ke kanan, maka
      counter --;                         //Nilai berkurang
    }
    Serial.print("Position: ");
    Serial.println(counter);              //Tampilkan nilai
  } 
  aLastState = aState;                    //Rekam kondisi

  if(digitalRead(button) == LOW){         //Jika tombol ditekan, maka
    Serial.println("Button pressed");     //Tampilkan text
    delay(200);                           //Jeda pembacaan 200ms
  }
}
