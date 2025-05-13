// bbdol.cpp - Fonksiyon implementasyonlarý
#include "bbdol.h"
#include <iostream>
#include <ctime>
using namespace std;

node* newnode(){
	node* newnode = new node;
	newnode->llink = NULL;
	newnode->rlink = NULL;
	cout << "Lütfen node'un datasýný giriniz:";
	cin >> newnode->data;
	return (newnode);
}
void inserttree(node*& tree , node* node_)
{
	if(tree == NULL){
		tree = node_;
		return;
	}
	if(node_->data < tree->data)
	{
		inserttree(tree->llink , node_);
	}
	else{
		if(node_->data > tree->data)
		inserttree(tree->rlink,node_);
	}
}
void printtree(node* tree)
{
	if(tree->llink != NULL){
		printtree(tree->llink);
	}
		cout << tree->data << endl;
	/*
	cout << tree << endl;
	cout << tree->llink << endl;
	cout << tree->rlink << endl;*/
	if(tree->rlink != NULL){
		printtree(tree->rlink);
	}
}
int say(node* tree , int& yaprakSayisi){
	if(tree == NULL)
	{
		return 0;
	}
	else
	{
		if((tree->llink == NULL && tree->rlink == NULL))
		{
			yaprakSayisi++;
			return 1;
		}
		else
		{
			return (1+say(tree->llink,yaprakSayisi)+say(tree->rlink, yaprakSayisi));
		}
		
	}

}
