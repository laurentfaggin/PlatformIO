#pragma once
#include <Arduino.h>
#include <EEPROM.h>

template<typename Type>
class DonneesASauvegarder{
    public:
        DonneesASauvegarder(byte p_adresse, Type p_data):
            m_adresse(p_adresse),
            m_donnees(p_data)
        {
        };

        void ecrireDonnees(const Type &p_das){
            EEPROM.put(m_adresse, p_das);
        };

        void lireDonnees(Type &p_das){
            EEPROM.get(m_adresse, p_das);
        };

        void setDonnee(const Type &p_das){
            m_donnees = p_das;
        };
       
    private:
        byte m_adresse;
        Type m_donnees;
};
