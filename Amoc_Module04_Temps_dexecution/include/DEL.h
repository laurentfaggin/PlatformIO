#pragma once

class DEL{
public:
    DEL(int p_pin, float p_rapportCycle);
    void allumer();
    void eteindre();
    void setRapportCycle(float p_rapportCycle);
    float getRapportCycle();

private:
    int m_pin;
    float m_rapportCycle;
};