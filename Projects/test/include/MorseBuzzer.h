#pragma once
#include <Arduino.h>
#include "Morse.h"

class MorseBuzzer: public Morse{
public:
    MorseBuzzer(int p_dureePoint);
    void afficherPoint() const override;
    void afficherTrait() const override;
    void afficherMonTexte(String p_texteAAfficher) const override;
};