#include <Arduino.h>
#include "DEL.h"
const int borneentree = 2;
const int borneSortie = 3;

long derniereDatechangement = 0;
int dernierEtatBouton = HIGH;
int dernierEtatStableBouton = HIGH;
const int delaiMinPression = 25;
int etatBouton = 0;

int valBouton;
DEL* del;

void setup() {
  Serial.begin(9600);
  del = new DEL(3, 250);
  pinMode(borneentree, INPUT);
  pinMode(borneSortie, OUTPUT);
}

void loop() {
  valBouton = digitalRead(borneentree);
  if (valBouton == 0 && etatBouton == 0){
  Serial.println(valBouton);
    if (del->getEtat() == 0){
      del->allumer();
      del->setEtat(1);
    }
    else if(del->getEtat() == 1){
      del->eteindre();
      del->setEtat(0);
    };
    etatBouton = 1;
  }
  if (valBouton == 1){
    etatBouton = 0;
  }
}

