#pragma once
#include <Arduino.h>
#include "Action.h"
#include "DEL.h"

class ActionModifierIntensiteDEL: public Action{
public:
    ActionModifierIntensiteDEL(DEL* p_del);
    ActionModifierIntensiteDEL(DEL* p_del, float p_pourcentage);
    void executer();
private:
    DEL* m_del;
    float m_pourcentageIntensite;
    float m_pas;
};