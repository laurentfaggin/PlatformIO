#include <Arduino.h>
#include "Configuration.h"
#include "Note.h"
#include "Partition.h"
#include "ClubbedToDeath.h"

  Partition* rocky;
  Partition* matrix;
void setup() {
  rocky = new Partition(9);
  
  Serial.begin(9600);
  rocky->remplirPartition(new Note("do", do, 1000));
  rocky->remplirPartition(new Note("re", re, 1000));
  rocky->remplirPartition(new Note("mi", mi, 2000));
  rocky->remplirPartition(new Note("fa", fa, 1000));
  rocky->remplirPartition(new Note("sol", sol, 1000));
  rocky->remplirPartition(new Note("la", la, 2000));
  rocky->remplirPartition(new Note("si", si, 1000));
  rocky->lirePartition();
  matrix = new Partition (9);

  matrix->remplirPartition(new Note(D4, EIGHTH));
  matrix->remplirPartition(new Note(Dsharp4, EIGHTH));
  matrix->remplirPartition(new Note(F4, EIGHTH));
  matrix->remplirPartition(new Note(Dsharp4, EIGHTH));
  matrix->remplirPartition(new Note(D4, EIGHTH));
  matrix->remplirPartition(new Note(Gsharp4, QUARTER));
  matrix->remplirPartition(new Note(D4, EIGHTH));
  matrix->remplirPartition(new Note(Dsharp4, EIGHTH));
  matrix->remplirPartition(new Note(F4, EIGHTH));
  matrix->remplirPartition(new Note(Dsharp4, EIGHTH));
  matrix->remplirPartition(new Note(D4, EIGHTH));
  matrix->remplirPartition(new Note(Asharp4, QUARTER));
  matrix->remplirPartition(new Note(G4, EIGHTH));
  matrix->remplirPartition(new Note(F4, EIGHTH));
  matrix->remplirPartition(new Note(Dsharp4, EIGHTH));
  matrix->remplirPartition(new Note(F4, EIGHTH));
  matrix->remplirPartition(new Note(Dsharp4, QUARTER));
  matrix->remplirPartition(new Note(F4, EIGHTH));
  matrix->remplirPartition(new Note(G4, EIGHTH));
  matrix->remplirPartition(new Note(Gsharp4, EIGHTH));
  matrix->remplirPartition(new Note(G4, EIGHTH));
  matrix->remplirPartition(new Note(D4, EIGHTH));
  matrix->remplirPartition(new Note(Dsharp4, EIGHTH));
  matrix->remplirPartition(new Note(F4, EIGHTH));
  matrix->remplirPartition(new Note(Dsharp4, EIGHTH));
  matrix->remplirPartition(new Note(D4, EIGHTH));
  matrix->remplirPartition(new Note(Gsharp4, QUARTER));
  matrix->remplirPartition(new Note(D4, EIGHTH));
  matrix->remplirPartition(new Note(Dsharp4, EIGHTH));
  matrix->remplirPartition(new Note(F4, EIGHTH));
  matrix->remplirPartition(new Note(Dsharp4, EIGHTH));
  matrix->remplirPartition(new Note(D4, EIGHTH));
  matrix->remplirPartition(new Note(Asharp4, QUARTER));
  matrix->remplirPartition(new Note(G4, EIGHTH));
  matrix->remplirPartition(new Note(F4, EIGHTH));
  matrix->remplirPartition(new Note(Dsharp4, EIGHTH));
  matrix->remplirPartition(new Note(F4, EIGHTH));
  matrix->remplirPartition(new Note(Dsharp4, QUARTER));
  matrix->remplirPartition(new Note(F4, EIGHTH));
  matrix->remplirPartition(new Note(G4, EIGHTH));
  matrix->remplirPartition(new Note(Gsharp4, EIGHTH));
  matrix->remplirPartition(new Note(G4, EIGHTH));
  matrix->remplirPartition(new Note(D4, EIGHTH));
  matrix->remplirPartition(new Note(Dsharp4, EIGHTH));
  matrix->remplirPartition(new Note(F4, EIGHTH));
  matrix->remplirPartition(new Note(Dsharp4, EIGHTH));
  matrix->remplirPartition(new Note(D4, EIGHTH));
  matrix->remplirPartition(new Note(Gsharp4, QUARTER));
  matrix->remplirPartition(new Note(D4, EIGHTH));
  matrix->remplirPartition(new Note(Dsharp4, EIGHTH));
  matrix->remplirPartition(new Note(F4, EIGHTH));
  matrix->remplirPartition(new Note(Dsharp4, EIGHTH));
  matrix->remplirPartition(new Note(D4, EIGHTH));
  matrix->remplirPartition(new Note(Gsharp4, QUARTER));
  matrix->remplirPartition(new Note(Asharp4, EIGHTH));
  matrix->remplirPartition(new Note(Dsharp4, EIGHTH));
  matrix->remplirPartition(new Note(F4, EIGHTH));
  matrix->remplirPartition(new Note(Gsharp4, EIGHTH));
  matrix->remplirPartition(new Note(G4, EIGHTH));
  matrix->remplirPartition(new Note(F4, EIGHTH));
  matrix->remplirPartition(new Note(Dsharp4, EIGHTH));
  matrix->remplirPartition(new Note(D4, EIGHTH));
  matrix->remplirPartition(new Note(Gsharp4, QUARTER));
  matrix->remplirPartition(new Note(G4, EIGHTH));
  matrix->remplirPartition(new Note(Dsharp4, EIGHTH));
  matrix->remplirPartition(new Note(F4, EIGHTH));
  matrix->remplirPartition(new Note(G4, EIGHTH));
  matrix->remplirPartition(new Note(F4, EIGHTH));
  matrix->remplirPartition(new Note(Dsharp4, EIGHTH));
  matrix->remplirPartition(new Note(Gsharp4, QUARTER));
  matrix->remplirPartition(new Note(G4, EIGHTH));
  matrix->remplirPartition(new Note(Dsharp4, EIGHTH));
  matrix->remplirPartition(new Note(F4, EIGHTH));
  matrix->remplirPartition(new Note(G4, EIGHTH));
  matrix->remplirPartition(new Note(F4, EIGHTH));
  matrix->remplirPartition(new Note(Dsharp4, EIGHTH));
  matrix->remplirPartition(new Note(F4, QUARTER));
  matrix->remplirPartition(new Note(G4, EIGHTH));
  matrix->remplirPartition(new Note(Gsharp4, EIGHTH));
  matrix->remplirPartition(new Note(G4, EIGHTH));
  matrix->remplirPartition(new Note(D4, EIGHTH));
  matrix->remplirPartition(new Note(Dsharp4, EIGHTH));
  matrix->remplirPartition(new Note(F4, EIGHTH));
  matrix->remplirPartition(new Note(Dsharp4, EIGHTH));
  matrix->remplirPartition(new Note(D4, EIGHTH));
  matrix->remplirPartition(new Note(Gsharp4, QUARTER));
  matrix->remplirPartition(new Note(G4, EIGHTH));
  matrix->remplirPartition(new Note(Dsharp4, EIGHTH));
  matrix->remplirPartition(new Note(F4, EIGHTH));
  matrix->remplirPartition(new Note(G4, EIGHTH));
  matrix->remplirPartition(new Note(F4, EIGHTH));
  matrix->remplirPartition(new Note(Dsharp4, EIGHTH));
  matrix->remplirPartition(new Note(Gsharp4, QUARTER));
  matrix->remplirPartition(new Note(G4, EIGHTH));
  matrix->remplirPartition(new Note(Dsharp4, EIGHTH));
  matrix->remplirPartition(new Note(F4, EIGHTH));
  matrix->remplirPartition(new Note(G4, EIGHTH));
  matrix->remplirPartition(new Note(F4, EIGHTH));
  matrix->remplirPartition(new Note(Dsharp4, EIGHTH));
  matrix->remplirPartition(new Note(A4, QUARTER));
  matrix->lirePartition();
}

void loop() {
    //rocky->lirePartition();
  matrix->lirePartition();
  // put your main code here, to run repeatedly:
}