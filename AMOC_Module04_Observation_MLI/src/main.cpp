#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  analogWrite(3, 25);
  analogWrite(5, 127);
  analogWrite(6, 127);
  analogWrite(9, 127);
  analogWrite(10, 191);
  analogWrite(11, 127);
  Serial.println("hello");
}

void loop() {

}

// unsigned long dureeActionMS = 0;
// uint32_t dateDernierDecrementdureeActionUs = 0;
// int etapeCycle = 0;
// int dureeAllumee = 1000;  // ms
// int dureeEteinte = 500;   // ms
// void setup() {
//   pinMode(LED_BUILTIN, OUTPUT);
//   dateDernierDecrementdureeActionUs = micros();
// }

// void loop() {
//   while (dureeActionMS > 0 && (micros() - dateDernierDecrementdureeActionUs) >= 1000) {
//     dureeActionMS--;
//     dateDernierDecrementdureeActionUs += 1000;
//   }

//   if (dureeActionMS == 0) {
//     switch (etapeCycle) {
//       case 0:  // allumer
//         digitalWrite(LED_BUILTIN, HIGH);
//         dureeActionMS = dureeAllumee;
//         ++etapeCycle;
//         break;
//       case 1:  // éteindre
//         digitalWrite(LED_BUILTIN, LOW);
//         dureeActionMS = dureeEteinte;
//         etapeCycle = 0;
//       default:
//         break;
//     }
//   }
// }