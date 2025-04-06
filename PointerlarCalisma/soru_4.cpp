#include <iostream>
#include <locale.h>
#include <cstring>

using namespace std;

int main()
{
	setlocale(LC_ALL , "Turkish");
	
	/*
	//Soru 1
	char* dizi = "Merhaba";
	while(*dizi)
	{
		cout << *dizi++;
	}
	cout << endl;
	*/
	
	/*
	//Soru 2
	char dizi[] = "Dizinin boyutu";
	char* p;
	p = dizi;
	int boyut = 0;
	
	while(*p)
	{
		boyut += 1;
		p++;
	}
	cout << "Dizinin boyutu: " << boyut << endl;
	*/
	/*
	//Soru 3
	char dizi[50] = "Merhaba Dünya";
	char* p = dizi;
	while(*p)
	{
		p++;
	}
	*p = '!';
	*p++;
	*p = '\0';
	cout << "Yeni hali: " << dizi << endl;
	*/
	/*
	//Soru 4
	char dizi[] = "Pointerlari";
	char* p = dizi;
	int boyut = strlen(dizi);
	char yedek;
	int j = strlen(dizi)-1;
	for(int i = 0; i < boyut/2; i++ )
	{
		yedek = *(p+i);
		*(p+i) = *(p+j);
		*(p+j) = yedek;
		j--;
	}
	cout << dizi << endl;
	*/
	/*
	//Soru 5
	char dizi[] = "Merhaba Dünya";
	char* p = dizi;
	int sayac = 0;
	while(*p)
	{
		sayac += 1;
		if(*p == 'D')
		{
			cout << sayac+1 << ". indisde 'D' harfi." << endl;
			break;
		}
		p++;
	}
	*/
	/*
	//Soru 6
	char dizi[] = "Hayat";
	char* p = dizi;
	*p = 'G';
	cout << dizi << endl;
	*/
	
	/*
	//Soru 7
	char dizi[] = "C++ Dili";
	char* p = dizi;
	while(*p)
	{
		cout << *p << endl;
		p++;
	}
	*/
	
	char* gunler[7] = {"Pazartesi" , "Salý" , "Çarþamba" , "Perþembe" , "Cuma" , "Cumartesi" , "Pazar"};
	for(int i = 0; i < 7; i++)
	{
		cout << i+1 << ". elemanýn adresi: " << (gunler+i) << "ve deðeri: " << gunler[i] << endl;
	 } 
	
	system("pause");
	return 0;
}



