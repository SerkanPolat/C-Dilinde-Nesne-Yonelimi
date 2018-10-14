/**
*
* @author Serkan POLAT ve serkan.polat2@ogr.sakarya.edu.tr / Ýsmail Kaya ve ismail.kaya7@ogr.sakarya.edu.tr
* @since 21.04.2018
* <p>
* Açýklama : Kimlik Numarasý Üretme ve Üretilmiþ Kimlik Numarasý Kontrolü 
* </p>
*/
#include "KimlikNo.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
KimlikNo KimlikNoKurucu(){
	KimlikNo this;
	this->Gecersiz=0;
	this->Gecerli=0;
	this=(KimlikNo)malloc(sizeof(struct KIMLIKNO));
	this->KimlikNoUret= &_KimlikNoUret;
	this->KimlikNoKontrol = &_KimlikNoKontrol;
	this->GetKimlikNumarasi=&_GetKimlikNumarasi;
	return this;
}
void KimlikNoYikici(KimlikNo this){
	if(this!=NULL){
		free(this->KimlikNumarasi);
		free(this);
	}
}
void* _KimlikNoUret(const KimlikNo this){
	int index=0;
	char *KimlikNumarasi = (char*)malloc(sizeof(char)*11);
	KimlikNumarasi[index] = rand()%9+49;
	index++;
	for(index;index<9;index++){
		KimlikNumarasi[index] = rand()%10+48;
	}
	int i;
	int TcSayilarDizisi[12];
	KimlikNumarasi[9] = ((KimlikNumarasi[0]-48+KimlikNumarasi[2]-48+KimlikNumarasi[4]-48+
							KimlikNumarasi[6]-48+KimlikNumarasi[8]-48)*7 - 
							(KimlikNumarasi[1]-48+KimlikNumarasi[3]-48+KimlikNumarasi[5]-48+KimlikNumarasi[7]-48))%10+48;
	KimlikNumarasi[10]= (KimlikNumarasi[0]-48+KimlikNumarasi[9]-48)%10+48;
	KimlikNumarasi[11]=0;
	this->KimlikNumarasi=KimlikNumarasi;
}
void _KimlikNoKontrol(const KimlikNo this){
	char KimlikNumarasi[12];
	char Gecici[20];
	int i=0;
	int GecerliKimlikSayisi=0;
	int GecersizKimlikSayisi=0;
	FILE *dosya;
	dosya = fopen("Kisiler.txt","r");
	while(!feof(dosya)){
		fscanf(dosya,"%s",KimlikNumarasi);
		for(i=0;i<5;i++){
			
			fscanf(dosya,"%s",Gecici);
		}
		if(KimlikNumarasi[9] == ((KimlikNumarasi[0]-48+KimlikNumarasi[2]-48+KimlikNumarasi[4]-48+
							KimlikNumarasi[6]-48+KimlikNumarasi[8]-48)*7 - 
							(KimlikNumarasi[1]-48+KimlikNumarasi[3]-48+KimlikNumarasi[5]-48+KimlikNumarasi[7]-48))%10+48){
			if(KimlikNumarasi[10] == (KimlikNumarasi[0]-48+KimlikNumarasi[9]-48)%10+48){
				GecerliKimlikSayisi++;
			}
		}else{
		GecersizKimlikSayisi++;
		}
	}
	fclose(dosya);
	printf("T.C Kimlik Kontrol\n");
	printf("%d   Gecerli\n",GecerliKimlikSayisi-1); //En Son Satir \n de Gecerli Sayildigindan -1 Dogru Rakami Veriyor.
	printf("%d   Gecersiz\n\n",GecersizKimlikSayisi);
}
char* _GetKimlikNumarasi(const KimlikNo this){
	return this->KimlikNumarasi;
}
