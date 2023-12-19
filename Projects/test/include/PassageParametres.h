#pragma once
#include "Flasher.h"

void passageParametres1(int p_v1, int &p_r1, int *p_p1);
void passageParametres2(int *&p_v1, int **p_v2);
void passageParametresCopie(const Flasher p_flasher);
void passageParametresReference(Flasher &p_flasher);
void passageParametresPointeur(Flasher *p_flasher);