/**
*
* @author Serkan POLAT ve serkan.polat2@ogr.sakarya.edu.tr / Ýsmail Kaya ve ismail.kaya7@ogr.sakarya.edu.tr
* @since 21.04.2018
* <p>
* Açýklama : Telefon Numarasý Üretir.
* </p>
*/
#include "Telefon.h"
#include <stdio.h>
Telefon TelefonKurucu(){
	Telefon this;
	this = (Telefon)malloc(sizeof(struct TELEFON));
	this->TelefonNumarasiUret=&_TelefonNumarasiUret;
	this->GetTelefonNumarasi = &_GetTelefonNumarasi;
	return this;
}
void TelefonYikici(Telefon this){
	if(this!=NULL){
		free(this->TelefonNumarasi);
		free(this);
	}	
}
char *_GetTelefonNumarasi(Telefon this){
	return this->TelefonNumarasi;
}
void _TelefonNumarasiUret(const Telefon this){
	int index=0;
	char* TelefonNumarasi = (char*)malloc(sizeof(char)*11);
	char TurkiyeNumaraAlanKodlari[30][3]={"501","505","506","507","551","552",
                                       "553","554","555","559","530","531",
                                       "532","533","534","535","536","537",
                                       "538","539","561","540","541","542",
                                       "544","545","546","547","548","549",
                                       };
    TelefonNumarasi[index]='0';
    index++;
    int RastgeleAlanKodu = rand()%30;
    for(index;index<=3;index++){
    	TelefonNumarasi[index]= TurkiyeNumaraAlanKodlari[RastgeleAlanKodu][index-1];
	}
	
	for(index;index<11;index++){
		TelefonNumarasi[index]=rand()%10+48;	
	}
	TelefonNumarasi[11]=0;
	this->TelefonNumarasi=TelefonNumarasi;
}
