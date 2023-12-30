#pragma once
#include <Arduino.h>
#include "DEL.h"
#include "Button.h"
#include "TrafficLightsCar.h"
#include "TrafficLightsPedestrian.h"

class TrafficLights{
public:

    TrafficLights(TrafficLightsCar* p_feuxVoiture, TrafficLightsPesdestrian* p_feuxPieton);

    void modeNormal();
    void modeUrgence();
    void modeEntretien();
    int getDemandePieton();
    void setDemandePieton(int p_demande);
    int getEtatFeu();
    void setEtatFeu(int p_etatfeu);
    int getRatioFeu();
    void setRatio(int p_ratio);
    int getCompteurvoiture();
    void setcompteurVoiture(int p_valeur);
    int getCompteurPieton();
    void setCompteurPieton(int p_compteur);
    void resetPourcentage();
    void gestionAllumageFeux(int nouvelEtat);
private:

    TrafficLightsCar* m_feuxVoiture;
    TrafficLightsPesdestrian* m_feuxPieton;
    Button* m_boutonPieton;
    int m_etatFeu;
    int m_etatPieton;
    int m_pourcentageCyclesPieton;
    unsigned long m_dureeEtat;
    unsigned long m_debutEtat;
    unsigned long m_dureeAllumage;
    unsigned long m_dureeClignotement;
    uint32_t m_dateDerniereDecrementation;
    int m_etatCycle;
    int m_demandePieton;
};