#pragma once
#include <Arduino.h>
#include <CRC16.h>
#include <EEPROM.h>
#include "SaveData.h"
#include "stringUtil.h"

#define USE_COLOR_TERMINAL
#define TEXT_BLUE "\033[34m"
#define TEXT_GREEN "\033[32m"
#define TEXT_RED "\033[31m"
#define TEXT_YELLOW "\033[33m"
#define TEXT_RESET "\033[0m"
#define TEXT_BG_BLACK "\033[40m"
#define TEXT_BOLD "\033[1m"

// Organisation EEPROM :
// || signature app (2 octets) || adresse debut donnees (2 octets) || ...
// || nombre ecritures (2 octets) || crc donnees utilisateur (2 octets) ||
// donnees utilisateur (sizeof(TypeDonneesASauvegarder) octets) || ... ||
inline String padLeft(String p_texte, uint16_t p_tailleMin,
                      char p_remplissage = ' ');

template<typename TypeDataToSave>
class DataToSaveEEprom: public Savedata<TypeDataToSave> {
public:
    DataToSaveEEProm(const uint16_t& signatureApp):
        SIGNATURE_APP(signatureApp) 
    {
        ;
    }; 

    virtual bool save() override;
    virtual bool read() override;
    virtual void initIfFirstTime();
    virtual void deleteEEPROM();
    
    static void showContentEEPROM();
    static uint16_t dataSize(); 

private:
    static uint16_t addressCounterWriting(const uint16_t& addressData);
    static uint16_t addressCRCDataUser(const uint16_t& addressData);
    static uint16_t addressDataUser(const uint16_t& adresseaddressDataDonnees);

    const uint16_t SIGNATURE_APP;

    static const uint16_t ADDRESS_SIGNATURE_APP;
    static const uint16_t ADDRESS_START_DATAS;
    static const uint16_t ADDRESS_START_DATAS_INITIALIZATION;
    static const uint16_t MAX_WRITING_PER_ADDRESS; 
};

template <typename TypeDataToSave> 
    const uint16_t DataToSaveEEprom<TypeDataToSave>::ADDRESS_SIGNATURE_APP = 0;

template <typename TypeDonneesASauvegarder> 
    const uint16_t DataToSaveEEprom<TypeDonneesASauvegarder>::ADDRESS_START_DATAS = 2;

template <typename TypeDataToSave> 
    const uint16_t DataToSaveEEprom<TypeDataToSave>::ADDRESS_START_DATAS_INITIALIZATION = 4;

template <typename TypeDataToSave> 
    const uint16_t DataToSaveEEprom<TypeDataToSave>::MAX_WRITING_PER_ADDRESS = 2;


template <typename TypeDataToSave>
uint16_t DataToSaveEEprom<TypeDataToSave>::dataSize() 
{
    return sizeof(uint16_t) + sizeof(uint16_t) + sizeof(TypeDataToSave);
}

template <typename TypeDataToSave>
uint16_t DataToSaveEEprom<TypeDataToSave>::addressCounterWriting(const uint16_t& addressData) 
{
  return addressData;
}

template <typename TypeDataToSave>
uint16_t DataToSaveEEprom<TypeDataToSave>::addressCRCDataUser(const uint16_t& addressData) 
{
  return addressCounterWriting(addressData) + sizeof(uint16_t);
}

template <typename TypeDataToSave>
uint16_t DataToSaveEEprom<TypeDataToSave>::addressDataUser(const uint16_t& addressData) 
{
  return addressCRCDataUser(addressData) + sizeof(uint16_t);
}

template <typename TypeDataToSave>
bool DataToSaveEEprom<TypeDataToSave>::save() 
{
    bool success = true;
    uint16_t addressData = 0;
    uint16_t counterWriting = 0;

    this->initIfFirstTime();
    EEPROM.get(ADDRESS_START_DATAS, addressData);
    EEPROM.get(adresseCounterWriting(addressData), counterWriting);

    if (counterWriting >= MAX_WRITING_PER_ADDRESS) {
        addressData += dataSize();
        if (addressData + dataSize() > EEPROM.length()) {
            success = false;
        }
        counterWriting = 0;
        if (success) {
            EEPROM.put(ADDRESS_START_DATAS, addressData);
        }
    }

    ++counterWriting;
    if (success) {
        CRC16 crc;
        crc.add((uint8_t*)&this->datas(), sizeof(TypeDataToSave));

        EEPROM.put(addressCounterWriting(addressData), counterWriting);
        EEPROM.put(addressCRCDataUser(addressData), crc.calc());
        EEPROM.put(addressDataUser(addressData), this->datas());

        success = this->charger();
        CRC16 crc2;
        crc2.add((uint8_t*)&(this->datas()), sizeof(TypeDataToSave));
        success = crc2.calc() == crc.calc();
    }

    return success;
}

template <typename TypeDataToSave>
void DataToSaveEEprom<TypeDataToSave>::initIfFirstTime() 
{
  uint16_t signatureAppEEPROM = 0;
  EEPROM.get(ADDRESS_SIGNATURE_APP, signatureAppEEPROM);

  if (signatureAppEEPROM != this->SIGNATURE_APP) {
    this->effacerEEPROM();
    EEPROM.put(ADDRESS_SIGNATURE_APP, this->SIGNATURE_APP);
    EEPROM.put(ADDRESS_START_DATAS, ADDRESS_START_DATAS_INITIALIZATION);
  }
}

