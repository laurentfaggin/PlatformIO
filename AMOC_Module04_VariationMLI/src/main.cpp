#include <Arduino.h>

int value = 0;
int step = 5;

void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
}

void loop() {
  analogWrite(9, value);
  if (value <= 0 || value >= 255){
    step = -step;
  }
  delay(500);
}

