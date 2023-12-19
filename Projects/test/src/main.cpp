#include <Arduino.h>
#include "GestionDELInterne.h"
#include "Configuration.h"
#include "PassageParametres.h"
#include "Flasher.h"
#include "DEL.h"
#include "Morse.h"
#include "MorseDEL.h"
#include "MorseSerie.h"
#include "MorseBuzzer.h"


void morse();

//Flasher flasher (LED_BUILTIN, 500);

void setup(){
  Serial.end();
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  int valeur1 = 42;
  int valeur2 = 13;
  int valeur3 = 40;

  Serial.println(42);
  Serial.println("Bonjour a tous");
  Serial.println(String(42, HEX));
  Serial.println("0x" + String(42,HEX));
  Serial.println("int valeur1 (int * : 0x" + String((uint16_t)(&valeur1), HEX) + ") = " + String(valeur1));
  Serial.println("int valeur2 (int * : 0x" + String((uint16_t)(&valeur2), HEX) + ") = " + String(valeur2));
  Serial.println("int valeur2 (int * : 0x" + String((uint16_t)(&valeur3), HEX) + ") = " + String(valeur3));
  
  Serial.println("Appel de passageDeParametres1(valeur1, valeur1, &valeur2);");
  passageParametres1(valeur1, valeur1, &valeur2);
  Serial.println("exercice 2.3");
  int *pointeur1 = new int(20);
  int *pointeur2 = new int(30);
  int **pointeur2_ptr = &pointeur2;
  
  passageParametres2(pointeur1, pointeur2_ptr);
  Serial.println("Valeurs après l'appel de passageParametres2 :");
  Serial.println("p_v1 (pointeur1 : 0x" + String((uint16_t)(pointeur1), HEX) + ") = " + String(*pointeur1));
  Serial.println("&p_v2 (pointeur2_ptr : 0x" + String((uint16_t)(&pointeur2_ptr), HEX) +  ") = " + String(**pointeur2_ptr));
  delete pointeur1;
  delete pointeur2;
  delete pointeur2_ptr;

  // Flasher flasherDuSetUp(LED_BUILTIN, 200);
  // flasher = flasherDuSetUp;
  // passageParametresCopie(flasher);
  // passageParametresReference(flasher);
  // passageParametresPointeur(&flasher);

  // Morse* morse = new MorseSerie();
  // morse->afficherSOS();
  // morse = new MorseDEL(200);
  // morse->afficherSOS();
}

void loop(){

  // Morse* texte = new MorseDEL(200);
  // texte->afficherMonTexte("hello world");
  // delay(1000);
  //flasher.faireClignoter(1);
  //morse();  
  // allumerDELInterne(DUREE_DEL_ALLUMEE);
  // eteindreDELInterne(DUREE_DEL_ETEINTE);
  // DEL del(1000);
  // del.allumer();
  // del.eteindre();
  
}

void lettreS(){
  for (size_t i = 0; i < 3; ++i){
    allumerDELInterne(200);
    eteindreDELInterne(200);
  }
  delay(200);
}

void lettreO(){
   for (size_t i = 0; i < 3; ++i){
    allumerDELInterne(600);
    eteindreDELInterne(200);
  }
  delay(200);
}

void morse(){
  lettreS();
  lettreO();
  lettreS();
  delay(1000);
}