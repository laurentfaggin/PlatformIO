#include <Arduino.h>
#include "Bouton.h"
#include "ActionModifierIntensiteDEL.h"
#include "DEL.h"

const int borneentree = 2;
const int borneSortie = 3;

long derniereDatechangement = 0;
int dernierEtatBouton = HIGH;
int dernierEtatStableBouton = HIGH;
const int delaiMinPression = 25;

int valBouton;
DEL* del;

void setup() {
  Serial.begin(9600);
  del = new DEL(3);
  pinMode(borneentree, INPUT);
  pinMode(borneSortie, OUTPUT);
}

void loop() {
  Serial.println(valBouton);
  valBouton = digitalRead(borneentree);
  if (valBouton == 0){
    del->allumer();
  }
  else {
      del->eteindre();
  }

}

