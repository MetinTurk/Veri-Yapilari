#include <iostream>
#include <locale.h>
#include <conio.h>
#include <fstream>
#include <cstring>

using namespace std;

struct Su {
    char marka[30];
    char litre[6];
    int adet;	
};

struct Node {
    Su veri;
    Node* next;
};

Node* bas = NULL;  

void StokEkleme();
void StokListeleme();
void StokArama();
void StokSil();
void StokDuzenle();
void DosyadanAl();
void DosyayaAktar();
bool ListeDenSil(const char* silMarka);

int main(){
	setlocale(LC_ALL , "Turkish");
	
	char menu;
	bool menuAcildiMi = false;
	cout << "Haz�r Su Stok Takip Uygulamas�na Ho�geldiniz...\n" << endl;
	do {
		if(menuAcildiMi) {
			system("cls");
			menuAcildiMi = true;
		}
		DosyadanAl();
		cout << "-*-*-*-*-*-*Merhaba*-*-*-*-*-*" << endl;
		cout << "|    L�tfen Se�im Yap�n�z    |" << endl;
		cout << "|     1- Stok Ekleme         |" << endl;
		cout << "|     2- Stok Listeleme      |" << endl;
		cout << "|     3- Marka Arama         |" << endl;
		cout << "|     4- Stok Silme          |" << endl;
		cout << "|     5- Stok D�zenleme      |" << endl;
		cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
		char secim;
		cin >> secim;
		
		switch(secim) {
			case '1': StokEkleme(); break;
			case '2': StokListeleme(); break;
			case '3': StokArama(); break;
			case '4': StokSil(); break;
			case '5': StokDuzenle(); break;
		}
		
		cout << "Men�ye d�nmek ister misiniz ? (e/h): "; 
		menu = getche();
	} while(menu == 'e' || menu == 'E');
	
	system("pause");
	return 0;
}

void DosyadanAl() {
	Node* gecici = bas;
	while (gecici != NULL) {
		Node* silinecek = gecici;
		gecici = gecici->next;
		delete silinecek;
	}
	bas = NULL;

	FILE* dosya = fopen("sudeposu.dat", "rb");
	if (dosya == NULL) return;

	Su temp;
	while (fread(&temp, sizeof(Su), 1, dosya)) {
		Node* yeni = new Node;
		yeni->veri = temp;
		yeni->next = NULL;

		if (bas == NULL) {
			bas = yeni;
		} else {
			Node* gecici = bas;
			while (gecici->next != NULL)
				gecici = gecici->next;
			gecici->next = yeni;
		}
	}
	fclose(dosya);
}

void DosyayaAktar() {
	FILE* dosya = fopen("sudeposu.dat", "wb");
	if (dosya == NULL) {
		printf("Dosya yazma hatas�!\n");
		return;
	}

	Node* gecici = bas;
	while (gecici != NULL) {
		fwrite(&(gecici->veri), sizeof(Su), 1, dosya);
		gecici = gecici->next;
	}
	fclose(dosya);
}

Su suStok;

void StokEkleme() {
	char secim;
	int adet = 0;

	do {
		bool kontrol = true;
		do {
			cout << "Eklemek istedi�iniz suyun markas�\n1-) Erikli\n2-) Kalabak\n3-) Abant\n4-) Ceysu\nSe�im: ";
			cin >> secim;
			switch (secim) {
				case '1': strcpy(suStok.marka, "Erikli"); kontrol = false; break;
				case '2': strcpy(suStok.marka, "Kalabak"); kontrol = false; break;
				case '3': strcpy(suStok.marka, "Abant"); kontrol = false; break;
				case '4': strcpy(suStok.marka, "Ceysu"); kontrol = false; break;
				default: cout << "Ge�ersiz se�im!\n";
			}
		} while (kontrol);

		kontrol = true;
		do {
			cout << "Eklemek istedi�iniz suyun litresi\n1-) 0.5 Lt\n2-) 1.5 Lt\n3-) 5 Lt\n4-) 20 Lt\nSe�im: ";
			cin >> secim;
			switch (secim) {
				case '1': strcpy(suStok.litre, "0.5 Lt"); kontrol = false; break;
				case '2': strcpy(suStok.litre, "1.5 Lt"); kontrol = false; break;
				case '3': strcpy(suStok.litre, "5 Lt"); kontrol = false; break;
				case '4': strcpy(suStok.litre, "20 Lt"); kontrol = false; break;
				default: cout << "Ge�ersiz se�im!\n";
			}
		} while (kontrol);

		cout << "Ka� adet eklemek istiyorsunuz: ";
		cin >> suStok.adet;

		Node* yeni = new Node;
		yeni->veri = suStok;
		yeni->next = NULL;

		if (bas == NULL) {
			bas = yeni;
		} else {
			Node* gecici = bas;
			while (gecici->next != NULL)
				gecici = gecici->next;
			gecici->next = yeni;
		}

		adet++;
		cout << "Ba�ka stok eklemek istiyor musunuz? (E/H): ";
		secim = getche();
		cout << endl;

	} while (secim == 'e' || secim == 'E');

	cout << adet << " adet stok eklendi.\n";
	DosyayaAktar();
}

