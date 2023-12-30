#pragma once
#include <Arduino.h>
#include "DEL.h"

class TrafficLightsPesdestrian{
    public:
        TrafficLightsPesdestrian(DEL* p_vert, DEL* p_rouge);
        void setCompteurFeuVoiture(int p_compteur);
        int getCompteurFeuVoiture() const;
        void allumerRougePieton();
        void allumerVertPieton();
    private:
        DEL* m_vert;
        DEL* m_rouge;
        int m_compteur;
};