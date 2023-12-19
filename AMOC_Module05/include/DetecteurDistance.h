#pragma once

class DetecteurDistance{
    private:
    int m_pintrigger;
    int m_pinEcho;
    int danger = 4;
    int securitaire = 8;
    int collision = 0;

    public:
    DetecteurDistance(int p_pintrigger, int p_pinEcho);
    double ObtenirDistance();
    void DetectionObstacle(int p_pinVerte, int p_pinJaune, int p_pinRouge, int distance);
};