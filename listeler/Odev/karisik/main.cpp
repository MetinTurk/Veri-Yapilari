// main.cpp
#include <iostream>
#include "bbdol.h"
#include <locale.h>
using namespace std;

int main(int argc, char** argv) {
    setlocale(LC_ALL , "Turkish");
    
    // ÖDEV 1 
    node* list = NULL;
	list = addhead(cons(20), list);
	list = addhead(cons(30), list);
	list = addhead(cons(40), list);
	cout << "ortalamasi: " << ortalama(list) << endl;
	
	/*
	node* kesilen = cutlast(list);
	if (kesilen != NULL)
	    cout << "Kesilen veri: " << kesilen->data << endl;
	*/
/*
    // ÖDEV 2 
    ogrenci* sinif = new ogrenci{"Ali", "Yılmaz", "101", 22, NULL};
    sinif->next = new ogrenci{"Ayşe", "Demir", "102", 22, NULL};
    sinif->next->next = new ogrenci{"Emre", "Kaya", "103", 23, NULL};
    ogrencisorgula(sinif, 22);

    // ÖDEV 3 
    node* dlist = newnode(7);
    dlist->link = newnode(14);
    dlist->link->link = newnode(21);
    dlist->link->link->link = dlist; 
    node* ylist = donustur(dlist);
    while (ylist) {
        cout << ylist->data << " ";
        ylist = ylist->link;
    }
    cout << endl;

    // ÖDEV 4 
    node* a = NULL;
    a = addhead(a, 10);
    a = addhead(a, 20);
    node* b = NULL;
    b = addhead(b, 10);
    b = addhead(b, 20);
    if (karsilastir(a, b))
        cout << "Listeler eşit: Evet" << endl;
    else
        cout << "Listeler eşit: Hayır" << endl;

    // ÖDEV 5 
    node* c = newnode(5);
    c->link = newnode(10);
    c->link->link = newnode(15);
    c->link->link->link = c;
    cout << "Liste elemanlarının ortalaması: " << ortalamaal(c) << endl;

    // ÖDEV 6 
    kitap* k = new kitap{500, "Kitap A", NULL};
    k->next = new kitap{600, "Kitap B", NULL};
    k->next->next = new kitap{450, "Kitap C", NULL};
    kitap* kalin = kalinkitap(k);
    if (kalin != NULL)
        cout << "En kalın kitap: " << kalin->kitap_adi << endl;

    // ÖDEV 7 
    kitap* kalin_r = kalinkitap_recursive(k);
    if (kalin_r != NULL)
        cout << "Recursive en kalın kitap: " << kalin_r->kitap_adi << endl;
*/
    return 0;
}
