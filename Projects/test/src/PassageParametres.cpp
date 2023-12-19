#include <Arduino.h>
#include "PassageParametres.h"

void passageParametres1(int p_v1, int &p_r1, int *p_p1){
    Serial.println("int p_v1 (int * : 0x" + String((uint16_t)(p_v1), HEX) + ") = " + String(p_v1));
    Serial.println("int &p_r1 (int * 0x" + String((uint16_t)(&p_r1), HEX) + ") = " + String(p_r1));
    Serial.println("int *p_p1 (int *p_p1 (int ** : 0x" + String((uint16_t)(*p_p1), HEX) + ") adresse: 0x" + String((uint16_t)p_p1, HEX) + " = " + String(*p_p1));
}

void passageParametres2(int *&p_v1, int **p_v2){
    Serial.print("Avant l'appel : ");
    Serial.println("p_v1 (pointeur : 0x" + String((uint16_t)(p_v1), HEX) + ") = " + String(*p_v1));
    Serial.println("&p_v2 (pointeur de pointeur : 0x" + String((uint16_t)(**p_v2), HEX) + ") = 0x" + String((uint16_t)p_v2, HEX) + " = " + String(**p_v2));

    p_v1 = new int(42);

    *p_v2 = new int(100);

    Serial.print("Pendant l'appel : ");
    Serial.println("p_v1 (pointeur : 0x" + String((uint16_t)(p_v1), HEX) + ") = " + String(*p_v1));
    Serial.println("&p_v2 (pointeur de pointeur : 0x" + String((uint16_t)(**p_v2), HEX) + ") = 0x" + String((uint16_t)p_v2, HEX) + " = " + String(**p_v2));
}

void passageParametresCopie(const Flasher p_flasher){
    Serial.println("passage flasher par copie");
    Serial.println("flasher parametre adresse: 0x" + String((uint16_t)(&p_flasher), HEX));
    Flasher f(p_flasher);   
    Serial.println("flasher copie adresse: 0x" + String((uint16_t)(&f), HEX));   
}

void passageParametresReference(Flasher &p_flasher){
    Serial.println("passage flasher par reference");
    Serial.println("flasher parametre adresse: 0x" + String((uint16_t)(&p_flasher), HEX));
}

void passageParametresPointeur(Flasher *p_flasher){
    Serial.println("passage flasher par pointeur");
    Serial.println("flasher parametre adresse: 0x" + String((uint16_t)p_flasher, HEX));
}