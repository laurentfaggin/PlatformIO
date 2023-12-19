#pragma once
#include <Arduino.h>
#include "Action.h"
#include "DEL.h"

class ActionModifierIntensiteDEL: public Action{
public:
    ActionModifierIntensiteDEL(DEL* p_del);
    void executer() override;
    void setPas();
private:
    DEL* m_del;
    float m_pourcentageIntensite;
    float m_pas;
};