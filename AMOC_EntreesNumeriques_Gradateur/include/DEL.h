#pragma once

class DEL{
public:
    DEL(int p_pin, int p_intensite);
    void allumer();
    void eteindre();
    void setEtat(int p_etat);
    int getEtat();
private:
    int m_pin;
    int m_intensite;
    int m_etat;
};