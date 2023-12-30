#include "TrafficlightsCar.h"

TrafficLightsCar::TrafficLightsCar(DEL* p_vert, DEL* p_orange, DEL* p_rouge):
    m_vert(p_vert),
    m_orange(p_orange),
    m_rouge(p_rouge),
    m_compteur(0)
{
    ;
}

void TrafficLightsCar::setCompteurFeuVoiture(int p_compteur){
    m_compteur = p_compteur;
}

int TrafficLightsCar::getCompteurFeuVoiture() const{
    return m_compteur;
}

void TrafficLightsCar::allumerRougeVoiture(){
    m_rouge->allumer();
    m_orange->eteindre();
    m_vert->eteindre();
}

void TrafficLightsCar::allumerJauneVoiture(){
    m_rouge->eteindre();
    m_orange->allumer();
    m_vert->eteindre();
}

void TrafficLightsCar::allumerVertVoiture(){
    m_rouge->eteindre();
    m_orange->eteindre();
    m_vert->allumer();
}