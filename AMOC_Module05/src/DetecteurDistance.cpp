#include <Arduino.h>
#include "DetecteurDistance.h"


DetecteurDistance::DetecteurDistance(int p_pinTrigger, int p_pinEcho):
    m_pintrigger(p_pinTrigger),
    m_pinEcho(p_pinEcho)
{
    pinMode(m_pintrigger, OUTPUT);
    digitalWrite(m_pinEcho, LOW);   

    pinMode(m_pinEcho, INPUT);
}

double DetecteurDistance::ObtenirDistance()
{
    digitalWrite(m_pintrigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(m_pintrigger, LOW);

    int duree = pulseIn(m_pinEcho, HIGH);

    return duree;
}

void DetecteurDistance::DetectionObstacle(int p_pinVerte, int p_pinJaune, int p_pinRouge, int distance)
{
    if (distance >= securitaire){
        digitalWrite(p_pinVerte, HIGH);
        digitalWrite(p_pinJaune, LOW);
        digitalWrite(p_pinRouge, LOW);
    }
    else if(distance < securitaire && distance > danger){
        digitalWrite(p_pinVerte, LOW);
        digitalWrite(p_pinJaune, HIGH);
        digitalWrite(p_pinRouge, LOW);
    }
    else{
        digitalWrite(p_pinVerte, LOW);
        digitalWrite(p_pinJaune, LOW);
        digitalWrite(p_pinRouge, HIGH);
    }
}

