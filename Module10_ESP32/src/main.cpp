#include <Arduino.h>
#include <WiFi.h>
#include <LiquidCrystal_I2C.h>
#include "Connection.h"

#define WIFI_SSID "BELL092"
#define WIFI_PASSWORD "77F597E97D7F"

Connection* connection;

void setup() {
    Serial.begin(115200);
    connection = new Connection(WIFI_SSID, WIFI_PASSWORD);
    if (connection->wiFiConnected()) {
        Serial.print("Connecté au réseau WiFi, adresse IP locale : ");
        Serial.println(connection->getLocalIP());
        Serial.println("");
        String ipPublique = connection->getPublicIP();
        Serial.print("Adresse IP publique : ");
        Serial.println(ipPublique);
    } else {
        Serial.println("Connexion échouée");
    }
}


void loop() {
}
