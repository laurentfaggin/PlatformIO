#include <Arduino.h>
#include "Program.h"

Program * program;
void setup() {
  program = new Program(2,3);
}

void loop() {
  program->loop();
}

