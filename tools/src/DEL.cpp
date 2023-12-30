#include <Arduino.h>
#include "DEL.h"

DEL::DEL(uint8_t p_pin):
    m_pin(p_pin),
    m_dureeClignotement(500),
    m_dateDerniereDecrementation(0),
    m_etatCycle(0)
{
    pinMode(m_pin, OUTPUT);
}

void DEL::dureeAllumage(unsigned long p_duree){
    unsigned long currentTime = millis();
    while (millis() - currentTime <= p_duree){
        allumer();
    }
    eteindre();
}

void DEL::allumer(){
    digitalWrite(m_pin, HIGH);
}

void DEL::eteindre(){
    digitalWrite(m_pin, LOW);
}

void DEL::clignoter(){
    unsigned long currentMillis = millis();
    if(currentMillis - m_dateDerniereDecrementation >= m_dureeClignotement){
        m_dateDerniereDecrementation = currentMillis;
        if(m_etatCycle == 1){
            allumer();
            m_etatCycle = 0;
        }
        else{
            eteindre();
            m_etatCycle = 1;
        }
    }
}