#include <Arduino.h>
#include "ActionModifierIntensiteDEL.h"

ActionModifierIntensiteDEL::ActionModifierIntensiteDEL(DEL* p_del):
    m_del(p_del),
    m_pourcentageIntensite(0),
    m_pas(25)
{
    m_del->allumer();
}

void ActionModifierIntensiteDEL::executer()
{
    m_pourcentageIntensite += m_pas;
    if(m_pourcentageIntensite < 0){
        m_pourcentageIntensite = 25;
        setPas();
    }
    else if(m_pourcentageIntensite > 100){
        m_pourcentageIntensite = 75;
        setPas();
    }    
    m_del->allumer(m_pourcentageIntensite);    
}

void ActionModifierIntensiteDEL::setPas(){
    m_pas = -m_pas;
}