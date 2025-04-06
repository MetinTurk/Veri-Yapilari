#include <iostream>
#include <locale.h>

using namespace std;

void ikiKatinaCikar(int* p);
int main()
{
	setlocale(LC_ALL , "Turkish");
	
	//Soru 1
	/*
	int sayi = 10;
	int *p;
	
	p = &sayi;
	
	*p = 30;
	cout << "Sayi: " << sayi << endl;
	*/
	
	//Soru 2
	/*
	int sayilar[5] = {1 , 2 , 3 , 4 , 5};
	int *p;
	p = sayilar;
	for(int i = 0 ; i < 5 ; i++)
	{
		cout << *p++ << endl;
	}
	*/
	
	//Soru 3
	/*
	int sayi = 15;
	int *p;
	p = &sayi;
	cout << "Sayi : " << sayi << endl;
	ikiKatinaCikar(p);
	cout << "Sayi : " << sayi << endl;
	*/
	
	//Soru 4
	/*
	int *p;
	p = new int(21);		//int deðer büyüklüðünde bellek tahsis ederek bellek adresine 21 deðerini atar.
	*p = 20;			//iþaretci kullanarak deðerini güncelledik
	cout << *p << endl;
	delete p;
	*/
	
	
	//Soru 5 
	int *p1 , *p2;
	int* p3 , p4;
	int sayi = 20;
	p1 = &sayi;
	p2 = p1;
	cout << *p1 << " "  << *p2<< endl; 
	
	system("pause");
	return 0;
}
//Soru 3
/*
void ikiKatinaCikar(int* p)
{
	*p *= 2;	
}
*/



