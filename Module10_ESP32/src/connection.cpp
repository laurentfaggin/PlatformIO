#include "Connection.h"


Connection::Connection(String p_ssid, String p_password):
    m_ssid(p_ssid),
    m_password(p_password)
{
    ;
}

bool Connection::wiFiConnected(){
    Serial.println("Connexion au reseau: ");
    WiFi.begin(m_ssid, m_password);
    int essay = 0;
    while (essay < 15 && WiFi.status() != WL_CONNECTED){
        Serial.print(".");
        delay(500);
        ++essay;
    }
    if (WiFi.status() == WL_CONNECTED){
        Serial.println("Connecte au WiFi!");
        return true;
    }
    else{
        Serial.println("Connection echouee!");
        return false;
    }
}

String Connection::getPublicIP(){
    if (WiFi.status() == WL_CONNECTED){
        String url = "https://ifconfig.co.json";
        String url2 = "http://api.ipify.org/?format=json";
        HTTPClient httpClient;
        httpClient.begin(url2);
        int codeStatut = httpClient.GET();
        //la methode GET est bloquante, elle attend le retour avant de continuer le code
        if (codeStatut != 200) {
            return HTTPClient::errorToString(codeStatut);
        } else {
            return httpClient.getString();
        }
    } else {
        return "Non connecté au WiFi !";
    }      
}

String Connection::getLocalIP() {
    if (WiFi.status() == WL_CONNECTED) {
        return WiFi.localIP().toString();
    } else {
        return "Not connected to WiFi";
    }
}
