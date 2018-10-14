/**
*
* @author Serkan POLAT ve serkan.polat2@ogr.sakarya.edu.tr / Ýsmail Kaya ve ismail.kaya7@ogr.sakarya.edu.tr
* @since 21.04.2018
* <p>
* Açýklama : RastgeleKisi Baþlýk Dosyasý
* </p>
*/
#ifndef RASTGELEKISI_H
#define RASTGELEKISI_H
#include "Kisi.h"
#include "Telefon.h"
#include "ImeiNo.h"
#include "KimlikNo.h"
typedef struct RASTGELEKISI* RastgeleKisi;
struct RASTGELEKISI{
	Kisi YeniKisi;
	Telefon YeniTelefon;
	Imei YeniImei;
	KimlikNo YeniKimlikNo;
	void (*KisiUret)(const RastgeleKisi,int);
	void (*IMEIKontrol)(const RastgeleKisi);
	void (*TcKimlikKontrol)(const RastgeleKisi);
};
RastgeleKisi RastgeleKisiKurucu();
void RastgeleKisiYikici(RastgeleKisi);
void _KisiUret(const RastgeleKisi,int);
void _IMEIKontrol(const RastgeleKisi);
void _TcKimlikKontrol(const RastgeleKisi);

#endif
