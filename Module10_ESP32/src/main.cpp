#include <Arduino.h>
#include <WiFi.h>
#include <LiquidCrystal_I2C.h>
#include "Connection.h"
#include "LCD1602ProxyI2C.h"

#define WIFI_SSID "iot_lab"
#define WIFI_PASSWORD "engagelejeuquejelegagne"

Connection* connection;
LCD1602ProxyI2C* lcd;

void setup() {
    Serial.begin(115200);
    connection = new Connection(WIFI_SSID, WIFI_PASSWORD);
    lcd = new LCD1602ProxyI2C();
    String url = "https://ifconfig.co/json";
    if (connection->wiFiConnected()) {
        String ipAddress = "WiFi Connecte IP: " + connection->getLocalIP();
        lcd->definirPositionCurseur(0,0);
        lcd->afficher(ipAddress);       
       
        String ipPublique = connection->getPublicIP(url);
        Serial.print("Adresse IP publique : ");
        Serial.println(ipPublique);
    } else {
        Serial.println("Connexion échouée");
    }
    
}


void loop() {

}
