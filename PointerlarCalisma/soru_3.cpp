#include <iostream>
#include <locale.h>
#include <cstring>

using namespace std;

void yazdir(int* dizi , int boyut);
void ciftleriYazdir(int* dizi , int boyut);
void diziyeDegerEkle(int* dizi , int boyut , int deger);
void diziyeAtamaYap(int* dizi , int boyut);
void sirala(int* dizi , int boyut);
void siralaBuyuk(int* dizi , int boyut);

int main()
{
	setlocale(LC_ALL ,"Turkish");
	
	/*
	int dizi[] = {10 , 20, 30 , 40 , 50};
	int* p;
	p = dizi;
	*/
	/*
	//Soru 1
	
	cout << "Dizinin ilk eleman�: " << *p << endl;
	*/
	
	/*
	//Soru 2
	int boyut = sizeof(dizi) / sizeof(dizi[0]);
	for(int i = 0 ; i < boyut; i++)
	{
		cout << "Dizinin " << i+1 << ". eleman� " << *(p+i) << endl;
	}
	*/
	
	/*
	//Soru 3
	*(p+2) = 99;
	
	cout << "Dizinin 3. eleman�: " << *(p+2) << endl; 
	*/
	
	/*
	//Soru 4
	int boyut = sizeof(dizi) / sizeof(dizi[0]);
	for(int i = boyut-1; i >= 0; i--)
	{
		cout << "Dizinin " << i+1 << ". eleman�: " << *(p+i) << endl; 
	}
	*/
	
	/*
	//Soru 5
	int dizi[] = {20 , 30 , 50 , 70 , 80 , 50 , 60 , 10};
	int* p;
	p = dizi;
	float toplam = 0 , ortalama = 0;
	int boyut = sizeof(dizi) / sizeof(dizi[0]);
	
	for(int i = 0 ; i < boyut ; i++)
	{
		toplam += *(p+i);
	}
	cout << "Dizideki say�lar�n toplam�: " << toplam << endl;
	ortalama = toplam / boyut;
	cout << "Dizideki say�lar�n ortalamas�: " << ortalama << endl;
	*/
	
	/*
	//Soru 6
	int dizi[] = {20 , 10 , 50 , 70 , 60 , 50 , 90 , 10};
	int* p;
	p = dizi;
	int boyut = sizeof(dizi) / sizeof(dizi[0]);
	int enBuyuk = *p;
	
	for(int i = 1 ; i < boyut ; i++)
	{
		if(*(p+i) > enBuyuk)
		{
			enBuyuk = *(p+i);
		}
	}
	cout << "En B�y�k de�er: " << enBuyuk << endl;
	*/
	
	/*
	//Soru 7
	int dizi[] = {20 , 10 , 50 , 70 , 60 , 50 , 90 , 10};
	int* p;
	p = dizi;
	int boyut = sizeof(dizi) / sizeof(dizi[0]);
	yazdir(p , boyut);
	*/
	
	/*
	//Soru 8
	int dizi[] = {25 , 40, 68 , 17 , 98 , 37 , 14 , 25 , 38};
	int* p;
	p = dizi;
	int boyut = sizeof(dizi) / sizeof(dizi[0]);
	ciftleriYazdir(p , boyut);
	*/
	
	/*
	//Soru 9
	int dizi[] = {25 , 40, 68 , 17 , 98 , 37 , 14 , 25 , 38};
	int* p;
	p = dizi;
	int boyut = sizeof(dizi) / sizeof(dizi[0]);
	cout << "eski hali : " << endl;
	yazdir(p , boyut);
	diziyeDegerEkle(p , boyut , 20);
	cout << "-----------------------------------------" << endl << "yeni hali: " << endl;
	yazdir(p , boyut);
	*/
	
	/*
	//Soru 10
	int* p;
	int diziBoyutu;
	cout << "Ka� elemanl� bir diziniz olsun :";
	cin >> diziBoyutu;
	
	p = new int[diziBoyutu];
	
	diziyeAtamaYap(p , diziBoyutu);
	cout << "--------------------------------" << endl;
	yazdir(p , diziBoyutu);
	
	delete [] p;
	*/
	
	//Soru 11
	int dizi[] = {25, 12, 45, 67, 10, 5, 99};
	int* p;
	p = dizi;
	int boyut = sizeof(dizi) / sizeof(dizi[0]);
	cout << "---------------------------------" << endl << "�lk hali:" << endl;
	yazdir(p, boyut);
	cout << "---------------------------------" << endl << "K���kten B�y��e:" << endl;
	sirala(p , boyut);
	yazdir(p , boyut);
	cout << "---------------------------------" << endl << "B�y�kten K����e:" << endl;
	siralaBuyuk(p , boyut);
	yazdir(p , boyut);
	
	
	
	
	system("pause");
	return 0;
}
//Soru 7
void yazdir(int* dizi , int boyut)
{
	for(int i = 0 ; i < boyut ; i++)
	{
		cout << "Dizinin " << i+1 << ". eleman�: " << *(dizi+i) << endl;
	}
}

//Soru 8
void ciftleriYazdir(int* dizi , int boyut)
{
	for(int i = 0 ; i < boyut ; i++)
	{
		if(*(dizi+i)%2 == 0)
		{
			cout << "Dizinin " << i+1 << ". eleman� �ifttir, de�eri: " << *(dizi+i) << endl;
		}
	}
}

//Soru 9
void diziyeDegerEkle(int* dizi , int boyut , int deger)
{
	for(int i = 0 ; i < boyut ; i++)
	{
		*(dizi+i) += deger;
	}
}

//Soru 10
void diziyeAtamaYap(int* dizi , int boyut)
{
	for(int i = 0; i < boyut ; i++)
	{
		cout << "Dizinin " << i+1 << ". eleman�n� de�eri:";
		cin >> *(dizi+i);
	}
}

//Soru 11
void sirala(int* dizi , int boyut)
{
	int yedek;
	for(int i = 0 ; i < boyut-1; i++)
	{
		for(int j = 0; j < boyut-i-1; j++)
		{
			if(*(dizi+j) > *(dizi+j+1))
			{
				yedek = *(dizi+j);
				*(dizi+j) = *(dizi+j+1);
				*(dizi+j+1) = yedek;
			}
		}
	}
}

//Soru 12
void siralaBuyuk(int* dizi , int boyut)
{
	int yedek;
	for(int i = 0 ; i < boyut -1 ; i++)
	{
		for(int j = 0 ; j < boyut - i - 1; j++)
		{
			if(*(dizi+j) < *(dizi+j+1))
			{
				yedek = *(dizi+j);
				*(dizi+j) = *(dizi+j+1);
				*(dizi+j+1) = yedek;
			}
		}
	}	
}
