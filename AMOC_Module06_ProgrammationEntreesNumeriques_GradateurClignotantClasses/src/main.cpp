#include <Arduino.h>
#include "Action.h"
#include "ActionModifierIntensiteDEL.h"
#include "Bouton.h"
#include "DEL.h"
#include "Program.h"


Program* program;

void setup() {
    program = new Program();
}

void loop() {
    program->loop();
}