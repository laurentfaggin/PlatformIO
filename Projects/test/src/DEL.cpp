#include <Arduino.h>
#include "DEL.h"

DEL::DEL(const int& p_pinDEL){
    this->m_pinDEL = p_pinDEL;
}

void DEL::allumer() const{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(this->m_pinDEL);
}

void DEL::eteindre() const{
    digitalWrite(LED_BUILTIN, LOW);
    delay(this->m_pinDEL);
}