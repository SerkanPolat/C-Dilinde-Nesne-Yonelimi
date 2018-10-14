/**
*
* @author Serkan POLAT ve serkan.polat2@ogr.sakarya.edu.tr / Ýsmail Kaya ve ismail.kaya7@ogr.sakarya.edu.tr
* @since 21.04.2018
* <p>
* Açýklama : Test Programý
* </p>
*/
#include "RastgeleKisi.h"
#include <stdio.h>
int main(){
	RastgeleKisi this = RastgeleKisiKurucu();
	int secim=-1;
	int KisiAdet=0;
	while(secim!=3){
		printf("\n\n-------\n\n");
		printf("1-Rastgele Kisi Uret\n");
		printf("2-Uretilmis Dosya Kontrol Et\n");
		printf("3-Cikis\n");
		printf("Seciminizi Yapiniz : "); scanf("%d",&secim);
		printf("\n\n-------\n\n");
		switch (secim){
			case 1:
				printf("Uretilecek Kisi Adedini Giriniz : "); scanf("%d",&KisiAdet);
				this->KisiUret(this,KisiAdet);
			break;
			case 2:
				this->TcKimlikKontrol(this);
				this->IMEIKontrol(this);
		}
	}
	RastgeleKisiYikici(this);
}
