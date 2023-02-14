
/*
* Program WDT Sederhana
* www.saifulmiqdar.my.id
*/
// include library wdt
#include <avr/wdt.h>
// counter 
const byte jumlah_krupuk = 10;
// lama delay makan krupuk dal ms
int lama_makan_krupuk[jumlah_krupuk] = {
 1000,
 1500,
 1000,
 1500,
 1000,
 3000, // keselek, jadi lama
 1000,
 1000,
 1000,
 1000
 };
byte giliran = 0;
void setup() {
 // disable wdt
 // lalu tunggu hingga stabil
 wdt_disable();
 delay(2000);
 Serial.begin(19200);
 while(!Serial);
 //
 // kunfigurasi lainnya jika ada
 //
 Serial.println("==== Start Program!");
 // aktifkan wdt dg waktu tunggu 8 detik
 wdt_enable(WDTO_2S);
}
void loop() {
 // lama makan krupuk sesuai giliran
 delay( lama_makan_krupuk[giliran] );
 // giliran berikutnya
 giliran++;
 Serial.print("Krupuk No. ");
 Serial.print(giliran);
 Serial.println(", habis!");
 
 // reset wdt, krupuk sudah habis
 wdt_reset();
}
