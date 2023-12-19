#include <Arduino.h>
#include "Morse.h"

Morse::Morse(){}

Morse::Morse(int p_dureePoint):
    m_dureePoint (p_dureePoint)
{
    ;
}

void Morse::afficherSOS() const
{
    for(size_t i = 0; i < 3; ++i)
    {
        afficherPoint();
        delay(getDureePoint());
    }
    for(size_t i = 0; i <  3; ++i)
    {
        afficherTrait();
        delay(getDureePoint());
    }
    for(size_t i = 0; i < 3; ++i)
    {
        afficherPoint();
    }
    delay(getDureePoint()*2);
}

int Morse::getDureePoint() const{
    return this->m_dureePoint;
}