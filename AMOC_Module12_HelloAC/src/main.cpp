#include <Arduino.h>
#include <WebServer.h>

//question 1: Quel protocole fournit une adresse du réseau 192.168.4.0/24 au cellulaire?
// DHCP

//question 2: Quelles sont les adresses possibles pour les stations se connectant à ce point d'accès ?
//192.168.23.2 a 192.168.23.254

//Combien cela fait-il de stations potentielles ?
//253 adresses possibles

IPAddress adresseIPInterne(192, 168, 23, 1);
IPAddress passerelle(192, 168, 23, 1);
IPAddress masqueReseau(255, 255, 255, 0);
WebServer serveurWeb(80);
char const* SSID = "ESP32AP2292860";
char const* motPasse = "12345678";
bool erreur = false;

void setup() {
  Serial.begin(115200);

  bool configReussie =
      WiFi.softAPConfig(adresseIPInterne, passerelle, masqueReseau);
  bool demarrageAPReussi = false;
  Serial.println(String("Configuration réseau du point d'accès : ") +
               (configReussie ? "Réussie" : "Échec !"));

  if (configReussie) {
    demarrageAPReussi = WiFi.softAP(SSID, motPasse);
    Serial.println(String("Démarrage du point d'accès : ") +
                 (demarrageAPReussi ? "Réussi" : "Échec !"));

    if (demarrageAPReussi) {
      Serial.print("Adresse IP du point d'accès : ");
      Serial.println(WiFi.softAPIP());

      serveurWeb.on("/", []() {
        serveurWeb.send(200, "text/plain", "Bienvenue sur le point d'accès de mon reseau !");
      });

      serveurWeb.begin();
    }
  }

  erreur = !(configReussie && demarrageAPReussi);
}

void loop() {
  if (!erreur) {
    serveurWeb.handleClient();
  }
}