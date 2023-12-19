#include <Arduino.h>
#include "MorseSerie.h"
#include "Morse.h"

MorseSerie::MorseSerie()
{ ; }

void MorseSerie::afficherPoint() const
{
    Serial.print(".");
}

void MorseSerie::afficherTrait() const
{
    Serial.print("-");
}

void MorseSerie::afficherMonTexte(String p_texteAEmettre) const
{
    char* lettres[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",   // A-I
        ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R 
        "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."         // S-Z
    };

    char* nombres[] = {
        "-----", ".----", "..---", "...--", "....-", ".....",   //0-5
        "-....", "--...", "---..", "----."                      //6-9 
    };

    int capacite = p_texteAEmettre.length() + 1;
    char texteConvertiChar[capacite];
    p_texteAEmettre.toCharArray(texteConvertiChar, capacite);

    for (size_t i = 0; i < capacite - 1; ++i){
        char caractere = texteConvertiChar[i];
        if (isalpha(caractere))
        {
            int index = toupper(caractere) - 'A';
            Serial.print(lettres[index]);
            Serial.print(" ");
        }
        else if(isDigit(caractere))
        {
            int index = caractere - '0';
            Serial.print(nombres[index]);
            Serial.print(" ");
        }
        else if(caractere == ' ')
        {
            Serial.print(" ");
        }
    }
}