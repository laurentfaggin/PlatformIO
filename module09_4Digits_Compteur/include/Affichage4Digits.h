#pragma once
#include <Arduino.h>
#include <TM1637Display.h>
#include "Affichage4DigitsProxy.h"

class Affichage4Digits{
    public:
        Affichage4Digits(Affichage4DigitsProxy * p_proxy);
        void afficher(uint8_t p_d1, uint8_t p_d2, uint8_t p_d3, uint8_t p_d4);
        void afficherEntier(uint16_t p_valeur);
        void afficherEntierBinaire(uint16_t p_valeur);
        uint8_t valeursSegment(uint16_t p_valeurSegment);
        void afficherBinaire(uint16_t p_valeur);
        void afficherDecimal(uint16_t p_valeur);

    private:
        Affichage4DigitsProxy * m_proxy;
};