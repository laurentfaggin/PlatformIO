#include <Arduino.h>
#include "Servo.h"

Servo servo;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  servo.attach(9);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  
  delay(1000);                      
  digitalWrite(LED_BUILTIN, LOW);   
  delay(1000);
  for (int pos = 0; pos <= 180; ++pos){
    servo.write(pos);
    delay(15);
  }
  for(int pos = 180; pos > 0; --pos){
    servo.write(pos);
    delay(15);
  }
}

