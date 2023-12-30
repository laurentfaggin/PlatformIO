#include "TrafficLightsPedestrian.h"


TrafficLightsPesdestrian::TrafficLightsPesdestrian(DEL* p_vert, DEL* p_rouge):
    m_vert(p_vert),
    m_rouge(p_rouge),
    m_compteur(0)
{
    ;
}

void TrafficLightsPesdestrian::setCompteurFeuVoiture(int p_compteur){
    m_compteur = p_compteur;
}

int TrafficLightsPesdestrian::getCompteurFeuVoiture() const{
    return m_compteur;
}

void TrafficLightsPesdestrian::allumerRougePieton(){
    m_rouge->allumer();
    m_vert->eteindre();
}

void TrafficLightsPesdestrian::allumerVertPieton(){
    m_rouge->eteindre();
    m_vert->allumer();
}