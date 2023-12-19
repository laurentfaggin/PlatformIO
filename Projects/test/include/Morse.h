#pragma once
#include <Arduino.h>

class Morse{
public:
    Morse();
    Morse(int p_dureePoint);
    virtual void afficherPoint() const = 0;
    virtual void afficherTrait() const = 0;
    virtual void afficherMonTexte(String p_texteAAfficher) const = 0;
    void afficherSOS() const;
    int getDureePoint() const;
private:
    int m_dureePoint;
};