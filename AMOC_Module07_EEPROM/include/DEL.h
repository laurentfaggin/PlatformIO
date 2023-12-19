#pragma once
#include <Arduino.h>

class DEL{
public:
    DEL(uint8_t p_pin);
    void allumer();
    void allumer(int p_pourcentageIntensite);
    void eteindre();
    int getPourcentageIntensite();
    void setPourcentageintensite(int p_pourcentageIntensite);
private:
    uint8_t m_pin;
    int m_pourcentageIntensite;
};