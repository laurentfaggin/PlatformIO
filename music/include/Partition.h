#pragma once
#include "ListeGen.h"
#include "Note.h"

class Partition{
public:
    Partition(int pin);
    void lirePartition();
    void remplirPartition(Note* p_note);
private:
    Liste<Note*> m_partition;
    int m_pin;
};

