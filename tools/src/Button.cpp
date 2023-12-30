#include <Arduino.h>
#include "Button.h"

Button::Button(uint8_t p_pin):
    m_pin(p_pin),
    m_boutonPresse(false),
    etatBouton (0),
    derniereDateChangement(0),
    dernierEtatBouton(HIGH),
    dernierEtatStableBouton(HIGH),
    delaiMinPression(25)
{
    pinMode(getPin(), INPUT);
}


uint8_t Button::getPin(){
    return m_pin;
}

int Button::getEtat(){
    return etatBouton;
}

void Button::click(){
    int etatBouton = digitalRead(getPin());
    long dateActuelle = millis();

    if (etatBouton != dernierEtatBouton) {
        derniereDateChangement = dateActuelle;
        dernierEtatBouton = etatBouton;
    }

    if(dateActuelle - derniereDateChangement > delaiMinPression && dateActuelle - derniereDateChangement < delaiMinPression*1000 ) {
        if (dernierEtatStableBouton == HIGH && etatBouton == LOW) {
            //Action a effectuer
        } 
        dernierEtatStableBouton = etatBouton;
    }
    if(dateActuelle - derniereDateChangement > 5000 && etatBouton == LOW){
        if (dernierEtatStableBouton == LOW){
             //Action a effectuer            
        }
        dernierEtatStableBouton = etatBouton;
    }
}; 