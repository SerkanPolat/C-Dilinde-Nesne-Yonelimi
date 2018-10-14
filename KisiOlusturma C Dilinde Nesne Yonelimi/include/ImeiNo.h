/**
*
* @author Serkan POLAT ve serkan.polat2@ogr.sakarya.edu.tr / Ýsmail Kaya ve ismail.kaya7@ogr.sakarya.edu.tr
* @since 21.04.2018
* <p>
* Açýklama : ImeiNo Baþlýk Dosyasý
* </p>
*/
#ifndef IMEINO_H
#define IMEINO_H
#include <stdlib.h>
typedef struct IMEINO* Imei;
struct IMEINO{
	char* ImeiNumarasi;
	void (*ImeiNumarasiUret)(const Imei);
	int (*ImeiKontrol)(const Imei);
	char* (*GetImeiNumarasi)(const Imei);
};
Imei ImeiKurucu();
void ImeiYikici(Imei);
void _ImeiNumarasiUret(const Imei);
int _ImeiKontrol(const Imei);
char *_GetImeiNumarasi(const Imei);
#endif
