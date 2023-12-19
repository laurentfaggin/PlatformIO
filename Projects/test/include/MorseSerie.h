#pragma once
#include "Morse.h"

class MorseSerie : public Morse{
public:
    MorseSerie();
    void afficherPoint() const override;
    void afficherTrait() const override;
    void afficherMonTexte(String p_texteAEmettre) const override;
};

