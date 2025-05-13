// bbdol.h - B_TreeVeriYapisi
#ifndef BBDOL_H
#define BBDOL_H

#include <iostream>
#include <cstdlib>

struct node{
	int data;
	struct node * llink , * rlink;
};


node* newnode();
void inserttree(node*& tree , node* node_);
void printtree(node* tree);
int say(node* tree , int& yaprakSayisi);


#endif // BBDOL_H
