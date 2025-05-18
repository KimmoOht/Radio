#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN

const byte osoite[] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(osoite);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();
}

void loop() {
  const char viesti[] = "Hei vastaanotin!";
  bool ok = radio.write(&viesti, sizeof(viesti));
  
  if (ok) {
    Serial.println("Viesti lähetetty");
  } else {
    Serial.println("Lähetys epäonnistui");
  }

  delay(1000);
