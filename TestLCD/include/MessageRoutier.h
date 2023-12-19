#include <Arduino.h>
#include <EEPROM.h>
#include <LiquidCrystal_I2C.h>
#include "LCD1602.h"

class MessageRoutier {
    public:
        MessageRoutier(LCD1602* p_lcd);
        void affichageRandom();
        void setup();
        void loop();
    private:
        LCD1602* m_lcd;
        uint8_t m_indexMessage;
        uint16_t m_indexAdresse = 0;
        uint16_t m_adressePremierMessage = 16;

        const char* m_messages[6] = {
            "trop vite",
            "trop lent",
            "vent",
            "pluie",
            "neige",
            "soleil"
        };
};