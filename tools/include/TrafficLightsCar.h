#pragma once
#include <Arduino.h>
#include "DEL.h"

class TrafficLightsCar{
    public:
        TrafficLightsCar(DEL* p_vert, DEL* p_orange, DEL* p_rouge);
        void setCompteurFeuVoiture(int p_compteur);
        int getCompteurFeuVoiture() const;
        void allumerRougeVoiture();
        void allumerJauneVoiture();
        void allumerVertVoiture();
    private:
        DEL* m_rouge;
        DEL* m_orange;
        DEL* m_vert;
        int m_compteur;
};