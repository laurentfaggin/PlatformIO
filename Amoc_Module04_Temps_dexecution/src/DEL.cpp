#include <Arduino.h>
#include "DEL.h"


DEL::DEL(int p_pin, float p_rapportCycle):
    m_pin(p_pin),
    m_rapportCycle(p_rapportCycle)
{
   ;
}

void DEL::allumer(){
    analogWrite(m_pin, m_rapportCycle);
}

void DEL::eteindre(){
    analogWrite(m_pin, 0);
}

void DEL::setRapportCycle(float p_rapport){
    m_rapportCycle = (p_rapport*255)/100;
}

float DEL::getRapportCycle(){
    return m_rapportCycle;
}