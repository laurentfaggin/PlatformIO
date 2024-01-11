#include <Arduino.h>

class Motor {
public:
    Motor(int brocheEnable, int brocheIN1, int brocheIN2);
    void avancer(int vitesse);
    void reculer(int vitesse);
    void arreter();
    void tournerADroite(int vitesse);
    void tournerAGauche(int vitesse);
    void demiTour(int vitesse);

private:
    int pinEnable;
    int pinIN1;
    int pinIN2;
};