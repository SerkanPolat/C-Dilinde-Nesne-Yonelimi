/**
*
* @author Serkan POLAT ve serkan.polat2@ogr.sakarya.edu.tr / Ýsmail Kaya ve ismail.kaya7@ogr.sakarya.edu.tr
* @since 21.04.2018
* <p>
* Açýklama : KimlikNo Baþlýk Dosyasý
* </p>
*/
#ifndef KIMLIKNO_H
#define KINLIKNO_H
#include <stdio.h>
typedef struct KIMLIKNO* KimlikNo;
struct KIMLIKNO{
	int Gecersiz;
	int Gecerli;
	char* KimlikNumarasi;
	void* (*KimlikNoUret)(const KimlikNo);
	void (*KimlikNoKontrol)(const KimlikNo);
	char* (*GetKimlikNumarasi)(const KimlikNo);
};
KimlikNo KimlikNoKurucu();
void KimlikNoYikici(KimlikNo);
void* _KimlikNoUret(const KimlikNo);
void _KimlikNoKontrol(const KimlikNo);
char* _GetKimlikNumarasi(const KimlikNo);


#endif
