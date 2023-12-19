#include <Arduino.h>
#include "ActionModifierIntensiteDEL.h"

ActionModifierIntensiteDEL::ActionModifierIntensiteDEL(DEL* p_del):
    m_del(p_del)
{
    ;
}

ActionModifierIntensiteDEL::ActionModifierIntensiteDEL(DEL* p_del, float p_pourcentage):
    m_del(p_del),
    m_pourcentageIntensite(p_pourcentage)
{
    ;
}

void ActionModifierIntensiteDEL::executer()
{
    m_del->allumer(m_pourcentageIntensite+=m_pas);    
}