void StokListeleme() {
	if (bas == NULL) {
		cout << "Herhangi bir stok kayd� bulunamad�..." << endl;
		return;
	}

	Node* temp = bas;
	int sayac = 1;

	while (temp != NULL) {
		cout << "\n===== " << sayac << ". Stok Bilgileri =====" << endl;
		cout << "Marka: " << temp->veri.marka << endl;
		cout << "Litre: " << temp->veri.litre << endl;
		cout << "Adet : " << temp->veri.adet << " tane" << endl;
		temp = temp->next;
		sayac++;
	}
}

void StokArama() {
	if (bas == NULL) {
		cout << "Stok listesi bo�. �nce stok ekleyiniz.\n";
		return;
	}

	char arananMarka[30];
	bool kontrol = true;
	do {
		char secim;
		cout << "Aramak istedi�iniz suyun markas�\n1-) Erikli\n2-) Kalabak\n3-) Abant\n4-) Ceysu\nSe�im: ";
		cin >> secim;
		switch (secim) {
			case '1': strcpy(arananMarka, "Erikli"); kontrol = false; break;
			case '2': strcpy(arananMarka, "Kalabak"); kontrol = false; break;
			case '3': strcpy(arananMarka, "Abant"); kontrol = false; break;
			case '4': strcpy(arananMarka, "Ceysu"); kontrol = false; break;
			default: cout << "Ge�ersiz se�im!\n";
		}
	} while (kontrol);

	bool bulundu = false;
	Node* gecici = bas;

	while (gecici != NULL) {
		if (strcmp(gecici->veri.marka, arananMarka) == 0) {
			if (!bulundu) {
				cout << "\nBulunan Stok Bilgileri:\n";
				bulundu = true;
			}
			cout << "\nMarka: " << gecici->veri.marka << endl;
			cout << "Litre: " << gecici->veri.litre << endl;
			cout << "Adet : " << gecici->veri.adet << endl;
		}
		gecici = gecici->next;
	}

	if (!bulundu) {
		cout << "\nAranan marka ile e�le�en stok bulunamad�.\n";
	}
}

void StokSil() {
    if (bas == NULL) {
        cout << "Stok listesi bo�. �nce stok ekleyiniz.\n";
        return;
    }

    char silinecekMarka[30];
    char secim;
    bool kontrol = true;

    do {
        cout << "Silmek istedi�iniz suyun markas�:\n"
             << "1-) Erikli\n2-) Kalabak\n3-) Abant\n4-) Ceysu\nSe�im: ";
        cin >> secim;
        switch (secim) {
            case '1': strcpy(silinecekMarka, "Erikli"); kontrol = false; break;
            case '2': strcpy(silinecekMarka, "Kalabak"); kontrol = false; break;
            case '3': strcpy(silinecekMarka, "Abant"); kontrol = false; break;
            case '4': strcpy(silinecekMarka, "Ceysu"); kontrol = false; break;
            default: cout << "Ge�ersiz se�im!\n";
        }
    } while (kontrol);

    Node* gecici = bas;
    bool bulundu = false;

    while (gecici != NULL) {
        if (strcmp(gecici->veri.marka, silinecekMarka) == 0) {
            cout << "\nBulunan Stok Bilgisi:\n";
            cout << "Marka: " << gecici->veri.marka << endl;
            cout << "Litre: " << gecici->veri.litre << endl;
            cout << "Adet : " << gecici->veri.adet << endl;

            cout << "\nBu kayd� silmek istiyor musunuz? (E/H): ";
            char onay;
            cin >> onay;

            if (onay == 'E' || onay == 'e') {
                bulundu = ListeDenSil(gecici->veri.marka); 
                break; 
            }
        }
        gecici = gecici->next;
    }

    if (bulundu) {
        DosyayaAktar(); 
        cout << "\nKay�t ba�ar�yla silindi.\n";
    } else {
        cout << "\nSilme i�lemi iptal edildi veya marka bulunamad�.\n";
    }
}


