#include <Arduino.h>
#include "TrafficLights.h"


TrafficLights::TrafficLights(TrafficLightsCar* p_feuxVoiture, TrafficLightsPesdestrian* p_feuxPieton):
    m_etatFeu(3),
    m_demandePieton(0),
    m_etatPieton(0)
    {
        m_dureeClignotement = 0;
        m_dateDerniereDecrementation = 0;
    }

int TrafficLights::getEtatFeu(){
    return m_etatFeu;
}

void TrafficLights::setEtatFeu(int p_etat){
    m_etatFeu = p_etat;
}

int TrafficLights::getDemandePieton(){
    return m_demandePieton;
}

void TrafficLights::setDemandePieton(int p_demande){
   m_demandePieton = p_demande;
}



void TrafficLights::gestionAllumageFeux(int p_etat){
    m_etatFeu = p_etat;
    switch(m_etatFeu){
        case 0:
            m_dureeClignotement = 15000;
            m_feuxVoiture->allumerRougeVoiture();
            m_feuxPieton->allumerRougePieton();         
            break;
        case 1:            
            m_dureeClignotement = 20000;
            m_feuxVoiture->allumerRougeVoiture();
            m_feuxPieton->allumerVertPieton();
            break;
        case 2:
            m_dureeClignotement = 1000;
            m_feuxVoiture->allumerRougeVoiture();
            m_feuxPieton->allumerRougePieton();
            break;
        case 3:
            m_dureeClignotement = 30000;
            m_feuxVoiture->allumerVertVoiture();
            m_feuxPieton->allumerRougePieton();
            break;
        case 4:
            m_dureeClignotement = 5000;
            m_feuxVoiture->allumerJauneVoiture();
            m_feuxPieton->allumerRougePieton();
            break;
        default:
            break;
    }  
}

void TrafficLights::modeNormal(){
    if (m_dureeClignotement > 0 && (micros() - m_dateDerniereDecrementation) >= 1000) {
        m_dureeClignotement--;
        m_dateDerniereDecrementation += 1000;
    }
    if(!m_dureeClignotement){
        switch (m_etatFeu){
            case 0:
            Serial.println(m_demandePieton);
                if (m_demandePieton == 1){                           
                        m_etatFeu = 1;                      
                    }
                else if(m_demandePieton == 0){       
                    gestionAllumageFeux(3);
                    m_etatFeu = 3;
                }
                break;
            case 1:        
                gestionAllumageFeux(1);
                m_etatFeu = 2;
                break;
            case 2:
                gestionAllumageFeux(2);
                m_demandePieton = 0;       
                m_etatFeu = 0;
                break;
            case 3:
                gestionAllumageFeux(4);
                m_etatFeu = 4;
                break;
            case 4:                
                gestionAllumageFeux(0);
                m_etatFeu=0;
                break;
            default:
                break;    
        }
    }    
}


