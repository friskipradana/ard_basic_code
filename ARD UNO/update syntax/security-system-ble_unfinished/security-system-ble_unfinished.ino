#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

char val = 5;
void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }

  sendCommand("AT");
  sendCommand("AT+VERSION");
  sendCommand("AT+ROLE0");
  sendCommand("AT+UUID0xFFE0");
  sendCommand("AT+CHAR0xFFE1");
  sendCommand("AT+NAMEBleArdUno");
  oled("login", "", val, NULL);
}

void sendCommand(const char * command) {
  Serial.print("Command send :");
  Serial.println(command);
  mySerial.println(command);
  //wait some time
  delay(100);

  char reply[100];
  int i = 0;
  while (mySerial.available()) {
    reply[i] = mySerial.read();
    i += 1;
  }
  //end the string
  reply[i] = '\0';
  oled("bt_check", reply, NULL, NULL);
  delay(2000);
  Serial.print(reply);
  Serial.println("Reply successful");


}

void readSerial() {
  char reply[50];
  int i = 0;
  while (mySerial.available()) {
    reply[i] = mySerial.read();
    i += 1;
  }
  //end the string
  reply[i] = '\0';
  if (strlen(reply) > 0) {
    oled("receive", reply, NULL, NULL);
    Serial.println(reply);
    Serial.println("Houston we have a signal!");
  }
}

void oled(String type, String reply, byte id, byte pass) {

  if (type == "bt_check") {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("response: ");
    display.setCursor(0, 10);
    display.println(reply);
    display.display();
  }
  if (type == "login") {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("Security System");
    display.setCursor(0, 10);
    display.print("Your ID : ");
    display.print(" ");
    display.print(id);
    display.display();
  }
  if (type == "receive") {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("Receive: ");
    display.println(reply);
    display.display();
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  readSerial();
  delay(500);

}
