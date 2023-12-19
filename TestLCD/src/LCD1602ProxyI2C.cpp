#include "LCD1602ProxyI2C.h"

LCD1602ProxyI2C::LCD1602ProxyI2C(){
    m_lcd->init();
    m_lcd->backlight();
    m_lcd->setCursor(0,0);
}

void LCD1602ProxyI2C::definirPositionCurseur(int p_colonne, int p_ligne) const{
    m_lcd->setCursor(p_colonne, p_ligne);
}

void LCD1602ProxyI2C::afficher(const String & p_texte) const{
    effacer();
    if (p_texte.length() > 16){
        for (int i = 0; i < 16; ++i){
            definirPositionCurseur(0,0);
            m_lcd->write(i);
        }
        for (int i = 16; i < p_texte.length(); ++i){
            definirPositionCurseur(0,1);
            m_lcd->write(i);
        }
    }
    m_lcd->print(p_texte);
}

void LCD1602ProxyI2C::effacer() const{
    m_lcd->clear();
}
