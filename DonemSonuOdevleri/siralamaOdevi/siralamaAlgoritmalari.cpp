#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int diziKopya(int sayilar[300], int kopyaDizi[300])
{
	for(int i = 0; i< 300; i++){
		kopyaDizi[i] = sayilar[i];
	}
}
void diziOlustur(int sayilar[300])
{
	int adet = 0;

    while (adet < 300) {
        int yeniSayi = rand() % 5001 + 0; 

        
        bool varMi = false;
        for (int i = 0; i < adet; i++) {
            if (sayilar[i] == yeniSayi) {
                varMi = true;
                break;
            }
        }

        if (!varMi) {
            sayilar[adet] = yeniSayi;
            adet++;
        }
    }
}

void diziYazdir(int sayilar[300]){
	for(int i = 0 ; i < 300; i++){
		cout << i + 1 << ". sayý: " << sayilar[i] << endl;
	}
}

void bubbleSort(int dizi[], int n) {
	int sayac = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
        	sayac++;
            if (dizi[j] > dizi[j + 1]) {
                int temp = dizi[j];
				dizi[j] = dizi[j + 1];
				dizi[j + 1] = temp;
            }
        }
    }
    cout << "bubble sort algoritmasý " << sayac << " kere döngüye girdi" << endl;
}


int mergeSortSayac = 0; 

void merge(int dizi[], int sol, int orta, int sag) {
    int n1 = orta - sol + 1;
    int n2 = sag - orta;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = dizi[sol + i];
        mergeSortSayac++; 
    }

    for (int j = 0; j < n2; j++) {
        R[j] = dizi[orta + 1 + j];
        mergeSortSayac++; 
    }

    int i = 0, j = 0, k = sol;

    while (i < n1 && j < n2) {
        mergeSortSayac++; 
        if (L[i] <= R[j]) {
            dizi[k++] = L[i++];
        } else {
            dizi[k++] = R[j++];
        }
    }

    while (i < n1) {
        dizi[k++] = L[i++];
        mergeSortSayac++;
    }

    while (j < n2) {
        dizi[k++] = R[j++];
        mergeSortSayac++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int dizi[], int sol, int sag) {
    if (sol < sag) {
        int orta = sol + (sag - sol) / 2;
        mergeSort(dizi, sol, orta);
        mergeSort(dizi, orta + 1, sag);
        merge(dizi, sol, orta, sag);
    }
}


void selectionSort(int dizi[], int n) {
	int sayac = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
        	sayac++;
            if (dizi[j] < dizi[minIndex]) {
                minIndex = j;
            }
        }
        int temp = dizi[i];
		dizi[i] = dizi[minIndex];
		dizi[minIndex] = temp;
    }
    cout << "selection sort algoritmasý " << sayac << " kere döngüye girdi" << endl;
}



int main()
{
	setlocale(LC_ALL ,"Turkish");
	
	srand(time(0)); 

    int sayilar[300];
    
	diziOlustur(sayilar);
	
	int kopyaSayilar1[300];
	diziKopya(sayilar , kopyaSayilar1);
	
	int kopyaSayilar2[300];
	diziKopya(sayilar , kopyaSayilar2);
	
	bubbleSort(kopyaSayilar1, 300);
	selectionSort(kopyaSayilar2, 300);
	
	mergeSortSayac = 0; 
    mergeSort(sayilar, 0, 299);

    cout << "merge sort algoritmasý " << mergeSortSayac << " kere döngüye girdi" << endl;
    
    diziYazdir(sayilar);
	
	
	system("pause");
	return 0;
}
