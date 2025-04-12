//bbdol.cpp Dosyasý
#include <iostream>
#include <locale.h>
#include <conio.h>
#include "bbdol.h"

using namespace std;


void dumplist(node* list)
{
	node* ylist = list;
	if(list!=NULL)
	{
		int i = 1;
		do
		{
			cout <<"Listenin " << i++ << ".Nodun Adresi: " << list << " Datasi: " << list->data << " Linki: " << list->link << endl;
			list = list -> link;
		}while(list!=ylist);
	}
}

node* newnode()
{
	node* list = new node;
	list->data = 0;
	list->link = list;
	return(list);
}

node* last(node* list)
{
	node* ylist = list;
	if(list != NULL)
	{
		while(list->link != ylist)
		{
			list = list->link;
		}
	}
	node* last = list;
	return(last);
}

void addhead(node* node_ , node*& list)
{
	if(node_ != NULL)
	{
		if(list == NULL)
		{
			list = node_;
		}
		else
		{
			node_->link = list;
			last(list)->link = node_;
			list = node_;
		}
	}
}

void concatenate(node*& l1 , node* l2)
{
	if(l2 != NULL)
	{
		if(l1 == NULL)
		{
			l1 = l2;
		}
		else
		{
			last(l1)->link = l2;
			last(l2)->link = l1;
		}
	}
}

node* cons(int data_)
{
	node* l1 = newnode();
	l1->data = data_;
	return(l1);
}

node* copy(node* list)
{
	node* ylist = list;
	node* l1 = NULL;
	if(list != NULL)
	{
		do
		{
			node* yeni = cons(list->data);
			concatenate(l1 , yeni);
			cout << list->data << endl;
			list = list -> link;
		}while(list != ylist);
	}
	return(l1);
}

node* locate(int data_ , node* list)
{
	node* ylist = list;
	node* locate = NULL;
	if(list != NULL)
	{
		do
		{
			if(list->data != data_)
			{
				list = list->link;
			}
			else
			{
				locate = list;
				break;
			}
		}while(list != ylist);
	}
	return(locate);
}

bool member(node* node_ , node* list)
{
	bool member = false;
	node* ylist = list;
	if(node_ != NULL)
	{
		if(list != NULL)
		{
			do
			{
				if(list != node_)
				{
					list = list->link;
				}
				else
				{
					member = true;
				}
			}while(list != ylist);
		}
	}
	return(member);
}

node* cuthead(node*& list)
{
	node* cuthead = list;
	if (list != NULL)
	{
		if (list->link == list)
		{
			list = NULL;
		}
		else
		{
			list = list->link;
			last(cuthead)->link = list;
		}
		cuthead->link = cuthead;
	}
	return cuthead;
}


void free(node*& list)
{
	delete list;
	list = NULL;
}

bool advance(node*& list)
{
	bool advance = false;
	if(list != NULL && list->link != NULL)
	{
		list = list->link;
		advance = true;
	}
	return(advance);
}

bool deletenode(node* node_ , node*& list)
{
	bool deletenode = false;
	if(node_ == NULL)
	{
		return(deletenode);
	}
	if(list == node_)
	{
		deletenode = true;
		node* silinecek = cuthead(list);
		free(silinecek);
		return(deletenode);
	}
	else
	{
		node* ylist = list;
		node* point = list;
		do
		{
			if(point->link == node_)
			{
				node* silinecek = cuthead(list);
				free(silinecek);
				deletenode = true;
				return(deletenode);
			}
		}while(advance(point) && ylist != point);
	}
}






