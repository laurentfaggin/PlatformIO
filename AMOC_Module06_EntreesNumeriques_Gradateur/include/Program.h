#pragma once
#include <Arduino.h>
#include "Bouton.h"

class Program{
public:
    Program();
    void loop();
private:
    Bouton* m_bouton1;
    Bouton* m_bouton2;
};