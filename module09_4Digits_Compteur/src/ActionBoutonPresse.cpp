#include <Arduino.h>
#include "ActionBoutonPresse.h"

ActionBoutonPresse::ActionBoutonPresse(Affichage4Digits * p_proxy, Compteur * p_compteur):
    m_proxy(p_proxy),
    m_compteur(p_compteur)
{
    ;
}

void ActionBoutonPresse::executer()
{
      m_compteur->incrementer();
      m_proxy->afficherDecimal(m_compteur->obtenirValeur());
}
