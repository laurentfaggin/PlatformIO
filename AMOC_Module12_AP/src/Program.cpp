#include <Arduino.h>
#include <WiFi.h>

#include "config.h"
#include "Program.h"

#include "ServeurWeb.h"
#include "DEL.h"

IPAddress adresseIPInterne(192, 168, 23, 1);
IPAddress passerelle(192, 168, 23, 1);
IPAddress masqueReseau(255, 255, 255, 0);

Program::Program() { 
  this->connexionReseau();

  // Configurer l'ensemble de vos actionneurs.
  // Ici je n'ai mis que des DELs et j'ai triché en utilisant que la DEL qui
  // est soudée sur l'ESP32
  // DEL(idUnique, "description", pin, allumée?)
  // La configuration des actions pourraient même être enregistrée dans un fichier json.
  // Les routes sont :
  // GET /actionneurs    -> renvoie la liste des actionneurs avec le statut
  // PUT /actionneurs/id -> permet de mettre à jour un actionneur avec la struture 
  // exemples : {"id":1,"statut":"eteint"}, {"id":1,"statut":"allume"}
  this->m_actionneurs.push_back(new DEL(1, "DEL 1", 2, false));
  this->m_actionneurs.push_back(new DEL(2, "DEL 2", 2, false));
  this->m_actionneurs.push_back(new DEL(3, "DEL 3", 2, false));
  this->m_actionneurs.push_back(new DEL(4, "DEL 4", 2, false));
  this->m_actionneurs.push_back(new DEL(5, "DEL 5", 2, false));
  this->m_actionneurs.push_back(new DEL(6, "DEL 6", 2, false));
  
  this->m_serveurWeb = new ServeurWeb(this->m_actionneurs);
}

void Program::loop() {
  this->m_serveurWeb->tick();
}

void Program::connexionReseau() {
  const uint8_t nbEssaisMaximum = 50;
  uint8_t nbEssais = 0;
  bool configReussie = WiFi.softAPConfig(adresseIPInterne, passerelle, masqueReseau);
  bool demarrageReussi = false;
  Serial.println(String("Configuration point d'acces: ") + (configReussie ? "Reussie" : "echec"));
  if (configReussie){
    demarrageReussi = WiFi.softAP(WIFI_SSID_ESP32, WIFI_PASSWORD_ESP32);
    Serial.println("Adresse IP point acces: ");
    Serial.println (WiFi.softAPIP());
  }
}

