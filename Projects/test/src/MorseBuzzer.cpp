#include "MorseBuzzer.h"
#define BUZZER 8

MorseBuzzer::MorseBuzzer(int p_dureePoint): Morse(p_dureePoint)
{
    pinMode(BUZZER, OUTPUT);
}

void MorseBuzzer::afficherPoint() const{
    tone(BUZZER, 100);
    delay(getDureePoint());
    noTone(BUZZER);
}

void MorseBuzzer::afficherTrait() const{
    tone(BUZZER, 100);
    delay(getDureePoint() * 3);
    noTone(BUZZER);
}

void MorseBuzzer::afficherMonTexte(String p_texteAAfficher) const
{
    static char* lettres[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",   // A-I
        ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R 
        "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."         // S-Z
    };

    static char* nombres[] = {
        "-----", ".----", "..---", "...--", "....-", ".....",   //0-5
        "-....", "--...", "---..", "----."                      //6-9 
    };

    int capacite = p_texteAAfficher.length() + 1;
    char texteConvertiChar[capacite];
    p_texteAAfficher.toCharArray(texteConvertiChar, capacite);

    for (size_t i = 0; i < capacite - 1; ++i){
        char caractere = texteConvertiChar[i];
        if (isalpha(caractere))
        {
            int index = toupper(caractere) - 'A';
            String lettreMorse = lettres[index];
            for(size_t j = 0; j < lettreMorse.length(); ++j)
            {
                if(lettreMorse[j] == '.')
                {
                    afficherPoint();
                }
                else if (lettreMorse[j] == '-')
                {
                    afficherTrait();
                }
                delay(getDureePoint() * 2);
            }
            
        }
        else if(isDigit(caractere))
        {
            int index = caractere - '0';
            String lettreMorse = nombres[index];
            for(size_t j = 0; j < lettreMorse.length(); ++j)
            {
                if(lettreMorse[j] == '.')
                {
                    afficherPoint();
                }
                else if (lettreMorse[j] == '-')
                {
                    afficherTrait();
                }
                delay(getDureePoint() * 2);
            }
        }
        else if(caractere == ' ')
        {
            delay(getDureePoint() * 5);
        }
    }
}