#include <Arduino.h>
#include <WiFi.h>
#include "HTTPClient.h"

class Connection{
    public:
        Connection(String p_ssid, String p_password);
        String getPublicIP();
        String getLocalIP();
        bool wiFiConnected();
    private:
        String m_ssid;
        String m_password;    
};