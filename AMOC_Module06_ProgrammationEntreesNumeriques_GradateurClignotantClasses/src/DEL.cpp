#include <Arduino.h>
#include "DEL.h"


DEL::DEL(uint8_t p_pin):
    m_pin(p_pin),
    m_tempsAllume(0),
    m_tempsEteint(0),
    m_pourcentageIntensite(100)
{
    m_etatCycle = 1;
    m_dureeActionMS = 0;
    m_dateDerniereDecrementation = 0;
}

void DEL::allumer(){
    analogWrite(m_pin, (m_pourcentageIntensite*255)/100);
}

void DEL::allumer(float p_pourcentage){
    m_pourcentageIntensite = p_pourcentage;
    analogWrite(m_pin, (m_pourcentageIntensite*255)/100);
}

void DEL::eteindre(){
    analogWrite(m_pin, LOW);
}

float DEL::getPourcentageIntensite(){
    return m_pourcentageIntensite;
}

void DEL::setIntensite(float p_intensite){
    m_pourcentageIntensite = p_intensite;
}

void DEL::clignoter(float p_tempsAllume, float p_tempsEteint) {

    unsigned long currentMicros = millis();
 
    while(m_dureeActionMS > 0 && (currentMicros - m_dateDerniereDecrementation) >= 1000){
        m_dureeActionMS --;
        m_dateDerniereDecrementation += 1000;
    }

    if (currentMicros - m_dateDerniereDecrementation >= m_dureeActionMS) {
    
        m_dateDerniereDecrementation = currentMicros;

        if (m_etatCycle == 1) {
            allumer(m_pourcentageIntensite);
            m_dureeActionMS = (unsigned long)p_tempsAllume;
            m_etatCycle = 0;
        } else {
            eteindre();
            m_dureeActionMS = (unsigned long)p_tempsEteint;
            m_etatCycle = 1;
        }
    }
}

  
