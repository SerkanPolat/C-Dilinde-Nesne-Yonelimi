/**
*
* @author Serkan POLAT ve serkan.polat2@ogr.sakarya.edu.tr / Ýsmail Kaya ve ismail.kaya7@ogr.sakarya.edu.tr
* @since 21.04.2018
* <p>
* Açýklama : ÝMEÝ Numarasý Üretme ve Üretilmiþ ÝMEÝ Numarasý Kontrolü
* </p>
*/
#include "ImeiNo.h"
#include <stdio.h>
#include <time.h>

Imei ImeiKurucu(){
	Imei this;
	this = (Imei)malloc(sizeof(struct IMEINO));
	this->ImeiNumarasiUret = &_ImeiNumarasiUret;
	this->ImeiKontrol = &_ImeiKontrol;
	this->GetImeiNumarasi = &_GetImeiNumarasi;
	return this;
}
void ImeiYikici(Imei this){
	if(this!=NULL){
		free(this->ImeiNumarasi);
		free(this);
	}
}
void _ImeiNumarasiUret(const Imei this){
	int Gecici=0;
	int index=0,ImeiToplam=0;
	char *ImeiNumarasi = (char*)malloc(sizeof(char)*16);
	for(index;index<14;index++){
		ImeiNumarasi[index]=rand()%10+48;
		Gecici=ImeiNumarasi[index]-48;
		if(index%2==1){
			Gecici*=2;
			if(Gecici/10==1){
				ImeiToplam+=Gecici/10;
				ImeiToplam+=Gecici%10;
			}else{
				ImeiToplam+=Gecici;
			}
		}else{
			ImeiToplam+=Gecici;
		}
	}
			if(ImeiToplam%10==0){
                ImeiNumarasi[index]='0';
            }else{
                ImeiNumarasi[index]=(10-ImeiToplam%10)+48;
            }
	ImeiNumarasi[15]=0;
    this->ImeiNumarasi=ImeiNumarasi;
}
int _ImeiKontrol(const Imei this){
	char DosyadanOkunan[20];
	int Gecici,Gecerli=0,Gecersiz=0,i,ImeiToplam=0;
	FILE *dosya;
	dosya = fopen("Kisiler.txt","r");
	while(!feof(dosya)){
		for(i=0;i<5;i++){
			fscanf(dosya,"%s",DosyadanOkunan);
		}
		fscanf(dosya,"%s",DosyadanOkunan);
		ImeiToplam=0;
		for(i=1;i<15;i++){
			Gecici=DosyadanOkunan[i]-48;
			if(i%2==0){
				Gecici*=2;
				if(Gecici/10==1){
					ImeiToplam+=Gecici/10;
					ImeiToplam+=Gecici%10;
				}else{
					ImeiToplam+=Gecici;
				}
			}else{
				ImeiToplam+=Gecici;
			}
		}
			if(ImeiToplam%10==0){
           	    if(DosyadanOkunan[15]=='0'){
           	    	Gecerli++;
				}else{
					Gecersiz++;
				}
           	}
			else{
               	if(DosyadanOkunan[15]==(10-ImeiToplam%10)+48){
               		Gecerli++;
				}else{
					Gecersiz++;
				}
            }
	}
	printf("IMEI Kontrol\n");
	printf("%d   Gecerli\n",Gecerli-1);
	printf("%d   Gecersiz",Gecersiz);
}
char* _GetImeiNumarasi(const Imei this){
	return this->ImeiNumarasi;
}