template <typename TypeDataToSave>
bool DataToSaveEEprom<TypeDataToSave>::read() 
{
  bool succes = true;
  uint16_t addressData = 0;
  uint16_t crcSave = 0;
  TypeDataToSave data;

  this->initIfFirstTime();
  EEPROM.get(ADDRESS_START_DATAS, addressData);
  EEPROM.get(addressCRCDataUser(addressData), crcSave);
  EEPROM.get(addressDataUser(addressData), data);

  CRC16 crc;
  crc.add((uint8_t*)&data, sizeof(TypeDataToSave));
  succes = crcSave == crc.calc();

  if (succes) {
    this->datas(data);
  }

  return succes;
}

template <typename TypeDataToSave>
void DataToSaveEEprom<TypeDataToSave>::deleteEEPROM() 
{
  for (uint16_t addressEEPROM = 0; addressEEPROM < EEPROM.length();
       ++addressEEPROM) {
    EEPROM.write(addressEEPROM, 0);
  }
}

template <typename TypeDataToSave>
void DataToSaveEEprom<TypeDataToSave>::showContentEEPROM() 
{
  uint16_t addressDatas = 0;
  uint16_t counterWriting = 0;
  uint16_t signatureApp = 0;
  uint16_t crcDataUser = 0;

  EEPROM.get(ADDRESS_SIGNATURE_APP, signatureApp);
  EEPROM.get(ADDRESS_START_DATAS, addressDatas);
  EEPROM.get(addressCounterWriting(addressDatas), counterWriting);
  EEPROM.get(addressCRCDataUser(addressDatas), crcDataUser);

  Serial.println("Taille donnees : " + String(dataSize()));
  Serial.println("Signature app : 0x" +
                 padLeft(String(signatureApp, HEX), 4, '0'));
  Serial.println("Adresse debut donnees : 0x" +
                 padLeft(String(addressDatas, HEX), 4, '0'));
  Serial.println(
      "Adresse CRC donnees utilisateur : 0x" +
      padLeft(String(addressCRCDataUser(addressDatas), HEX), 4,
              '0'));
  Serial.println(
      "Adresse debut donnees utilisateur : 0x" +
      padLeft(String(addressDataUser(addressDatas), HEX), 4, '0'));
  Serial.println("Compteur ecritures : " + String(counterWriting, DEC));
  Serial.println("CRC donnees utilisateur : 0x" +
                 padLeft(String(crcDataUser, HEX), 4, '0'));
  Serial.println();

  Serial.println("Contenu de l'EEPROM :");
  Serial.println("Capacite dump : " + String(EEPROM.length(), DEC));

  uint16_t lineOffset = 16;
  Serial.print(padLeft("", 4));
  for (uint16_t compt = 0; compt < lineOffset; ++compt) {
    Serial.print("  " + padLeft(String(compt, HEX), 2, '0'));
  }
  Serial.println();

  for (uint16_t adresse = 0; adresse < EEPROM.length(); adresse += lineOffset) {
    Serial.print(padLeft(String((uint16_t)adresse, HEX), 4, '0'));
    for (uint16_t offset = 0;
         offset < lineOffset && adresse + offset < EEPROM.length(); ++offset) {
      uint16_t adresseAAfficher = adresse + offset;
#if defined(USE_COLOR_TERMINAL)
      if (adresseAAfficher == ADDRESS_SIGNATURE_APP ||
          adresseAAfficher == ADDRESS_SIGNATURE_APP + 1) {
        Serial.print(TEXT_BOLD);
        Serial.print(TEXT_BG_BLACK);
        Serial.print(TEXT_BLUE);
      } else if (adresseAAfficher == ADDRESS_START_DATAS ||
                 adresseAAfficher == ADDRESS_START_DATAS + 1) {
        Serial.print(TEXT_BOLD);
        Serial.print(TEXT_BG_BLACK);
        Serial.print(TEXT_YELLOW);
      } else if (adresseAAfficher == addressDatas ||
                 adresseAAfficher == addressDatas + 1) {
        Serial.print(TEXT_BOLD);
        Serial.print(TEXT_BG_BLACK);
        Serial.print(TEXT_BLUE);
      } else if (adresseAAfficher ==
                     addressCRCDataUser(addressDatas) ||
                 adresseAAfficher ==
                     addressCRCDataUser(addressDatas) + 1) {
        Serial.print(TEXT_BOLD);
        Serial.print(TEXT_BG_BLACK);
        Serial.print(TEXT_YELLOW);
      } else if (adresseAAfficher >=
                     addressDataUser(addressDatas) &&
                 adresseAAfficher < addressDataUser(addressDatas) +
                                        sizeof(TypeDataToSave)) {
        Serial.print(TEXT_BOLD);
        Serial.print(TEXT_BG_BLACK);
        Serial.print(TEXT_GREEN);
      }
#endif
      Serial.print("  " +
                   padLeft(String(EEPROM.read(adresseAAfficher), HEX), 2, '0'));
#if defined(USE_COLOR_TERMINAL)
      Serial.print(TEXT_RESET);
#endif
    }

    Serial.print("  |  ");
    for (uint16_t offset = 0;
         offset < lineOffset && adresse + offset < EEPROM.length(); ++offset) {
      char character = (char)EEPROM.read(adresse + offset);
      Serial.print(isprint(character) ? character : ' ');
    }

    Serial.println("  |");
  }

  Serial.println();
}