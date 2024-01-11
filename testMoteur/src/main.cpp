#include <Arduino.h>

// Définir les broches pour le module L298N
const int ENA = 12;  // Broche de vitesse pour le moteur 1
const int IN1 = 14;  // Broche d'entrée 1 pour le moteur 1
const int IN2 = 27;  // Broche d'entrée 2 pour le moteur 1
const int ENB = 13;  // Broche de vitesse pour le moteur 2
const int IN3 = 26;  // Broche d'entrée 1 pour le moteur 2
const int IN4 = 25;  // Broche d'entrée 2 pour le moteur 2

void setup() {
   // Initialiser les broches de contrôle du moteur en tant que sortie
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Définir la vitesse initiale des moteurs
  analogWrite(ENA, 255);  // Vitesse maximale pour le moteur 1
  analogWrite(ENB, 255);  // Vitesse maximale pour le moteur 2
}

void loop() {
  // Faire tourner les moteurs dans un sens pendant 2 secondes
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(2000);

  // Arrêter les moteurs pendant 1 seconde
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(1000);

  // Faire tourner les moteurs dans l'autre sens pendant 2 secondes
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(2000);

  // Arrêter les moteurs pendant 1 seconde
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(1000);
}
