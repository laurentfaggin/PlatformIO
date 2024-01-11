#include "Program.h"

LCD1602ProxyI2C * proxy;


Program::Program(){
    proxy = new LCD1602ProxyI2C();
}

void Program::Afficher(const String p_texte) const{
    proxy->afficher(p_texte);
}

void Program::loop(){

}