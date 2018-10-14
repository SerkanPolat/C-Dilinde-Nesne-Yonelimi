/**
*
* @author Serkan POLAT ve serkan.polat2@ogr.sakarya.edu.tr / Ýsmail Kaya ve ismail.kaya7@ogr.sakarya.edu.tr
* @since 21.04.2018
* <p>
* Açýklama : Kisi Baþlýk Dosyasý
* </p>
*/
#ifndef KISI_H
#define KISI_H
#include <time.h>
typedef struct KISI* Kisi;
struct KISI{
	int Yas;
	char  *Isim;
	char  *Soyisim;
	void  (*IsimSoyisimBelirle)(const Kisi);
	void  (*YasBelirle)(const Kisi);
	int   (*GetYas)(const Kisi);
	char* (*GetIsim)(const Kisi);
	char* (*GetSoyisim)(const Kisi);
};
Kisi KisiKurucu();
void KisiYikici(Kisi);
void _IsimSoyisimBelirle(const Kisi);
void _YasBelirle(const Kisi);
int _GetYas(const Kisi);
char* _GetIsim(const Kisi);
char* _GetSoyisim(const Kisi);
#endif
