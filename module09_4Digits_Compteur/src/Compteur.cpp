#include "Compteur.h"
#include <EEPROM.h>

Compteur::Compteur():
    m_valeur(0)
{
    
}

void Compteur::incrementer(){
    m_valeur += 1;
    //sauvegarderValeur();
}

int Compteur::obtenirValeur(){
    return m_valeur;
}

void Compteur::chargerValeur(int p_valeur){   
    m_valeur = p_valeur;
}

void Compteur::remiseAZero(){
    m_valeur = 0;
}