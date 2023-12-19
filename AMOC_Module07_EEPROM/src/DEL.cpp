#include <Arduino.h>
#include "DEL.h"


DEL::DEL(uint8_t p_pin):
    m_pin(p_pin),
    m_pourcentageIntensite(0)
{
   ;
}

void DEL::allumer(){
    analogWrite(m_pin, m_pourcentageIntensite*255/100);
}

void DEL::allumer(int p_pourcentageIntensite){
    setPourcentageintensite(p_pourcentageIntensite);
    analogWrite(m_pin, m_pourcentageIntensite*255/100);
}

void DEL::eteindre(){
    analogWrite(m_pin, LOW);
}

int DEL::getPourcentageIntensite(){
    return m_pourcentageIntensite;
}

void DEL::setPourcentageintensite(int p_pourcentageIntensite){
    m_pourcentageIntensite = p_pourcentageIntensite;
}