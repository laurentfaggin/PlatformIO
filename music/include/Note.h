#pragma once
#include "ListeGen.h"
#include "Arduino.h"

class Note{
public:
    Note();
    Note(double frequence, int delay);
    Note(String nom, double frequence, int delay);
    String getNom();
    float getFrequence();
    unsigned long getDuree();
    void lireNote(int p_pin);
private:
    String m_nom;
    double m_frequence;
    unsigned long m_delay;
};