#include "Affichage4Digits.h"

const byte segmentValue[] = {
    0b00111111,  // 0
    0b00000110,  // 1
    0b01011011,  // 2
    0b01001111,  // 3
    0b01100110,  // 4
    0b01101101,  // 5
    0b01111101,  // 6
    0b00000111,  // 7
    0b01111111,  // 8
    0b01101111   // 9
} ;

Affichage4Digits::Affichage4Digits(Affichage4DigitsProxy * p_proxy):
    m_proxy(p_proxy)
{
    ;
}

void Affichage4Digits::afficher(uint8_t p_d1, uint8_t p_d2, uint8_t p_d3, uint8_t p_d4){
    m_proxy->afficher(p_d1, p_d2, p_d3, p_d4);
}

void Affichage4Digits::afficherEntier(uint16_t p_valeur){
    //decomposition de le valeur en chiffres unitaires. ex: 2672
    uint8_t d1 = p_valeur / 1000;            // =2
    uint8_t d2 = (p_valeur% 1000) / 100;     // =6
    uint8_t d3 = (p_valeur % 100) / 10;      // =7
    uint8_t d4 = (p_valeur % 10);            // =2

    afficher(valeursSegment(d1) | 0b10000000 ,valeursSegment(d2), valeursSegment(d3), valeursSegment(d4));
}

void Affichage4Digits::afficherEntierBinaire(uint16_t p_valeur){
    switch (p_valeur){
        case 0:
            afficher(0, 0, 0, 0);
            break;
        case 1:
            afficher(0, 0, 0, 1);
            break;
        case 2:
            afficher(0, 0, 1, 0);
            break;
        case 3:
            afficher(0, 0, 1, 1);
            break;
        case 4:
            afficher(0, 1, 0, 0);
            break;
        case 5:
            afficher(0, 1, 0, 1);
            break;
        case 6:
            afficher (0, 1, 1, 0);
            break;
        case 7:
            afficher(0, 1, 1, 1);
            break;
        case 8:
            afficher(1, 0, 0, 0);
            break;
        case 9: 
            afficher(1, 0, 0, 1);
            break;
        default:
            afficher(0, 0, 0, 0);
            break;
    }
}

uint8_t Affichage4Digits::valeursSegment(uint16_t p_valeurSegment){
    return segmentValue[p_valeurSegment % 10];   
}

void Affichage4Digits::afficherBinaire(uint16_t p_valeur){
    uint8_t d1 = (p_valeur >> 3 )&1;
    uint8_t d2 = (p_valeur >> 2 )&1;
    uint8_t d3 = (p_valeur >> 1) &1;
    uint8_t d4 = p_valeur &1;

    afficher(valeursSegment(d1),valeursSegment(d2), valeursSegment(d3), valeursSegment(d4));
}

void Affichage4Digits::afficherDecimal(uint16_t p_valeurAAfficher){
    uint8_t d1 = valeursSegment(p_valeurAAfficher / 1000);
    uint8_t d2 = valeursSegment((p_valeurAAfficher % 1000) / 100);
    uint8_t d3 = valeursSegment((p_valeurAAfficher % 100) / 10);
    uint8_t d4 = valeursSegment(p_valeurAAfficher % 10);

    afficher(d1, d2, d3, d4);
}