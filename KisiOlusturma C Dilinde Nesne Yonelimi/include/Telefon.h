/**
*
* @author Serkan POLAT ve serkan.polat2@ogr.sakarya.edu.tr / Ýsmail Kaya ve ismail.kaya7@ogr.sakarya.edu.tr
* @since 21.04.2018
* <p>
* Açýklama : Telefon Baþlýk Dosyasý
* </p>
*/
#ifndef TELEFON_H
#define TELEFON_H
#include "ImeiNo.h"
typedef struct TELEFON* Telefon;
struct TELEFON{
	Imei SuperImei;   
	char *TelefonNumarasi;
	void (*TelefonNumarasiUret)(const Telefon);
	char* (*GetTelefonNumarasi)(const Telefon);
};

Telefon TelefonKurucu();
void TelefonYikici(Telefon);
void _TelefonNumarasiUret(const Telefon);
char *_GetTelefonNumarasi(const Telefon);
#endif
