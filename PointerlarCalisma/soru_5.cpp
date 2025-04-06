#include <iostream>
#include <locale.h>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
	setlocale(LC_ALL , "Turkish");
	
	/*
	//Soru 1
	int* ptr = (int*) malloc(10 * sizeof(int));
	
	for(int i = 0; i < 10 ; i++)
	{
		cout << i+1 << ". elemanýn deðerini giriniz: ";
		cin >> *(ptr+i);
	}
	
	int toplam = 0 , ortalama = 0;
	for(int i = 0 ; i < 10 ; i++)
	{
		toplam += *(ptr+i);
	}
	ortalama = toplam /10;
	cout << "Ortalama: " << ortalama << endl;
	free(ptr);
	*/
	/*
	//Soru 2
	int* ptr = (int*) calloc(10 , sizeof(int));
	
	for(int i = 0; i < 10 ; i++)
	{
		cout << "Dizinin " << i+1 << ". elemaný: " << *(ptr+i) << endl;
	 }
	free(ptr); 
	//Bütün elemanlar 0
	
	*/
	/*
	//Soru 3
	int* ptr = (int*) calloc(5 , sizeof(int));
	
	ptr = (int*) realloc(ptr , 10 * sizeof(int));
	
	for(int i = 5 ; i < 10 ; i++)
	{
		cout << "Dizinin " << i+1 << ". elemanýnýn deðerini giriniz: ";
		cin >> *(ptr+i);
	}
	
	for(int i = 0; i < 10 ; i++)
	{
		cout << "Dizinin " << i+1 << ". elemaný: " << *(ptr+i) << endl;
	}
	free(ptr); 
	*/
	
	//Soru 4
	int* dizi = new int[7];
	
	for(int i = 0 ; i < 7 ; i++)
	{
		cout << "Dizinin " << i+1 << ". elemanýnýn deðerini giriniz: ";
		cin >> *(dizi+i);
	}
	
	for(int i = 0; i < 7 ; i++)
	{
		cout << "Dizinin " << i+1 << ". elemaný: " << *(dizi+i) << endl;
	} 
	
	
	delete [] dizi; 
	
	system("pause");
	return 0;
}



