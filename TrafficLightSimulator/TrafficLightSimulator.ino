#include "Arduino_LED_Matrix.h"

const int green = 13;
const int yellow = 12;
const int red = 10;
const int button = 2;

ArduinoLEDMatrix matrix; //matrix object

void setup() {
  Serial.begin(9600); //start serial connection on 9600 baud
  matrix.begin();

  //configure pin
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(button, INPUT);
}

uint8_t frame[8][12] = { //all led's are starting off
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};
void trafficLightSimulator() { //simulation function after button is pressed
  Serial.println("Button pressed, initiating code...");
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    Serial.println("Green light ON.");
    delay(1300);
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    Serial.println("Yellow light ON.");
    delay(800);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    Serial.println("Red light ON.");
    delay(1500);
    digitalWrite(red, LOW);
    Serial.println("Code finished");
}
void loop() { //main loop
  digitalWrite(red, HIGH);

  int buttonState = digitalRead(button); //get active state of button
  if (buttonState == HIGH) { //button pressed
    trafficLightSimulator();
  }
}