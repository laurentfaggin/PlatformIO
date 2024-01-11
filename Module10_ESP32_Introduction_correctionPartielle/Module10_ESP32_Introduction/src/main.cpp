#include <Arduino.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <WiFi.h>

#include "config.h"

void connexionWiFi();
String obtenirIPPublique();

uint8_t nbEssais = 0;
uint8_t nbEssaisMaximum = 30;

struct StatsTemperature {
  float min;
  float max;
  float moyenne;
};

StatsTemperature temperatures();
void setup() {
  Serial.begin(115200);
  connexionWiFi();

  Serial.println(String("IP publique : ") + obtenirIPPublique());

  StatsTemperature stats = temperatures();

  Serial.println(String("Température minimale : ") + stats.min);
  Serial.println(String("Température maximale : ") + stats.max);
  Serial.println(String("Température moyenne : ") + stats.moyenne);
}

void loop() {
  // put your main code here, to run repeatedly:
}

void connexionWiFi() {
  Serial.print("Connexion : ");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (nbEssais < nbEssaisMaximum && WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    nbEssais++;
  }
  Serial.println("");
  if (WiFi.status() == WL_CONNECTED) {
    Serial.print("Connecté au réseau WiFi, adresse IP : ");
    Serial.println(WiFi.localIP());
    Serial.println("");
  }
}

String obtenirIPPublique() {
  String res = "";
  if (WiFi.status() == WL_CONNECTED) {
    String url = "https://ifconfig.co/json";
    HTTPClient httpClient;
    httpClient.begin(url);
    int codeStatut = httpClient.GET();
    if (codeStatut != 200) {
      Serial.println(HTTPClient::errorToString(codeStatut));
    } else {
      res = httpClient.getString();

      DynamicJsonDocument doc(1024);

      DeserializationError error = deserializeJson(doc, res);
      if (error) {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(error.f_str());

        return "";
      }

      String ip = doc["ip"].as<String>();

      return ip;
    }
  } else {
    Serial.println("Non connecté au WiFi !");
  }
  return res;
}

StatsTemperature temperatures() {
  StatsTemperature stats = {0, 0, 0};

  if (WiFi.status() == WL_CONNECTED) {
    String url =
        "https://api.open-meteo.com/v1/"
        "forecast?latitude=46.785462&longitude=-71.286983&hourly=temperature_"
        "2m";
    HTTPClient httpClient;
    httpClient.begin(url);
    int codeStatut = httpClient.GET();
    if (codeStatut != 200) {
      Serial.println(HTTPClient::errorToString(codeStatut));
    } else {
      String res = httpClient.getString();
      DynamicJsonDocument doc(14336);
      DeserializationError error = deserializeJson(doc, res);
      if (error) {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(error.f_str());
      } else {
        float init = doc["hourly"]["temperature_2m"][0].as<float>();
        stats.min = init;
        stats.max = init;
        stats.moyenne = 0;
        for (JsonVariant t : doc["hourly"]["temperature_2m"].as<JsonArray>()) {
          float temperature = t.as<float>();
          stats.moyenne += temperature;
          if (temperature > stats.max) {
            stats.max = temperature;
          }
          if (temperature < stats.min) {
            stats.min = temperature;
          }
        }

        if (doc["hourly"]["temperature_2m"].size() > 0) {
          stats.moyenne /= doc["hourly"]["temperature_2m"].size();
        }
      }
    }
  } else {
    Serial.println("Non connecté au WiFi !");
  }
  return stats;
}