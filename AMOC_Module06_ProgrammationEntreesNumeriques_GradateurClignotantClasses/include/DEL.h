#pragma once
#include <Arduino.h>

class DEL{
public:
    DEL(uint8_t p_pin);
    void allumer();
    void allumer(float p_pourcentageIntensite);
    void eteindre();
    float getPourcentageIntensite();
    unsigned long getTempsAllume();
    unsigned long getTempsEteint();
    void setIntensite(float p_intensite);
    void clignoter(float p_tempsAllumee, float p_tempsEteint);
private:
    uint8_t m_pin;
    float m_pourcentageIntensite;
    uint32_t m_tempsAllume;
    uint32_t m_tempsEteint;
    unsigned long m_dureeActionMS;
    uint32_t m_dateDerniereDecrementation;
    int m_etatCycle;
};