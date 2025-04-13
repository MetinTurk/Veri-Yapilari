//bbdol.h dosyasý
#ifndef BBDOL_H
#define BBDOL_H

struct node {
    int data;
    node* link;
};

// Fonksiyon prototipleri
void dumplist(node* list);
node* newnode();
node* last(node* list);
void addhead(node* node_, node*& list);
void concatenate(node*& l1 , node* l2);
node* cons(int data_);
node* copy(node* list);
node* locate(int data_ , node* list);
bool member(node * node_ , node* list);
node* cuthead(node*& list);
void cutlast(node*& list);
void free(node*& list);
bool advance(node*& list);
bool deletenode(node* node_ , node*& list);
int countlist(node* list);
int countlist1(node* list);
int totallist(node* list);
void countlist2(int& count , node* list);
void totallist2(int& toplam , node* list);
node* creatlist();
node* findmiddle(int boyut , node* list);
node* reverscopy(node* list);
void clearlist(node*& list);
int countdata(int data_ , node* list);
bool ispalidrome(node* list);
bool search(int data_ , node* list , bool isFound = false)

#endif

