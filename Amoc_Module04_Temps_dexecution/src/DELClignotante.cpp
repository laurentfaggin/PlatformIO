#include <Arduino.h>
#include "DELClignotante.h"
#include "DEL.h"

DELClignotante::DELClignotante(int p_pin, float p_rapportCycle,int p_dureeAllumee, int p_dureeEteinte): 
    DEL(p_pin, p_rapportCycle),
    m_dureeAllumee(p_dureeAllumee),
    m_dureeEteinte(p_dureeEteinte)
{
    m_dureeActionMS = 0;
    m_dateDerniereDecrementation = 0;
    m_etatCycle = 0;;
}

void DELClignotante::tick(){
    while(m_dureeActionMS > 0 && (micros() - m_dateDerniereDecrementation) >= 1000){
        m_dureeActionMS --;
        m_dateDerniereDecrementation += 1000;
    }

    if(m_dureeActionMS == 0){
        switch(m_etatCycle){
            case 0:
                eteindre();
                m_dureeActionMS = m_dureeEteinte;
                m_etatCycle = 1;
                break;
            case 1:
                allumer();
                m_dureeActionMS = m_dureeAllumee;
                m_etatCycle = 0;
                break;
        }
    }
}