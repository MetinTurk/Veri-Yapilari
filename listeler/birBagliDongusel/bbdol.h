//bbdol.h dosyas�
#ifndef BBDOL_H
#define BBDOL_H

struct node {
    int data;
    node* link;
};

void dumplist(node* list);
node* newnode();
node* last(node* list);
void addhead(node* node_ , node*& list);
void concatenate(node*& l1 , node* l2);
node* cons(int data_);
node* copy(node* list);
node* locate(int data_ , node* list);
bool member(node* node_ , node* list);
node* cuthead(node*& list);
void free(node*& list);
bool advance(node*& list);
bool deletenode(node* node_ , node*& list);
//int countlist(node* list);




#endif

