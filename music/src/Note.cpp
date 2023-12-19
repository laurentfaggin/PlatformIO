#include "Note.h"

Note::Note(){};

Note::Note(double frequence, int delay):
    m_frequence(frequence),
    m_delay(delay)
{
    ;
}

Note::Note(String nom, double frequence, int delay):
    m_nom(nom),
    m_frequence(frequence),
    m_delay(delay)
{
    ;
}

String Note::getNom(){
    return this->m_nom;
}

float Note::getFrequence(){
    return this->m_frequence;
}

unsigned long Note::getDuree(){
    return this->m_delay;
}

void Note::lireNote(int p_pin){
    tone(p_pin, m_frequence);
    delay(m_delay + 30);
    noTone(p_pin);
}