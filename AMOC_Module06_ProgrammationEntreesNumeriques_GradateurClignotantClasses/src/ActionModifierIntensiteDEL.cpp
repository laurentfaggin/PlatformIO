#include <Arduino.h>
#include "ActionModifierIntensiteDEL.h"

ActionModifierIntensiteDEL::ActionModifierIntensiteDEL(DEL* p_del): 
    m_del(p_del),
    m_pas(25)
{

}

void ActionModifierIntensiteDEL::setPas(){
    m_pas = -m_pas;
}

void ActionModifierIntensiteDEL::executer() {
    if(m_pourcentageIntensite < 0){
        m_pourcentageIntensite = 25;
        setPas();
    }
    else if(m_pourcentageIntensite > 100){
        m_pourcentageIntensite = 75;
        setPas();
    }    
    m_del->setIntensite(m_pourcentageIntensite);
       
    m_pourcentageIntensite += m_pas;
}
