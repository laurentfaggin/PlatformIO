#pragma once

class DEL{
public:
    DEL(int p_pin, float p_intensite);
    void allumer();
    void setIntensite(float p_pas);
    float getIntensite();
    void eteindre();
    void setEtat(int p_etat);
    int getEtat();
private:
    int m_pin;
    float m_intensite;
    int m_etat;
};