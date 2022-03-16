/*
 * Emulates a nRF8001 temperature beacon; 
 * reads temperature from a DHT11 and sends it via BTLE.
 * Compatible with Nordic Semiconductor apps such as
 * nRF Master Control Panel or nRF Temp 2.0.
 */

#include <BTLE.h>

#include <SPI.h>
#include <RF24.h>
#include "DHT.h"
#define DHTPIN A0  
#define DHTTYPE DHT11   // DHT 11

RF24 radio(9,10);
BTLE btle(&radio);


DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(57600);
  
  dht.begin();
  
  while (!Serial) { }
  Serial.println("BTLE temperature sender");
  Serial.end();

  // 8 chars max
  btle.begin("TempBLE");
}

void loop() {



  nrf_service_data buf;
  buf.service_uuid = NRF_TEMPERATURE_SERVICE_UUID;
  buf.value = BTLE::to_nRF_Float(dht.readTemperature());
  
  if(!btle.advertise(0x16, &buf, sizeof(buf))) {
    Serial.begin(57600);
    Serial.println("BTLE advertisement failure");
    Serial.end();
  }
 // btle.advertise(0,0);
  btle.hopChannel();
  Serial.print(".");

}
