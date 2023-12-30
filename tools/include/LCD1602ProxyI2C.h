#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "LCD1602Proxy.h"
#include "LiquidCrystal_I2C.h"

class LCD1602ProxyI2C : public LCD1602Proxy{
    public:
        LCD1602ProxyI2C();
        void definirPositionCurseur(int p_colonne, int p_ligne) const;
        void afficher(const String & p_texte) const;
        void afficherPremiereLigne(const String p_texte) const;
        void afficherDeuxiemeLigne(const String p_texte) const;
        void effacer() const;
    private:
        LiquidCrystal_I2C* m_lcd;
};