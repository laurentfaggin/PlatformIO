#include <Arduino.h>
#include "Program.h"
#include "ActionModifierIntensiteDEL.h"
#include "DEL.h"
#include "DonneesASauvegarder.h"


DonneesASauvegarder<int>* delASauvegarder;
Action* action1;
DEL* del1;
int delStatus = 0;

Program::Program()
{   
    Serial.begin(9600);
    del1 = new DEL(9);
    int intensite = 0;
    Serial.println(del1->getPourcentageIntensite());
    delASauvegarder = new DonneesASauvegarder<int>(0x512, del1->getPourcentageIntensite());
    delASauvegarder->lireDonnees(intensite);
    del1->setPourcentageintensite(intensite);
    Serial.println(del1->getPourcentageIntensite());
    action1 = new ActionModifierIntensiteDEL(del1);
    m_bouton1 = new Bouton(2, action1);
}

void Program::loop()
{
    if(delStatus != del1->getPourcentageIntensite()){
        delStatus = del1->getPourcentageIntensite();
        delASauvegarder->ecrireDonnees((int)del1->getPourcentageIntensite()); 
        int intensite =  del1->getPourcentageIntensite();     
    }
   m_bouton1->tick();      
}