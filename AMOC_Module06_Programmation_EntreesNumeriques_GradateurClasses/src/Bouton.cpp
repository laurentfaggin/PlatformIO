#include <Arduino.h>
#include "Bouton.h"

Bouton::Bouton(uint8_t p_pinBouton, Action* p_action):
    m_pin(p_pinBouton),
    m_actionBoutonPresse(p_action)
{
    ;
}

uint8_t Bouton::getPin(){
    return m_pin;
}

void Bouton::tick(){
   m_actionBoutonPresse->executer();
}

