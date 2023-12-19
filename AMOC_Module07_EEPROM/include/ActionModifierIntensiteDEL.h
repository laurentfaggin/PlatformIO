#pragma once
#include <Arduino.h>
#include "Action.h"
#include "DEL.h"

class ActionModifierIntensiteDEL: public Action{
public:
    ActionModifierIntensiteDEL(DEL* p_del);
    void executer();
    void setPas();
private:
    DEL* m_del;
    int m_pourcentageIntensite;
    float m_pas;
};