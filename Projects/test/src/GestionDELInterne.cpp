#include "GestionDELInterne.h"
#include <Arduino.h>

void allumerDELInterne (int p_duree){
  digitalWrite (LED_BUILTIN, HIGH);
  delay(p_duree);
}

void eteindreDELInterne (int p_duree){
  digitalWrite (LED_BUILTIN, LOW);
  delay(p_duree);  
  }