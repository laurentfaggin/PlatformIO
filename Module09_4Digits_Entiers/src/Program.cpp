#include "Program.h"

Program::Program(int p_pinHorloge, int p_pinDonnees){
    m_affichage = new Affichage4Digits(new Affichage4DigitsProxyTM1637(p_pinHorloge, p_pinDonnees));
}

void Program::loop(){
     //afficher la valeur "1010" et validez que cela fonctionne
    m_affichage->afficherBinaire(0b1001);
    delay(1000);
    m_affichage->afficherDecimal(2572);
    delay(1000);
    m_affichage->afficherEntier(1234);
   

    // //Écrivez un programme principal qui compte en binaire de 
    // //"0000" (0 en décimal) à "1111" (15 en décimal) 
    // //et qui affiche le résultat sur le 4 digits 
    // //(attendre 1 seconde entre chaque incrément)
    // for(int i = 0; i <= 15; ++i){
    //     m_affichage->afficherBinaire(i);
    //     delay(1000);
    // }

    // //Écrivez un programme principal qui compte en binaire de "0000" à "9999" 
    // //et qui affiche le résultat sur le 4 digits 
    // //(attendre 100 millisecondes entre chaque incrément)
    // for (int i = 0; i <= 9999; ++i){
    //     m_affichage->afficherDecimal(i);
    //     delay(100);
    // }
}