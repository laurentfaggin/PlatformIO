#pragma once

class Flasher{
private:
    int m_pinDEL;
    int m_dureeAllumeeEteinte;
public:
    Flasher(int p_pinDEL, int p_dureeAllumeeEteinte);
    void faireClignoter(int p_nombreCycles);

    Flasher(const Flasher& p_aCopier);
    Flasher& operator=(const Flasher& p_source);
};