#pragma once
#include <Arduino.h>
#include "Action.h"

class Bouton{
public:
    Bouton(uint8_t p_pinBouton, Action* p_actionBoutonPresse);
    void tick();

private:
    uint8_t m_pin;
    Action* m_actionBoutonPresse;
};