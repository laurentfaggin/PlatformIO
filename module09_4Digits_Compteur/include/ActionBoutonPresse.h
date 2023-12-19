#pragma once
#include <Arduino.h>
#include "Action.h"
#include "Affichage4Digits.h"
#include "Compteur.h"

class ActionBoutonPresse: public Action{
public:
    ActionBoutonPresse(Affichage4Digits * p_proxy, Compteur * p_compteur);
    void executer();
private:
    Affichage4Digits * m_proxy;
    Compteur * m_compteur;
};