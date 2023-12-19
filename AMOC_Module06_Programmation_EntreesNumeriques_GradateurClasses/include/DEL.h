#pragma once
#include <Arduino.h>

class DEL{
public:
    DEL(uint8_t p_pin);
    void allumer();
    void allumer(float p_pourcentageIntensite);
    void eteindre();
    //float getPourcentageIntensite();
private:
    uint8_t m_pin;
    float m_pourcentageIntensite;
};