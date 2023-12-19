#include <Arduino.h>
#include "Bouton.h"

Bouton::Bouton(uint8_t p_pinBouton, Action* p_action):
    m_pin(p_pinBouton),
    m_actionBoutonPresse(p_action)
{
    derniereDateChangement1 = 0;
    dernierEtatBouton1 = HIGH;
    dernierEtatStableBouton1 = HIGH;
    delaiMinPression = 25;
    etatBouton = 0;
    pinMode(getPin(), INPUT);
}

uint8_t Bouton::getPin(){
    return m_pin;
}

void Bouton::tick(){
    etatBouton = digitalRead(getPin());
    long dateActuelle = millis();

    if (etatBouton != dernierEtatBouton1) {
        derniereDateChangement1 = dateActuelle;
        dernierEtatBouton1 = etatBouton;
    }

    if(dateActuelle - derniereDateChangement1 > delaiMinPression) {
        if (dernierEtatStableBouton1 == HIGH && etatBouton == LOW) {
            m_actionBoutonPresse->executer();                 
        } 
        dernierEtatStableBouton1 = etatBouton;
    }  
}

