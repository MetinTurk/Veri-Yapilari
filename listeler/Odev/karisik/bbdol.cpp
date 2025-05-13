// bbdol.cpp
#include "bbdol.h"
#include <iostream>
using namespace std;

node* newnode() {
    node* n = new node;
    n->data = 0;
    n->link = n;
    return n;
}

node* last(node* list)
{
	node* last = NULL;
	if(list!=NULL)
	{
		node* ylist = list;
		while(list->link!=ylist)
		list = list->link;
		last = list;
	}
	return last;
}

node* addhead(node* node_ , node*& list) 
{
	if(list!= NULL)
	{
		node_->link = list;
		last(list)->link = node_;
		list = node_;
	}
	else
	list=node_;
	return list;
    
}

node* cutlast(node*& list)
{
	node* cutlast = NULL;
	if(list != NULL)
	{
		node* point = list;
		if(point->link== point)
		{
			cutlast = point;
			list = NULL;
			return cutlast;
		}
		else
		{
			node* ylist = list;
			node* onceki = NULL;
			do
			{
				onceki = point;
				point = point->link;
			}while(point->link != ylist);
			cutlast = point;
			onceki->link = ylist;
			cutlast->link = cutlast;
		}
	}
	return cutlast;
}

node* cons(int data_)
{
	node* list = newnode();
	list->data = data_;
	return list;
}

node* donustur(node* list)
{
	if(list!=NULL)
	{
		if(list->link != list)
		{
			last(list)->link = NULL;
		}
		else
		list->link= NULL;
	}
	return list;
}

bool karsilastir(node* list , node* l1)
{
	bool karsilastir = true;
	if(list!=NULL && l1 != NULL)
	{
		node* ylist = list;
		while(list!=NULL&& l1!=NULL)
		{
			if(list->data == l1->data)
			{
				list = list->link;
				l1 = l1->link;
			}
			else
			{
				karsilastir = false;
				break;
			}
		}
	}
	bool ikisideBittiMi = (list == NULL && l1 == NULL);
	return (karsilastir && ikisideBittiMi);
}

int ortalama(node* list)
{
	int ortalama = 0;
	if(list != NULL)
	{
		int toplam = 0 , sayac = 0;
		node* ylist = list;
		do
		{
			toplam += list->data;
			sayac++;
			list = list->link;
		}while(list!=ylist);
		ortalama = toplam / sayac;
	}
	return ortalama;
}

// ÖDEV 1
/*
node* cutlast(node*& list) {
    if (!list || !list->link) {
        node* temp = list;
        list = NULL;
        return temp;
    }
    node* current = list;
    while (current->link->link)
        current = current->link;
    node* last = current->link;
    current->link = NULL;
    return last;
}
*/
/*
// ÖDEV 2
void ogrencisorgula(ogrenci* sinif, short yas) {
    int sayac = 0;
    while (sinif) {
        if (sinif->yas == yas) {
            sayac++;
            cout << sinif->ad << " " << sinif->soyad << " No: " << sinif->no << " Yas: " << sinif->yas << endl;
        }
        sinif = sinif->next;
    }
    cout << "Toplam " << yas << " yasinda ogrenci sayisi: " << sayac << endl;
}

// ÖDEV 3
node* donustur(node* dlist) {
    if (!dlist) return NULL;
    node* newlist = NULL;
    node* tail = NULL;
    node* start = dlist;
    do {
        node* temp = newnode(dlist->data);
        if (!newlist) newlist = tail = temp;
        else {
            tail->link = temp;
            tail = temp;
        }
        dlist = dlist->link;
    } while (dlist != start);
    return newlist;
}

// ÖDEV 4
bool karsilastir(node* l1, node* l2) {
    while (l1 && l2) {
        if (l1->data != l2->data) return false;
        l1 = l1->link;
        l2 = l2->link;
    }
    return (!l1 && !l2);
}

// ÖDEV 5
double ortalamaal(node* dlist) {
    if (!dlist) return 0;
    int sum = 0, count = 0;
    node* start = dlist;
    do {
        sum += dlist->data;
        count++;
        dlist = dlist->link;
    } while (dlist != start);
    return (double)sum / count;
}

// ÖDEV 6
kitap* kalinkitap(kitap* kutuphane) {
    if (!kutuphane) return NULL;
    kitap* max = kutuphane;
    kutuphane = kutuphane->next;
    while (kutuphane) {
        if (kutuphane->sayfa_sayisi > max->sayfa_sayisi) {
            max = kutuphane;
        }
        kutuphane = kutuphane->next;
    }
    return max;
}

// ÖDEV 7
kitap* kalinkitap_recursive(kitap* kutuphane) {
    if (!kutuphane || !kutuphane->next) return kutuphane;
    kitap* max_rest = kalinkitap_recursive(kutuphane->next);
    return (kutuphane->sayfa_sayisi > max_rest->sayfa_sayisi) ? kutuphane : max_rest;
}
/*
node* cutlast(node*& list)
{
	node* cutlast = NULL;
	if(list!=NULL)
	{
		if(list->link!=list)
		{
			node* ylist = list;
			do{
				list = list->link;
			}while(list->link != ylist);
			cutlast = list;
			list = ylist;
			do
			{
				list = list->link;
			}while(list->link!=cutlast);
			list->link = ylist;
			cutlast->link = cutlast;
		}
		else
		{
			cutlast = list;
			list = NULL;
		}
		
	}
	return cutlast;
}
*/






































