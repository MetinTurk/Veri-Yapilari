#include "bbdol.h"
#include <iostream>

using namespace std;

void dumplist(node* list)
{
	node* ylist = list;
	int i = 1;
	if(list != NULL)
	do
	{
		cout << i++ << ". nodun Adresi: " << list << " Datasi: " << list->data << " Adresi: " << list->link << endl;
		list = list->link;
	}while(list != ylist);
}

node* newnode()
{
	node* newnode = new node;
	newnode->data = 0;
	newnode->link = newnode;
	return(newnode);
}

node* last(node* list)
{
	node* ylist = list;
	if(list!=NULL)
	while(list->link!=ylist)
	list = list -> link;	
	node* last = list;
	return(last);
}

node* addhead(node* node_ , node* &list)
{
	if(list == NULL)
	list = node_;
	else
	{
		node_->link = list;
		last(list)->link = node_;
		list = node_;
	}
	return list;
}

void concatenate(node* &l1 , node* l2)
{
	if(l1!=NULL)
	{
		if(l2!=NULL)
		{
			last(l1)->link = l2;
			last(l2)->link = l1;
		}
	}
	else l1 = l2;
}

node* cons(int data_)
{
	node* l1 = newnode();
	l1->data = data_;
	return l1;
}

node* copy(node* list)
{
	node* ylist = list;
	node* suret = NULL;
	if(list != NULL)
	do
	{
		concatenate(suret , cons(list->data));
		list = list->link;
	}while(list != ylist);
	return(suret);
}

node* locate(int data_ , node* list)
{
	node* ylist = list;
	node* locate = NULL;
	if(list != NULL)
	do
	{
		if(list->data != data_)
		list = list->link;
		else
		{
			locate = list;
			locate->link = NULL;
			break;
		}
	}while(list!=ylist);
	return locate;
}

bool member(node* node_ , node* list)
{
	bool member = false;
	if(list!=NULL)
	{
		node* ylist = list;
		do
		{
			if(list != node_)
			list = list->link;
			else
			{
				member=true;	
			}
		}while(list != ylist);
	}
	return member;
}

node* cuthead(node* list)
{
	node* cuthead = list;
	if(list!=NULL)
	{
		list = list->link;
		last(list)->link = list;
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
	if(list->link != list)
	{
		list = list->link;
		advance = true;
	}
	return advance;
}

bool deletenode(node* node_ , node* list)
{
	bool deletenode = false;
	if(list == NULL) return deletenode;
	if(list == node_)
	{
		if(list->link == list)
		{
			node* silinecek = cuthead(list);
			free(silinecek);
			deletenode = true;
			return(deletenode);
		}
		else
		{
		    node* lastNode = list;
		    while (lastNode->link != list)
		        lastNode = lastNode->link;
		
		    node* silinecek = list;
		    list = list->link;
		    lastNode->link = list;
		
		    free(silinecek);
		    deletenode = true;
		}
	}
	else
	{
		node* point = list;
		do
		{
			if(point != node_)
			point = point->link;
			else
			{
				node* silinecek = cuthead(list);
				free(silinecek);
				deletenode = true;
				return deletenode;
			}
		}while(advance(point)&& point!=list);
	}
	return deletenode;
}

