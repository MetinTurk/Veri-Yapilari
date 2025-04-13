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
	/*
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
	*/
	
	/*
	node* list = NULL;
	addhead(newnode() , list);
	addhead(cons(85) , list);
	addhead(newnode() , list);
	addhead(cons(45) , list);
	cout << "Listenin uzunluðu: " << countlist(list) << endl;
	cout << "Listenin uzunluðu: " << countlist1(list) << endl;
	cout << "Toplam: " << totallist(list) << endl;
	dumplist(list);
	int say;
	countlist2(say , list);
	cout << "Listenin Uzunluðu: " << say << endl;
	int toplam = 0;
	totallist2(toplam , list);
	cout << "Toplam: " << toplam << endl;
	dumplist(cuthead(list));
	dumplist(list);
	*/
	
	
	node* list = NULL;
	list = creatlist();
	dumplist(list);
	cout << "----------------------" << endl;
	int boyut = 0;
	countlist2(boyut,list);
	//node* middlelist = findmiddle(boyut , list);
	//dumplist(middlelist);
	//node* copyNode = reverscopy(list);
	//dumplist(copyNode);
	//clearlist(list);

	
	
	
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
