#include "LCD1602ProxyI2C.h"

LCD1602ProxyI2C::LCD1602ProxyI2C(){
    m_lcd = new LiquidCrystal_I2C(0x27, 16, 2);
    m_lcd->init();
    m_lcd->backlight();
}

void LCD1602ProxyI2C::definirPositionCurseur(int p_colonne, int p_ligne) const{
    m_lcd->setCursor(p_colonne, p_ligne);
}

void LCD1602ProxyI2C::afficher(const String & p_texte) const{
    effacer();
    if (p_texte.length() > 16){
        for (int i = 0; i < 16; ++i){
            definirPositionCurseur(i,0);
            m_lcd->write(p_texte[i]);
        }
        for (int i = 16; i < p_texte.length(); ++i){
            definirPositionCurseur(i-17,1);
            m_lcd->write(p_texte[i]);
        }
    }
    else m_lcd->print(p_texte);    
}

void LCD1602ProxyI2C::effacer() const{
    m_lcd->clear();
}
