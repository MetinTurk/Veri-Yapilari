#include <iostream>
#include <locale.h>
#include <cstring>

using namespace std;
void kelimeBuyut(char* p , int boyut);
int main()
{
	setlocale(LC_ALL , "Turkish");
	
	//Soru1
	/*
	char kelime[] = "Ben Silayi Çok seviyorum";
	char *p;
	p = kelime;
	int boyut = strlen(kelime);
	kelimeBuyut(p , boyut);
	cout << kelime << endl;
	*/
	
	//Soru3
	/*
	int sayi1 = 10 , sayi2 = 20;
	int *p1 , *p2;
	p1 = &sayi1;
	p2 = &sayi2;
	int *temp;
	temp = p1;
	*p1 = *p2;
	*p2 = *temp;
	cout << "sayi1 : " << sayi1 << " sayi2 : " << sayi2 << endl;
	*/
	int sayi1 = 10, sayi2 = 20;
    int *p1, *p2;
    p1 = &sayi1;   // p1 sayi1'in adresini tutuyor
    p2 = &sayi2;   // p2 sayi2'nin adresini tutuyor
    int *temp;     // Geçici bir pointer tanýmladýk
    
    temp = p1;     // temp pointer'ýný p1'e eþitliyoruz, yani sayi1'in adresini tutuyor.
    *p1 = *p2;     // sayi1'in deðeri sayi2'nin deðeriyle deðiþtiriliyor.
    *p2 = *temp;   // sayi2'nin deðeri, eski sayi1 deðeriyle deðiþtiriliyor.

    // Sonuçlarý ekrana yazdýrýyoruz.
    cout << "sayi1 : " << sayi1 << " sayi2 : " << sayi2 << endl;
		
		
	
	
	system("pause");
	return 0;
}
//Soru 1
/*
void kelimeBuyut(char* p, int boyut) 
{
	for(int i = 0 ; i < boyut ; i++)
	{
		if(int(p[i]) >= 'a' && int(p[i]) <= 'z')
		{
			p[i] -= 32;
		}
		else
		{
			continue;
		}
		
	}
}
*/

