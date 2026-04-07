#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

#define CE_PIN   7
#define CSN_PIN  8
#define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6
#define SERVO_PIN 9

RF24 radio(CE_PIN, CSN_PIN);
const byte address[6] = "AUROR";
Servo camServo;

struct Data_Package {
  int j1_x;
  int j1_y;
  int j2_x;
};
Data_Package data;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  camServo.attach(SERVO_PIN);
  
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening();

  data.j1_x = 512;
  data.j1_y = 512;
  data.j2_x = 512;
}

void loop() {
  if (radio.available()) {
    radio.read(&data, sizeof(Data_Package));
  }

  int servoAngle = map(data.j2_x, 0, 1023, 0, 180);
  camServo.write(servoAngle);

  int yAxis = data.j1_y;
  int xAxis = data.j1_x;

  if (yAxis < 470) { 
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } 
  else if (yAxis > 550) { 
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  } 
  else if (xAxis < 470) { 
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } 
  else if (xAxis > 550) { 
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  } 
  else { 
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
}
