#pragma once
#include "DEL.h"

class DELClignotante: public DEL{
public:
    DELClignotante(int p_pin, float p_rapportCycle, int p_dureeallumee, int p_dureeEteinte);
    void tick();
    unsigned long m_dureeActionMS;
    int m_etatCycle;
    uint32_t m_dateDerniereDecrementation;
private:
    int m_dureeAllumee;
    int m_dureeEteinte;
};