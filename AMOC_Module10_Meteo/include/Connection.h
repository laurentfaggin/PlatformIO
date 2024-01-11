#include <Arduino.h>
#include <WiFi.h>
#include "HTTPClient.h"

class Connection{
    public:
        Connection(String p_ssid, String p_password);
        String getPublicIP(String url);
        String getLocalIP();
        bool wiFiConnected();
        String getJson(String url);
    private:
        String m_ssid;
        String m_password;    
};