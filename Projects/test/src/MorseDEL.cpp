#include <Arduino.h>
#include "MorseDEL.h"

MorseDEL::MorseDEL(int p_dureePoint) : Morse(p_dureePoint)
{
    pinMode (LED_BUILTIN, OUTPUT);
}

void MorseDEL::afficherPoint() const
{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(getDureePoint());
    digitalWrite(LED_BUILTIN, LOW);
    delay(getDureePoint());
}

void MorseDEL::afficherTrait() const
{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(getDureePoint() * 3);
    digitalWrite(LED_BUILTIN, LOW);
    delay(getDureePoint());
}

void MorseDEL::afficherMonTexte(String p_texteAAfficher) const
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
                delay(200);
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