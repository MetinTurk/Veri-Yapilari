#include <iostream>
#include <locale.h>
#include <conio.h>
#include <fstream>
#include <cstring>

using namespace std;

struct Su
{
	char marka[30];
	
	char litre[6];
	int adet;	
};

void StokEkleme();
void StokListeleme();
void StokArama();
void StokSil();
void StokDuzenle();



int main(){
	setlocale(LC_ALL , "Turkish");
	
	
	char menu;
	bool menuAcildiMi = false;
	cout << "Hazýr Su Stok Takip Uygulamasýna Hoþgeldiniz...\n" << endl;
	do{
	if(menuAcildiMi)
	system("cls");
	menuAcildiMi = true;
	cout << "-*-*-*-*-*-*Merhaba*-*-*-*-*-*"<< endl ;
	cout << "|    Lütfen Secim Yapiniz    |"<< endl ;
	cout << "|     1- Stok Ekleme   	     |"<< endl ;
	cout << "|     2- Stok Listeleme      |"<< endl ;
	cout << "|     3- Marka Arama         |"<< endl;
	cout << "|     4- Stok Silme          |"<< endl;
	cout << "|     5- Stok Duzenleme      |"<< endl;
	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl ;
    char secim;
	cin>> secim;
	
	switch(secim) 
	{
		case '1' : 
		{
			StokEkleme();
		break;	
		}
		case '2' : 
		{
		 StokListeleme();
		 break;
		}
		case '3' : 
		{
		 StokArama();
		 break;
		}
		case '4' : 
		{
		 StokSil();
		 break;
		}
		case '5' : 
		{
		 StokDuzenle();
		 break;
		}
	}
	
	cout << "Menuye dönmek ister misiniz ? (e/h): "; 
	menu=getche();
	
    }while(menu=='e');
	
	
	system("pause");
	return 0;
}

Su suStok;

void StokEkleme() {
    ofstream yaz("suStok.dat", ios::binary | ios::app);
    int adet = 0;
    char secim;

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

        yaz.write((char*)&suStok, sizeof(suStok));
        adet++;

        cout << "Baþka stok eklemek istiyor musunuz? (E/H): ";
        secim = getche();
        cout << endl;

    } while (secim == 'e' || secim == 'E');

    cout << adet << " adet stok eklendi.\n";
    yaz.close();
}



void StokListeleme() {
    ifstream oku("suStok.dat", ios::binary);
    
    oku.seekg(0, ios::end);
    int kayitSayisi = oku.tellg() / sizeof(Su);
    cout << "\nToplam Stok Kaydý Sayýsý: " << kayitSayisi << endl;

    if (kayitSayisi > 0) {
        oku.seekg(0, ios::beg);

        Su stok;
        for (int i = 0; i < kayitSayisi; i++) {
            oku.read((char*)&stok, sizeof(Su));
            cout << "\n" << i + 1 << ". Stok Bilgileri" << endl;
            cout << "Marka: " << stok.marka << endl;
            cout << "Litre: " << stok.litre << endl;
            cout << "Adet : " << stok.adet << " tane" << endl;
        }
    }
    else {
        cout << "Herhangi bir stok kaydý bulunamadý..." << endl;
    }

    oku.close();
}

void StokArama() {
    ifstream oku("suStok.dat", ios::binary);
    
    oku.seekg(0, ios::end);
    int kayitSayisi = oku.tellg() / sizeof(Su);
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

    if (kayitSayisi > 0) {
        oku.seekg(0, ios::beg); 

        Su stok;
        for (int i = 0; i < kayitSayisi; i++) {
            oku.read((char*)&stok, sizeof(Su));

            if (strcmp(stok.marka, arananMarka) == 0) {
                if (!bulundu) {
                    cout << "\nBulunan Stok Bilgileri:\n";
                    bulundu = true;
                }
                cout << "\nMarka: " << stok.marka << endl;
                cout << "Litre: " << stok.litre << endl;
                cout << "Adet : " << stok.adet << endl;
            }
        }

        if (!bulundu) {
            cout << "\nAranan marka ile eþleþen stok bulunamadý.\n";
        }
    } else {
        cout << "\nStok verisi bulunamadý.\n";
    }

    oku.close();
}