void StokDuzenle() {
    if (bas == NULL) {
        cout << "Stok listesi bo�. �nce stok ekleyiniz.\n";
        return;
    }

    char arananMarka[30];
    char secim;
    bool kontrol = true;
    do {
        cout << "D�zenlemek istedi�iniz suyun markas�:\n"
             << "1-) Erikli\n2-) Kalabak\n3-) Abant\n4-) Ceysu\nSe�im: ";
        cin >> secim;
        switch (secim) {
            case '1': strcpy(arananMarka, "Erikli"); kontrol = false; break;
            case '2': strcpy(arananMarka, "Kalabak"); kontrol = false; break;
            case '3': strcpy(arananMarka, "Abant"); kontrol = false; break;
            case '4': strcpy(arananMarka, "Ceysu"); kontrol = false; break;
            default: cout << "Ge�ersiz se�im!\n";
        }
    } while (kontrol);

    Node* gecici = bas;
    bool bulundu = false;

    while (gecici != NULL) {
        if (strcmp(gecici->veri.marka, arananMarka) == 0) {
            cout << "\nBulunan Stok Bilgisi:\n";
            cout << "Marka: " << gecici->veri.marka << endl;
            cout << "Litre: " << gecici->veri.litre << endl;
            cout << "Adet : " << gecici->veri.adet << endl;

            cout << "\nBu kayd� d�zenlemek istiyor musunuz? (E/H): ";
            char onay;
            cin >> onay;

            if (onay == 'E' || onay == 'e') {
                bulundu = true;
                kontrol = true;
                do {
                    cout << "Yeni marka se�iniz:\n"
                         << "1-) Erikli\n2-) Kalabak\n3-) Abant\n4-) Ceysu\nSe�im: ";
                    cin >> secim;
                    switch (secim) {
                        case '1': strcpy(gecici->veri.marka, "Erikli"); kontrol = false; break;
                        case '2': strcpy(gecici->veri.marka, "Kalabak"); kontrol = false; break;
                        case '3': strcpy(gecici->veri.marka, "Abant"); kontrol = false; break;
                        case '4': strcpy(gecici->veri.marka, "Ceysu"); kontrol = false; break;
                        default: cout << "Ge�ersiz se�im!\n";
                    }
                } while (kontrol);

                kontrol = true;
                do {
                    cout << "Yeni litre se�iniz:\n"
                         << "1-) 0.5 Lt\n2-) 1.5 Lt\n3-) 5 Lt\n4-) 20 Lt\nSe�im: ";
                    cin >> secim;
                    switch (secim) {
                        case '1': strcpy(gecici->veri.litre, "0.5 Lt"); kontrol = false; break;
                        case '2': strcpy(gecici->veri.litre, "1.5 Lt"); kontrol = false; break;
                        case '3': strcpy(gecici->veri.litre, "5 Lt"); kontrol = false; break;
                        case '4': strcpy(gecici->veri.litre, "20 Lt"); kontrol = false; break;
                        default: cout << "Ge�ersiz se�im!\n";
                    }
                } while (kontrol);

                cout << "Yeni adet giriniz: ";
                cin >> gecici->veri.adet;

                cout << "\nKay�t ba�ar�yla g�ncellendi.\n";
                DosyayaAktar();
                break;
            }
        }
        gecici = gecici->next;
    }

    if (!bulundu) {
        cout << "\nAranan marka ile ilgili kay�t bulunamad� veya d�zenleme iptal edildi.\n";
    }
}

bool ListeDenSil(const char* silMarka) {
    if (bas == NULL) return false;

    Node* gecici = bas;
    Node* onceki = NULL;
    bool bulundu = false;

    while (gecici != NULL) {
        if (strcmp(gecici->veri.marka, silMarka) == 0) {
            if (onceki == NULL) {
                bas = gecici->next;
            } else {
                onceki->next = gecici->next;
            }
            delete gecici;
            bulundu = true;
            break;
        }
        onceki = gecici;
        gecici = gecici->next;
    }

    return bulundu;
}



