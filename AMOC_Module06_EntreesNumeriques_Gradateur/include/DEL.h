#pragma once

class DEL{
public:
    DEL(uint8_t p_pin);
    void allumer();
    void allumer(float p_pourcentageIntensite);
    void eteindre();
private:
    uint8_t m_pin;
};