#include <Arduino.h>
#include "ActionModifierIntensiteDEL.h"

ActionModifierIntensiteDEL::ActionModifierIntensiteDEL(DEL* p_del):
    m_del(p_del),
    m_pourcentageIntensite(m_del->getPourcentageIntensite()),
    m_pas(20)
{
    m_del->allumer();
}

void ActionModifierIntensiteDEL::executer()
{
    m_pourcentageIntensite += m_pas;
    if(m_pourcentageIntensite < 0){
        m_pourcentageIntensite = 20;
        setPas();
    }
    else if(m_pourcentageIntensite > 100){
        m_pourcentageIntensite = 80;
        setPas();
    }    
    m_del->allumer(m_pourcentageIntensite);    
}

void ActionModifierIntensiteDEL::setPas(){
    m_pas = -m_pas;
}