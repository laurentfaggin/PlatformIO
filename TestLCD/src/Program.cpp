#include "Program.h"

LCD1602ProxyI2C * proxy;


Program::Program(){
    proxy = new LCD1602ProxyI2C();
    proxy->afficher("test d'affichage sur deux lignes");
}

void Program::loop(){

}