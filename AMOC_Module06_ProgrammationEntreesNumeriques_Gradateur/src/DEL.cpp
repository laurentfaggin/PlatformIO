#include <Arduino.h>
#include "DEL.h"


DEL::DEL(int p_pin, float p_intensite):
    m_pin(p_pin),
    m_intensite(p_intensite)
{
   ;
}

void DEL::allumer(){
    analogWrite(m_pin, m_intensite);
}

void DEL::eteindre(){
    analogWrite(m_pin, 0);
}

void DEL::setIntensite(float p_pas){
    m_intensite += p_pas;
}

float DEL::getIntensite(){
    return this->m_intensite;
}

void DEL::setEtat(int p_etat){
    m_etat = p_etat;
}

int DEL::getEtat(){
    return m_etat;
}