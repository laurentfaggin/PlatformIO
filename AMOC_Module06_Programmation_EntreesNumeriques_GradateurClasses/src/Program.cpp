#include <Arduino.h>
#include "Program.h"
#include "ActionModifierIntensiteDEL.h"
#include "DEL.h"

long derniereDateChangement1 = 0;
int dernierEtatBouton1 = HIGH;
int dernierEtatStableBouton1 = HIGH;
const int delaiMinPression = 25;
int etatBouton = 0;


Action* action1;
DEL* del1;
Program::Program()
{
    Serial.begin(9600);
    del1 = new DEL(9);
    action1 = new ActionModifierIntensiteDEL(del1);
    m_bouton1 = new Bouton(2, action1);
    pinMode(m_bouton1->getPin(), INPUT);
}

void Program::loop()
{
    etatBouton = digitalRead(m_bouton1->getPin());
    long dateActuelle = millis();

    if (etatBouton != dernierEtatBouton1) {
        derniereDateChangement1 = dateActuelle;
        dernierEtatBouton1 = etatBouton;
    }

    if(dateActuelle - derniereDateChangement1 > delaiMinPression) {
        if (dernierEtatStableBouton1 == HIGH && etatBouton == LOW) {    
                m_bouton1->tick();           
        } 
        dernierEtatStableBouton1 = etatBouton;
    }
}