#include <Arduino.h>
#include "DEL.h"
#include "DELClignotante.h"
#include "Program.h"

#define etatHaut(pin) ((pin) < 8 ? PORTD |= (1 << (pin)) : PORTB |= (1 << (pin - 8)))
#define etatBas(pin) ((pin) < 8 ? PORTD &= ~(1 << (pin)) : PORTB &= ~(1 << (pin - 8)))
//OU
#define debutCode (PORTD &= ~4)
#define finCode (PORTD |= 4)
// unsigned long dureeActionMS = 0;
// uint32_t dateDernierDecrementdureeActionUs = 0;
// int etapeCycle = 0;
// int dureeAllumee = 1000;  // ms
// int dureeEteinte = 500;   // ms

// int valeurIncrement = 0;
// const int pinMesureTemps = 2;

DELClignotante* del1;
Program* program; 

void setup() {
  Serial.begin(9600);
  //del1 = new DELClignotante(10, 50, 500, 500);
  program = new Program();
  //pinMode(pinMesureTemps, OUTPUT);
  // pinMode(LED_BUILTIN, OUTPUT);
  // dateDernierDecrementdureeActionUs = micros();
}

void loop() {
  //del1->tick(); 
  program->loop();
   //1er exercice
  //digitalWrite(pinMesureTemps, LOW);
  //valeurIncrement ++;
  //valeurIncrement = valeurIncrement % 8;
  //digitalWrite(pinMesureTemps, HIGH);

  //2eme exercice
  //digitalWrite(pinMesureTemps, LOW);
  //valeurIncrement ++
  //if(valeurIncrement >= 8){
  //   valeurIncrement -= 8;
  //}

  //3eme exercice
  //etatBas(2);
  //valeurIncrement ++;
  //valeurIncrement = valeurIncrement % 8;
  //etatHaut(2);

  //3eme exercice
  //debutCode;  
  // valeurIncrement ++;
  // valeurIncrement = valeurIncrement % 8;
  // finCode;

  //4eme exercice
  // while (dureeActionMS > 0 && (micros() - dateDernierDecrementdureeActionUs) >= 1000) {
  //   dureeActionMS--;
  //   dateDernierDecrementdureeActionUs += 1000;
  // }

  // if (dureeActionMS == 0) {
  //   switch (etapeCycle) {
  //     case 0:  // allumer
  //       digitalWrite(LED_BUILTIN, HIGH);
  //       dureeActionMS = dureeAllumee;
  //       ++etapeCycle;
  //       break;
  //     case 1:  // éteindre
  //       digitalWrite(LED_BUILTIN, LOW);
  //       dureeActionMS = dureeEteinte;
  //       etapeCycle = 0;
  //     default:
  //       break;
  //   }
  // }

  
}
