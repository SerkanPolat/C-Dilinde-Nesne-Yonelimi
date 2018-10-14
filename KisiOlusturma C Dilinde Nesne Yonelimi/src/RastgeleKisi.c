/**
*
* @author Serkan POLAT ve serkan.polat2@ogr.sakarya.edu.tr / Ýsmail Kaya ve ismail.kaya7@ogr.sakarya.edu.tr
* @since 21.04.2018
* <p>
* Açýklama : Tüm Ýþlemler Buradan Baþlatýlýr Diðer Baþlýk Dosyalarýyla Baðlantýlar Kurulur Dosyaya Yazýlma Ýþlemi Gerçekleþtirir.
* </p>
*/
#include "RastgeleKisi.h"
RastgeleKisi RastgeleKisiKurucu(){
	RastgeleKisi this;
	this = (RastgeleKisi)malloc(sizeof(struct RASTGELEKISI));
	this->KisiUret = &_KisiUret;
	this->IMEIKontrol = &_IMEIKontrol;
	this->TcKimlikKontrol = &_TcKimlikKontrol;
	this->YeniKisi = KisiKurucu();
	this->YeniTelefon = TelefonKurucu();
	this->YeniKimlikNo = KimlikNoKurucu();
	this->YeniImei = ImeiKurucu();
	return this;
}
void RastgeleKisiYikici(RastgeleKisi this){
	if(this!=NULL){
		KisiYikici(this->YeniKisi);
		TelefonYikici(this->YeniTelefon);
		ImeiYikici(this->YeniImei);
		KimlikNoYikici(this->YeniKimlikNo);
		free(this);
	}
}
void _KisiUret(const RastgeleKisi this,int UretilecekKisiSayisi){
	srand(time(NULL));
	FILE *dosya;
	int i = 0;
	dosya = fopen("Kisiler.txt","a+");
	for(i;i<UretilecekKisiSayisi;i++){
		this->YeniKisi->YasBelirle(this->YeniKisi);
		this->YeniKisi->IsimSoyisimBelirle(this->YeniKisi);
		this->YeniKimlikNo->KimlikNoUret(this->YeniKimlikNo);
		this->YeniTelefon->TelefonNumarasiUret(this->YeniTelefon);
		this->YeniImei->ImeiNumarasiUret(this->YeniImei);
	
		fprintf(dosya,"%s ",this->YeniKimlikNo->GetKimlikNumarasi(this->YeniKimlikNo));
		fprintf(dosya,"%s ",this->YeniKisi->GetIsim(this->YeniKisi));
		fprintf(dosya,"%s ",this->YeniKisi->GetSoyisim(this->YeniKisi));
		fprintf(dosya,"%d ",this->YeniKisi->GetYas(this->YeniKisi));
		fprintf(dosya,"%s ",this->YeniTelefon->GetTelefonNumarasi(this->YeniTelefon));	
		fprintf(dosya,"(%s)\n",this->YeniImei->GetImeiNumarasi(this->YeniImei));
	}
	fclose(dosya);
}
void _IMEIKontrol(const RastgeleKisi this){
	this->YeniImei->ImeiKontrol(this->YeniImei);
}
void _TcKimlikKontrol(const RastgeleKisi this){
	this->YeniKimlikNo->KimlikNoKontrol(this->YeniKimlikNo);
}
