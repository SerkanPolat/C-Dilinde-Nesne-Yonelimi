/**
*
* @author Serkan POLAT ve serkan.polat2@ogr.sakarya.edu.tr / Ýsmail Kaya ve ismail.kaya7@ogr.sakarya.edu.tr
* @since 21.04.2018
* <p>
* Açýklama : Kisi'nin Ad Soyad ve Yaþ Bilgilerinin Belirlenmesi
* </p>
*/
#include "Kisi.h"
#include <stdio.h>
#include <stdlib.h>
Kisi KisiKurucu(){
	Kisi this;
	this = (Kisi)malloc(sizeof(struct KISI));
	this->IsimSoyisimBelirle= &_IsimSoyisimBelirle;
	this->YasBelirle = &_YasBelirle;
	this->GetYas = &_GetYas;
	this->GetIsim = &_GetIsim;
	this->GetSoyisim = &_GetSoyisim;
	return this;
}
void KisiYikici(Kisi this){
	if(this!=NULL){
		free(this->Isim);
		free(this->Soyisim);
		free(this);	
	}
}
void _IsimSoyisimBelirle(const Kisi this){
	int VerininCekilecegiIndex=rand()%3000;
	int i;
	FILE *dosya;
	char* Isim = (char*)malloc(sizeof(char)*20);
	char* Soyisim = (char*)malloc(sizeof(char)*20);
	dosya = fopen("random_isimler.txt","r");
	for(i=0;i<VerininCekilecegiIndex;i++){
		fscanf(dosya,"%s %s",Isim,Soyisim);
	}
	fclose(dosya);
	this->Isim=Isim;
	this->Soyisim=Soyisim;
	this->YasBelirle(this);
}
void _YasBelirle(const Kisi this){
	this->Yas = rand()%99+1;
}
int _GetYas(const Kisi this){
	return this->Yas;
}
char* _GetIsim(const Kisi this){
	return this->Isim;
}
char * _GetSoyisim(const Kisi this){
	return this->Soyisim;
}
