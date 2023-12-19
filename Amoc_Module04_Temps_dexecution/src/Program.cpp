#include <Arduino.h>
#include "Program.h"
#include "DELClignotante.h"

Program::Program():
    m_DelClignotante1(10, 50, 500, 500),
    m_delclignotante2(11, 60, 600, 600)
{
    ;
}

void Program::loop(){
    m_DelClignotante1.tick();
    m_delclignotante2.tick();
}

