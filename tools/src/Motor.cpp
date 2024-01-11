#include "Motor.h"

Motor::Motor(int p_pinEnable, int p_pin1, int p_pin2): 
    pinEnable(p_pinEnable), 
    pinIN1(p_pin1), 
    pinIN2(p_pin2) 
    {
        pinMode(pinEnable, OUTPUT);
        pinMode(pinIN1, OUTPUT);
        pinMode(pinIN2, OUTPUT);
        arreter();
    }

void Motor::avancer(int vitesse) {
    digitalWrite(pinIN1, HIGH);
    digitalWrite(pinIN2, LOW);
    analogWrite(pinEnable, vitesse);
}

void Motor::reculer(int vitesse) {
    digitalWrite(pinIN1, LOW);
    digitalWrite(pinIN2, HIGH);
    analogWrite(pinEnable, vitesse);
}

void Motor::arreter() {
    digitalWrite(pinIN1, LOW);
    digitalWrite(pinIN2, LOW);
    analogWrite(pinEnable, 0);
}

void Motor::tournerADroite(int vitesse) {
    digitalWrite(pinIN1, HIGH);
    digitalWrite(pinIN2, HIGH);
    analogWrite(pinEnable, vitesse);
}

void Motor::tournerAGauche(int vitesse) {
    digitalWrite(pinIN1, HIGH);
    digitalWrite(pinIN2, HIGH);
    analogWrite(pinEnable, vitesse);
}

void Motor::demiTour(int vitesse) {
    digitalWrite(pinIN1, HIGH);
    digitalWrite(pinIN2, HIGH);
    analogWrite(pinEnable, vitesse);
    delay(500);  
    arreter();
}