void StokSil() {
    char marka[30];
    char secim = ' ';
    bool bulundu = false;

    ifstream oku("suStok.dat", ios::binary);
    if (!oku) {
        cout << "Stok dosyasý açýlamadý!" << endl;
        return;
    }

    oku.seekg(0, ios::end);
    int kayitSayisi = oku.tellg() / sizeof(Su);
    oku.seekg(0, ios::beg);

	bool kontrol = true;
    do {
    	char secim;
        cout << "Silmek istediðiniz suyun markasý\n1-) Erikli\n2-) Kalabak\n3-) Abant\n4-) Ceysu\nSeçim: ";
        cin >> secim;
        switch (secim) {
            case '1': strcpy(marka, "Erikli"); kontrol = false; break;
            case '2': strcpy(marka, "Kalabak"); kontrol = false; break;
            case '3': strcpy(marka, "Abant"); kontrol = false; break;
            case '4': strcpy(marka, "Ceysu"); kontrol = false; break;
            default: cout << "Geçersiz seçim!\n";
            }
        } while (kontrol);

    ofstream yedek("Yedek.dat", ios::binary);
    Su stok;

    for (int i = 0; i < kayitSayisi; i++) {
        oku.read((char*)&stok, sizeof(Su));

        if (strcmp(stok.marka, marka) == 0) {
            cout << "\nBulunan Stok Bilgisi:" << endl;
            cout << "Marka: " << stok.marka << endl;
            cout << "Litre: " << stok.litre << endl;
            cout << "Adet : " << stok.adet << endl;
            cout << "\nBu kaydý silmek istiyor musunuz? (E/H): ";
            secim = getche();
            cout << endl;

            if (secim == 'E' || secim == 'e') {
                bulundu = true;
                continue; 
            }
        }

        yedek.write((char*)&stok, sizeof(Su));
    }

    oku.close();
    yedek.close();

    if (bulundu) {
        remove("suStok.dat");
        rename("Yedek.dat", "suStok.dat");
        cout << "\nKayýt baþarýyla silindi.\n";
    } else {
        remove("Yedek.dat");
        cout << "\nAranan marka ile eþleþen kayýt bulunamadý.\n";
    }
}

void StokDuzenle() {
    char arananMarka[30];
    char secim = ' ';
    bool bulundu = false;

    ifstream oku("suStok.dat", ios::binary);
    if (!oku) {
        cout << "Stok dosyasý açýlamadý!" << endl;
        return;
    }

    oku.seekg(0, ios::end);
    int kayitSayisi = oku.tellg() / sizeof(Su);
    oku.seekg(0, ios::beg);

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

    ofstream yedek("Yedek.dat", ios::binary);
    Su stok;

    for (int i = 0; i < kayitSayisi; i++) {
        oku.read((char*)&stok, sizeof(Su));

        if (strcmp(stok.marka, arananMarka) == 0) {
            cout << "\nBulunan Stok Bilgisi:" << endl;
            cout << "Marka: " << stok.marka << endl;
            cout << "Litre: " << stok.litre << endl;
            cout << "Adet : " << stok.adet << endl;

            cout << "\nBu kaydý düzenlemek istiyor musunuz? (E/H): ";
            secim = getche();
            cout << endl;

            if (secim == 'E' || secim == 'e') {
                bulundu = true;

                
		        bool kontrol = true;
		        do {
		            cout << "Eklemek istediðiniz suyun markasý\n1-) Erikli\n2-) Kalabak\n3-) Abant\n4-) Ceysu\nSeçim: ";
		            cin >> secim;
		            switch (secim) {
		                case '1': strcpy(stok.marka, "Erikli"); kontrol = false; break;
		                case '2': strcpy(stok.marka, "Kalabak"); kontrol = false; break;
		                case '3': strcpy(stok.marka, "Abant"); kontrol = false; break;
		                case '4': strcpy(stok.marka, "Ceysu"); kontrol = false; break;
		                default: cout << "Geçersiz seçim!\n";
		            }
		        } while (kontrol);
		
		        kontrol = true;
		        do {
		            cout << "Eklemek istediðiniz suyun litresi\n1-) 0.5 Lt\n2-) 1.5 Lt\n3-) 5 Lt\n4-) 20 Lt\nSeçim: ";
		            cin >> secim;
		            switch (secim) {
		                case '1': strcpy(stok.litre, "0.5 Lt"); kontrol = false; break;
		                case '2': strcpy(stok.litre, "1.5 Lt"); kontrol = false; break;
		                case '3': strcpy(stok.litre, "5 Lt"); kontrol = false; break;
		                case '4': strcpy(stok.litre, "20 Lt"); kontrol = false; break;
		                default: cout << "Geçersiz seçim!\n";
		            }
		        } while (kontrol);
		
		        cout << "Kaç adet eklemek istiyorsunuz: ";
		        cin >> stok.adet;

                yedek.write((char*)&stok, sizeof(Su));
                continue;
            }
        }

        yedek.write((char*)&stok, sizeof(Su));
    }

    oku.close();
    yedek.close();

    if (bulundu) {
        remove("suStok.dat");
        rename("Yedek.dat", "suStok.dat");
        cout << "\nKayýt baþarýyla güncellendi.\n";
    } else {
        remove("Yedek.dat");
        cout << "\nAranan marka ile eþleþen kayýt bulunamadý.\n";
    }
}

