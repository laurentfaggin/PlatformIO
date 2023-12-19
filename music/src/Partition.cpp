#include "Configuration.h"
#include "Partition.h"

Partition::Partition(int pin): 
    m_pin(pin)
{
    pinMode(m_pin, OUTPUT);
}

void Partition::remplirPartition(Note* p_note){
    this->m_partition.ajouterFin(p_note);
}

void Partition::lirePartition(){
    for(int i = 0; i < m_partition.nombreDElement(); ++i){
        this->m_partition.obtenir(i)->lireNote(m_pin);
        Serial.println(m_partition.obtenir(i)->getNom());
    }
}