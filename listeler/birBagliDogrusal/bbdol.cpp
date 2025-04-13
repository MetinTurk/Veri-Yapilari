//bbdol.cpp Dosyasý
#include <iostream>
#include <locale.h>
#include <conio.h>
#include "bbdol.h"

using namespace std;



void dumplist(node* list)
{
	int i = 1;
	while(list != NULL)
	{
		cout << "Listenin " << i++ << ". Nodunun Adresi= " << list 
							<<" Datasi=" << list -> data
							<<" Linki = " << list -> link << endl;
		list = list -> link;
	}
}
//--------------------------------------------
node* newnode()
{
	node* newnode = new node;
	newnode->data = 0;
	newnode -> link = NULL;
	return(newnode);
}
//--------------------------------------------
node* last(node* list)
{
	if(list != NULL)
	{
		while(list -> link != NULL)
		{
			list = list -> link;
		}
	}
	node* last = list;
	return(last);
}
//-------------------------------------------
void addhead(node* node_ , node*& list)
{
	node_ -> link = list;
	list = node_;
}
//------------------------------------------

void concatenate(node*& l1 , node* l2)
{
	if(l1 == NULL)
	{
		l1 = l2;
	}
	else
	{
		last(l1) -> link = l2;
	}
}
//------------------------------------------

node* cons(int data_)
{
	node* l1 = newnode();
	l1 -> data = data_;
	return(l1);
}
//-----------------------------------------

node* copy(node* list)
{
	node* l1 = NULL;
	if(list != NULL)
	{
		do
		{
			concatenate(l1 , cons(list -> data));
			list = list -> link;
		}while(list != NULL);
	}
	return(l1);
}
//-----------------------------------------

node* locate(int data_ , node* list)
{
	node* locate = NULL;
	while(list != NULL)
	{
		if(list -> data != data_)
		{
			list = list -> link;
		}
		else
		{
			locate = list;
			break;
		}
	}
	return(locate);
}
//----------------------------------------

bool member(node* node_ , node* list)
{
	while(list != NULL && list != node_)
	{
		list = list -> link;
	}
	bool member = (list == node_);
	return member;
}

node* cuthead(node*& list)
{
	node* cuthead = list;
	if(list != NULL)
	{
		list = list -> link;
		cuthead -> link = NULL;
	}
	return(cuthead);
}
//---------------------------------------

void cutlast(node*& list)
{
	node* sonnode = last(list);
	node* baslangic = list;
	while(list != NULL)
	{
		if(list -> link == sonnode)
		{
			list -> link = NULL;
		}
		else
		{
			list = list -> link;
		}
	}
	list = baslangic;
}
//--------------------------------------

void free(node*& list)
{
	delete list;
}
//-------------------------------------

bool advance(node*& list)
{
	bool advance = false;
	if(list != NULL && list -> link != NULL)
	{
		list = list -> link;
		advance = true;
	}
	return(advance);
}
//---------------------------------------------------

bool deletenode(node* node_ , node*& list)
{
	bool deletenode = false;
	if(list == NULL)
	{
		return(deletenode);
	}
	if(list == node_)
	{
		node* silinecek = cuthead(list);
		free(silinecek);
		deletenode = true;
		return(deletenode);
	}
	else
	{
		node* point = list;
		do
		{
			if(point -> link == node_)
			{
				node* silinecek = cuthead(point->link);
				free(silinecek);						//free fonks. bizden gerçek bir deðiþken istiyor.
				deletenode = true;
				return(deletenode);
			}
		}while(advance(point));
		
	}
	return false;
}

int countlist(node* list)
{
	int count = 0;
	if(list == NULL)
	{
		return count;
	}
	else
	{
		count = 1 + countlist(list -> link);
	}
}

int countlist1(node* list)
{
	int count = 0;
	if(list != NULL)
	{
		count = 1+ countlist(list->link);
	}
	return count;
}

void countlist2(int& count , node* list)
{
	if(list != NULL)
	{
		countlist2(count , list->link);
		count = 1 + count;
	}
}

int totallist(node* list)
{
	int total = 0;
	if(list == NULL)
	{
		return total;
	}
	else
	{
		total = list->data + totallist(list->link);
	}
	return total;
}

void totallist2(int& toplam , node* list)
{
	if(list!=NULL)
	{
		totallist2(toplam , list -> link);
		toplam = list -> data + toplam;
	}
}



















