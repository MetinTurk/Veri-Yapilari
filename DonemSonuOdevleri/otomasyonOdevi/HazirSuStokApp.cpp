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
	cout << "Hazýr Su Stok Takip Uygulamasýna Hoþgeldiniz...\n" << endl;
	do {
		if(menuAcildiMi) {
			system("cls");
			menuAcildiMi = true;
		}
		DosyadanAl();
		cout << "-*-*-*-*-*-*Merhaba*-*-*-*-*-*" << endl;
		cout << "|    Lütfen Seçim Yapýnýz    |" << endl;
		cout << "|     1- Stok Ekleme         |" << endl;
		cout << "|     2- Stok Listeleme      |" << endl;
		cout << "|     3- Marka Arama         |" << endl;
		cout << "|     4- Stok Silme          |" << endl;
		cout << "|     5- Stok Düzenleme      |" << endl;
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
		
		cout << "Menüye dönmek ister misiniz ? (e/h): "; 
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
		printf("Dosya yazma hatasý!\n");
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
			cout << "Eklemek istediðiniz suyun markasý\n1-) Erikli\n2-) Kalabak\n3-) Abant\n4-) Ceysu\nSeçim: ";
			cin >> secim;
			switch (secim) {
				case '1': strcpy(suStok.marka, "Erikli"); kontrol = false; break;
				case '2': strcpy(suStok.marka, "Kalabak"); kontrol = false; break;
				case '3': strcpy(suStok.marka, "Abant"); kontrol = false; break;
				case '4': strcpy(suStok.marka, "Ceysu"); kontrol = false; break;
				default: cout << "Geçersiz seçim!\n";
			}
		} while (kontrol);

		kontrol = true;
		do {
			cout << "Eklemek istediðiniz suyun litresi\n1-) 0.5 Lt\n2-) 1.5 Lt\n3-) 5 Lt\n4-) 20 Lt\nSeçim: ";
			cin >> secim;
			switch (secim) {
				case '1': strcpy(suStok.litre, "0.5 Lt"); kontrol = false; break;
				case '2': strcpy(suStok.litre, "1.5 Lt"); kontrol = false; break;
				case '3': strcpy(suStok.litre, "5 Lt"); kontrol = false; break;
				case '4': strcpy(suStok.litre, "20 Lt"); kontrol = false; break;
				default: cout << "Geçersiz seçim!\n";
			}
		} while (kontrol);

		cout << "Kaç adet eklemek istiyorsunuz: ";
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
		cout << "Baþka stok eklemek istiyor musunuz? (E/H): ";
		secim = getche();
		cout << endl;

	} while (secim == 'e' || secim == 'E');

	cout << adet << " adet stok eklendi.\n";
	DosyayaAktar();
}

