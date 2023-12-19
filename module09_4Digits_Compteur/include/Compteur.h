#pragma once
#include <Arduino.h>

class Compteur{
    public:
        Compteur();
        void incrementer();
        int obtenirValeur();
        void sauvegarderValeur();
        void chargerValeur(int p_valeur);
        void remiseAZero();
    private:
        int m_valeur;
};