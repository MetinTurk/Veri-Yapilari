//main.cpp dosyasý
#include <iostream>
#include "bbdol.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	setlocale(LC_ALL ,"Turkish");
	
	/*
	node* liste = newnode();
	
	cout << liste << endl;
	cout << liste -> data << endl;
	cout << liste -> link << endl;
	
	liste -> data = 5;
	dumplist(liste);
	*/
	/*
	node* list;
	
	node* l1 = cons(25);
	
	concatenate(list , l1);
	dumplist(list);
	
	node* l2 = cons(85);
	concatenate(l1 , l2);
	dumplist(l1);
	*/
	
	/*
	node* list = NULL;
	
	node* l1 = cons(85);
	addhead(cons(25),  l1);
	addhead(cons(47) , l1);
	node* l2 = NULL;
	l2 = copy(l1);	
	dumplist(l1);
	cout << "*-----------------------------*" << endl;
	dumplist(l2);
	cout << bool(member(l1, l2))<< endl;
	if(locate(26 , l1) != NULL)
	{
		cout << "Aradýðýnýz node adresi: " << locate(26 , l1) << endl;
	}
	else
	{
		cout << "Aradýðýnýz node yok." << endl;
	}
	
	cutlast(l2);
	dumplist(l2);
	
	*/
	
	node* l2 = NULL;
	addhead(cons(48) , l2);
	addhead(newnode(), l2);
	addhead(newnode(), l2);
	addhead(newnode(), l2);
	dumplist(l2);
	cout << "-----------------------------------------" << endl;
	if(deletenode(locate(48,l2), l2))
	{
		cout << "Silme iþlemi baþarýlý." << endl;
	}
	else
	{
		cout << "Silme iþlemi baþarýsýz." << endl;
	}
	dumplist(l2);
	
	
	
	
	
	/*
	node* list = NULL;
	
	node* l1 = newnode();
	l1 -> data = 10;
	addhead(l1,list);
	
	node* l2 = newnode();
	l2 -> data = 20;
	addhead(l2,list);
	
	cout << "Son node adresi: " << last(list) << endl;
	dumplist(list);
	*/
	system("pause");
	return 0;
	
}
