#include <Arduino.h>
#include "DetecteurDistance.h"

const int borneTrigger = 10;
const int borneEcho = 8;
long duree, cm, pouces;
int distance;

DetecteurDistance* detecteur;

void Potentiometre(){
  pinMode(A0, INPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);

  //analogWrite(A0, 127);
  analogWrite(A1, 127);
  analogWrite(A2, 127);
  analogWrite(A3, 127);
  analogWrite(A4, 127);
  analogWrite(A5, 127);
}

void LirePotentiometre(){
  Serial.println(analogRead(A0));
  delay(1000);
}

void setup() {
  Serial.begin(9600);
  Serial.println("demarrage de la console");
  pinMode(borneTrigger, OUTPUT);
  pinMode(borneEcho, INPUT);
  detecteur = new DetecteurDistance(borneTrigger, borneEcho);
}

void loop() {
  int duree = detecteur->ObtenirDistance();

  double distanceCm = duree/2 /29;
  double distancePouces = (duree/2 /29)*0.39;

  Serial.print(distanceCm);
  Serial.println( " cm de distance");
  
  Serial.print(distancePouces);
  Serial.println(" inch de distance");
  delay(1000);
}

