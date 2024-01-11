#include "LCD1602ProxyI2C.h"

LCD1602ProxyI2C::LCD1602ProxyI2C(){
    m_lcd = new LiquidCrystal_I2C(0x27, 16, 2);
    m_lcd->init();
    m_lcd->backlight();
    m_lcd->setCursor(0,0);
}

void LCD1602ProxyI2C::definirPositionCurseur(int p_colonne, int p_ligne) const{
    m_lcd->setCursor(p_colonne, p_ligne);
}

void LCD1602ProxyI2C::afficher(const String & p_texte) const{
    effacer();
    if(p_texte.length() > 32){
        for (int i = 0; i < p_texte.length() - 15; ++i) {
            definirPositionCurseur(0, 1);
            m_lcd->print(p_texte.substring(i + 16, i + 32));
            delay(200);
            definirPositionCurseur(0, 0);
            m_lcd->print(p_texte.substring(i, i + 16));
            delay(200);
        }
    }      
    else if (p_texte.length() > 16) {
        for (int i = 0; i < p_texte.length(); ++i) {
            if (i < 16) {
                definirPositionCurseur(i, 0);
            } else {
                definirPositionCurseur(i - 16, 1);
            }
            m_lcd->print(p_texte[i]);
        }
    }
    else {
        m_lcd->print(p_texte);
    }
}

void LCD1602ProxyI2C::effacer() const{
    m_lcd->clear();
}
