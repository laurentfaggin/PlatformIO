#pragma once
#include <Arduino.h>
#include <TM1637Display.h>
#include "Affichage4Digits.h"
#include "Affichage4DigitsProxyTM1637.h"
#include "Bouton.h"
#include "ActionBoutonPresse.h"
#include "Compteur.h"
#include "SavedData.h"

class Program{
    public:
        Program(int p_pinHorloge, int p_pinDonnees);
        void loop();
    private:
        Affichage4Digits * m_affichage;
        Compteur * m_compteur;
};