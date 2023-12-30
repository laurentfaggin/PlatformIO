#pragma once
#include <Arduino.h>

class DEL{
public:
    DEL(uint8_t p_pin);
    void allumer();
    void eteindre();
    void clignoter();
    void dureeAllumage(unsigned long p_duree);
private:
    uint8_t m_pin;
    unsigned long m_dureeClignotement;
    uint32_t m_dateDerniereDecrementation;
    int m_etatCycle;
};