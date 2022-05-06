#include <virtuabotixRTC.h>

virtuabotixRTC myRTC(6, 7, 8); //CLK, DAT, RST

void setup() {
Serial.begin(9600); 
//myRTC.setDS1302Time(00, 9, 19, 00, 06, 05, 2022); 
}

void loop() {
myRTC.updateTime();
Serial.print("Tanggal / Waktu: ");
Serial.print(myRTC.dayofmonth); //menampilkan tanggal
Serial.print("/");
Serial.print(myRTC.month); //menampilkan bulan
Serial.print("/");
Serial.print(myRTC.year); //menampilkan tahun
Serial.print(" ");
Serial.print(myRTC.hours); //menampilkan jam
Serial.print(":");
Serial.print(myRTC.minutes); //menampilkan menit
Serial.print(":");
Serial.println(myRTC.seconds); //menampilkan detik
delay( 1000);
}
