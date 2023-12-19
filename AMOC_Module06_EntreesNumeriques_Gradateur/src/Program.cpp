#include <Arduino.h>
#include "Program.h"
#include "ActionModifierIntensiteDEL.h"
#include "DEL.h"

Program::Program():
    m_bouton1(new Bouton(2, new ActionModifierIntensiteDEL(new DEL(9)))),
    m_bouton2(new Bouton(4, new ActionModifierIntensiteDEL(new DEL(11))))
{
    ;
}

void Program::loop()
{
    m_bouton1->tick();
    m_bouton2->tick();
}