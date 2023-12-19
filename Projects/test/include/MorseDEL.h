#pragma once
#include "MorseDEL.h"
#include "Morse.h"

class MorseDEL: public Morse{
public:
    MorseDEL(int p_dureePoint);
    void afficherPoint() const override;
    void afficherTrait() const override;
    void afficherMonTexte(String p_texteAAfficher) const override;
};