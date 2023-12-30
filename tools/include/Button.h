#pragma once
#include <Arduino.h>

class Button{
    public:
    Button(uint8_t p_pinbutton);
    void click();
    uint8_t getPin();
    int getEtat();
private:
    uint8_t m_pin;
    bool m_boutonPresse;
    int etatBouton;

    long derniereDateChangement;
    int dernierEtatBouton;
    int dernierEtatStableBouton;
    const int delaiMinPression;
};