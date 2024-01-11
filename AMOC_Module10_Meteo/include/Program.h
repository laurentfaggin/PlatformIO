#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "LCD1602.h"
#include "LCD1602ProxyI2C.h"

class Program{
    public:
        Program();
        void Afficher(const String p_texte) const;
        void loop();
    private:
        LCD1602* m_LCD;
};