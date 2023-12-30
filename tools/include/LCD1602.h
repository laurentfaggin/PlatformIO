#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "LCD1602Proxy.h"

class LCD1602{
    public:
        LCD1602(LCD1602Proxy* p_proxy);
        void definirPositioncurseur(int p_colonne, int p_ligne) const;
        void afficher(const String & p_texte) const;
        void effacer() const;
    private:
        LCD1602Proxy* m_proxy;
};