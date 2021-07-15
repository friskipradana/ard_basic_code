#include <LiquidCrystal.h>
#include <virtuabotixRTC.h>
virtuabotixRTC myRTC(6, 7, 8); //CLK, DAT, RST

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  myRTC.setDS1302Time(00, 55, 8, 3, 10, 07, 2021);
  Serial.begin(9600);

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

  lcd.setCursor(1, 0);
  lcd.print(myRTC.dayofmonth);
  lcd.print("/");
  lcd.print(myRTC.month);
  lcd.print("/");
  lcd.print(myRTC.year);
  lcd.print(" ");
  lcd.setCursor(1, 1);
  lcd.print(myRTC.hours);
  lcd.print(":");
  lcd.print(myRTC.minutes);
  lcd.print(":");
  lcd.print(myRTC.seconds);
  lcd.print("  ");

}
