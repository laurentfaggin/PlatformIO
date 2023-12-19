#include <Arduino.h>
#include "DEL.h"


DEL::DEL(uint8_t p_pin):
    m_pin(p_pin)
{
   ;
}

void DEL::allumer(){
    analogWrite(m_pin, HIGH);
}

void DEL::allumer(float p_pourcentage){
    analogWrite(m_pin, (p_pourcentage*255)/100);
}

void DEL::eteindre(){
    analogWrite(m_pin, LOW);
}

