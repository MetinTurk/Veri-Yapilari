// bbdol.h
#ifndef BBDOL_H
#define BBDOL_H

#include <string>
using namespace std;

struct node {
    int data;
    node* link;
};

struct ogrenci {
    string ad;
    string soyad;
    string no;
    short yas;
    ogrenci* next;
};

struct kitap {
    int sayfa_sayisi;
    string kitap_adi;
    kitap* next;
};

node* newnode();
node* addhead(node* node_ , node*& list);
node* last(node* list);
node* cutlast(node*& list);
node* cons(int data_);
int ortalama(node* list);
/*
void ogrencisorgula(ogrenci* sinif, short yas);

node* donustur(node* dlist);

bool karsilastir(node* l1, node* l2);

double ortalamaal(node* dlist);

kitap* kalinkitap(kitap* kutuphane);
kitap* kalinkitap_recursive(kitap* kutuphane);
*/
#endif
