#include "Program.h"
Compteur * compteur;
SavedData<int>* savedData;
Bouton * bouton;
ActionBoutonPresse* action;

Program::Program(int p_pinHorloge, int p_pinDonnees)
{
    compteur = new Compteur();
    savedData = new SavedData<int>(0x0010, 0);
    m_affichage = new Affichage4Digits(new Affichage4DigitsProxyTM1637(p_pinHorloge, p_pinDonnees)); 
    action = new ActionBoutonPresse(m_affichage, compteur);
    bouton = new Bouton (4, action);
}


void Program::loop(){
    int valeurCompteur = compteur->obtenirValeur();
    savedData->lireDonnees(valeurCompteur);
    bouton->tick();
    savedData->ecrireDonnees(m_compteur->obtenirValeur());
}