#include "MessageRoutier.h"


MessageRoutier::MessageRoutier(LCD1602* p_lcd){
    m_lcd = p_lcd;
}

void MessageRoutier::setup(){
    m_lcd->effacer();
    //int index = EEPROM.read(m_indexMessage);
    affichageRandom();
}

void MessageRoutier::affichageRandom(){
    
}