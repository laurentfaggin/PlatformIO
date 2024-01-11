#include <ArduinoJson.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <limits.h>
#include "config.h"
#include "Connection.h"
#include "Program.h"


Connection* connection;
LCD1602ProxyI2C* lcd;
Program* program;

void setup() {
  Serial.begin(115200);
  program = new Program();
  connection = new Connection(WIFI_SSID_HOME, WIFI_PASSWORD_HOME);
  lcd = new LCD1602ProxyI2C();
  String url = "https://api.open-meteo.com/v1/forecast?latitude=45.5017&longitude=-73.5672&hourly=temperature_2m";   
  
  float minTemp = 0.0;
  float maxTemp = 0.0;
  float sumMinTemp = 0.0;

  float sumMaxTemp = 0.0;
  int compteurMin = 0;
  int compteurMax = 0;

  if (connection->wiFiConnected()) {
    String result = connection->getJson(url); 
    DynamicJsonDocument doc(4096);  
    Serial.print(result);
    deserializeJson(doc, result); 
    JsonObject hourly = doc["hourly"];
    JsonArray temperature_2m = hourly["temperature_2m"];

   
    for (const auto &temp : temperature_2m) {
      float tempValue = temp.as<float>();

      if (tempValue < minTemp) {
        minTemp = tempValue;
      }

      if (tempValue > maxTemp) {
        maxTemp = tempValue;
      }

      sumMinTemp += tempValue;
      sumMaxTemp += tempValue;

      compteurMin++;
      compteurMax++;
    }

    float avgMinTemp = sumMinTemp / compteurMin;
    float avgMaxTemp = sumMaxTemp / compteurMax;

    lcd->effacer();
    lcd->definirPositionCurseur(0,0);
    lcd->afficher("Temp Min: " + String( minTemp, 1) + "C");
    Serial.print("temp min: ");
    Serial.println(minTemp);

    lcd->definirPositionCurseur(0,1);
    lcd->afficher("Temp Max: " + String(maxTemp, 1) + "C");
    Serial.print("temp max: ");
    Serial.println(maxTemp);
    delay(5000);
  } 
  else {
      Serial.println("Connexion échouée");
  }
}

void loop() {
  //program->Afficher("essai avec un texte dont la taille est superieure a 32 caracteres!");
}