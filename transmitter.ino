#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN   9
#define CSN_PIN  10
#define JOY1_X A0
#define JOY1_Y A1
#define JOY2_X A2

RF24 radio(CE_PIN, CSN_PIN);
const byte address[6] = "AUROR";

struct Data_Package {
  int j1_x;
  int j1_y;
  int j2_x;
};
Data_Package data;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening();
}

void loop() {
  data.j1_x = analogRead(JOY1_X);
  data.j1_y = analogRead(JOY1_Y);
  data.j2_x = analogRead(JOY2_X);

  radio.write(&data, sizeof(Data_Package));
  delay(20); 
}