void StokListeleme() {
	if (bas == NULL) {
		cout << "Herhangi bir stok kaydý bulunamadý..." << endl;
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
		cout << "Stok listesi boþ. Önce stok ekleyiniz.\n";
		return;
	}

	char arananMarka[30];
	bool kontrol = true;
	do {
		char secim;
		cout << "Aramak istediðiniz suyun markasý\n1-) Erikli\n2-) Kalabak\n3-) Abant\n4-) Ceysu\nSeçim: ";
		cin >> secim;
		switch (secim) {
			case '1': strcpy(arananMarka, "Erikli"); kontrol = false; break;
			case '2': strcpy(arananMarka, "Kalabak"); kontrol = false; break;
			case '3': strcpy(arananMarka, "Abant"); kontrol = false; break;
			case '4': strcpy(arananMarka, "Ceysu"); kontrol = false; break;
			default: cout << "Geçersiz seçim!\n";
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
		cout << "\nAranan marka ile eþleþen stok bulunamadý.\n";
	}
}

void StokSil() {
    if (bas == NULL) {
        cout << "Stok listesi boþ. Önce stok ekleyiniz.\n";
        return;
    }

    char silinecekMarka[30];
    char secim;
    bool kontrol = true;

    do {
        cout << "Silmek istediðiniz suyun markasý:\n"
             << "1-) Erikli\n2-) Kalabak\n3-) Abant\n4-) Ceysu\nSeçim: ";
        cin >> secim;
        switch (secim) {
            case '1': strcpy(silinecekMarka, "Erikli"); kontrol = false; break;
            case '2': strcpy(silinecekMarka, "Kalabak"); kontrol = false; break;
            case '3': strcpy(silinecekMarka, "Abant"); kontrol = false; break;
            case '4': strcpy(silinecekMarka, "Ceysu"); kontrol = false; break;
            default: cout << "Geçersiz seçim!\n";
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

            cout << "\nBu kaydý silmek istiyor musunuz? (E/H): ";
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
        cout << "\nKayýt baþarýyla silindi.\n";
    } else {
        cout << "\nSilme iþlemi iptal edildi veya marka bulunamadý.\n";
    }
}


void StokDuzenle() {
    if (bas == NULL) {
        cout << "Stok listesi boþ. Önce stok ekleyiniz.\n";
        return;
    }

    char arananMarka[30];
    char secim;
    bool kontrol = true;
    do {
        cout << "Düzenlemek istediðiniz suyun markasý:\n"
             << "1-) Erikli\n2-) Kalabak\n3-) Abant\n4-) Ceysu\nSeçim: ";
        cin >> secim;
        switch (secim) {
            case '1': strcpy(arananMarka, "Erikli"); kontrol = false; break;
            case '2': strcpy(arananMarka, "Kalabak"); kontrol = false; break;
            case '3': strcpy(arananMarka, "Abant"); kontrol = false; break;
            case '4': strcpy(arananMarka, "Ceysu"); kontrol = false; break;
            default: cout << "Geçersiz seçim!\n";
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

            cout << "\nBu kaydý düzenlemek istiyor musunuz? (E/H): ";
            char onay;
            cin >> onay;

            if (onay == 'E' || onay == 'e') {
                bulundu = true;
                kontrol = true;
                do {
                    cout << "Yeni marka seçiniz:\n"
                         << "1-) Erikli\n2-) Kalabak\n3-) Abant\n4-) Ceysu\nSeçim: ";
                    cin >> secim;
                    switch (secim) {
                        case '1': strcpy(gecici->veri.marka, "Erikli"); kontrol = false; break;
                        case '2': strcpy(gecici->veri.marka, "Kalabak"); kontrol = false; break;
                        case '3': strcpy(gecici->veri.marka, "Abant"); kontrol = false; break;
                        case '4': strcpy(gecici->veri.marka, "Ceysu"); kontrol = false; break;
                        default: cout << "Geçersiz seçim!\n";
                    }
                } while (kontrol);

                kontrol = true;
                do {
                    cout << "Yeni litre seçiniz:\n"
                         << "1-) 0.5 Lt\n2-) 1.5 Lt\n3-) 5 Lt\n4-) 20 Lt\nSeçim: ";
                    cin >> secim;
                    switch (secim) {
                        case '1': strcpy(gecici->veri.litre, "0.5 Lt"); kontrol = false; break;
                        case '2': strcpy(gecici->veri.litre, "1.5 Lt"); kontrol = false; break;
                        case '3': strcpy(gecici->veri.litre, "5 Lt"); kontrol = false; break;
                        case '4': strcpy(gecici->veri.litre, "20 Lt"); kontrol = false; break;
                        default: cout << "Geçersiz seçim!\n";
                    }
                } while (kontrol);

                cout << "Yeni adet giriniz: ";
                cin >> gecici->veri.adet;

                cout << "\nKayýt baþarýyla güncellendi.\n";
                DosyayaAktar();
                break;
            }
        }
        gecici = gecici->next;
    }

    if (!bulundu) {
        cout << "\nAranan marka ile ilgili kayýt bulunamadý veya düzenleme iptal edildi.\n";
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



