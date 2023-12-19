#include "LCD1602.h"

LCD1602::LCD1602(LCD1602Proxy* p_proxy){
    m_proxy = p_proxy;
}

void LCD1602::definirPositioncurseur(int p_colonne, int p_ligne) const{
    m_proxy->definirPositionCurseur(p_colonne, p_ligne);
}

void LCD1602::afficher(const String & p_texte) const {
    m_proxy->afficher(p_texte);
}

void LCD1602::effacer() const{
    m_proxy->effacer();
}