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
	char kelime[] = "Ben Silayi �ok seviyorum";
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
    int *temp;     // Ge�ici bir pointer tan�mlad�k
    
    temp = p1;     // temp pointer'�n� p1'e e�itliyoruz, yani sayi1'in adresini tutuyor.
    *p1 = *p2;     // sayi1'in de�eri sayi2'nin de�eriyle de�i�tiriliyor.
    *p2 = *temp;   // sayi2'nin de�eri, eski sayi1 de�eriyle de�i�tiriliyor.

    // Sonu�lar� ekrana yazd�r�yoruz.
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

