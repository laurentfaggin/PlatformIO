#include "Connection.h"

Connection::Connection(String p_ssid, String p_password):
    m_ssid(p_ssid),
    m_password(p_password)
{
    wiFiConnected();
}

bool Connection::wiFiConnected(){
    Serial.println("Connexion au reseau: ");
    WiFi.begin(m_ssid, m_password);
    int essay = 0;
    while (essay < 30 && WiFi.status() != WL_CONNECTED){
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

String Connection::getPublicIP(String url){
    String res = "";
    if (WiFi.status() == WL_CONNECTED){
        
        HTTPClient httpClient;
        httpClient.begin(url);
        int codeStatut = httpClient.GET();
        //la methode GET est bloquante, elle attend le retour avant de continuer le code
        if (codeStatut != 200) {
            res = HTTPClient::errorToString(codeStatut);
        } else {
            res = httpClient.getString();
        }
    } else {
        res = "Non connecté au WiFi !";
    }    
    return res;  
}

String Connection::getLocalIP() {
    if (WiFi.status() == WL_CONNECTED) {
        return WiFi.localIP().toString();
    } else {
        return "Not connected to WiFi";
    }
}

String Connection::getJson(String url){
    String res = "";
    if (WiFi.status() == WL_CONNECTED){
        HTTPClient http;
        http.begin(url);
        int codeStatut = http.GET();
        if(codeStatut != 200){
            res = HTTPClient::errorToString(codeStatut);
        }
        else{
            res = http.getString();
        }
    }
    else {
        res = "Non connecté au WiFi !";
    }    
    return res; 
}
