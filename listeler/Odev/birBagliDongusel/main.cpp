//main.cpp
#include <iostream>
#include "bbdol.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void yildizbas()
{
	cout << "-----------------------------------" << endl;
}
int main(int argc, char** argv) {
	
	/*
	node* list = newnode();
	cout << list << endl;
	cout << list->data << endl;
	cout << list->link << endl;
	
	addhead(newnode() , list);
	addhead(newnode() , list);
	addhead(newnode() , list);
	addhead(cons(25) , list);
	
	dumplist(list);
	
	yildizbas();
	
	cout << last(list) << endl;
	cout << cuthead(list) << endl;
	dumplist(list);
	cout << last(list) << endl;
	yildizbas();
	
	
	
	node* l2 = NULL;
	addhead(newnode() , l2);
	addhead(newnode() , l2);
	addhead(newnode() , l2);
	dumplist(l2);
	yildizbas();
	
	concatenate(list , l2);
	
	dumplist(list);
	yildizbas();
	

	free(l2);	// etkisi yok

	dumplist(l2);
	*/
	
	node* list = NULL;
	addhead(cons(52), list);
	addhead(cons(32), list);
	addhead(cons(25), list);
	addhead(newnode() , list);
	dumplist(copy(list));
	node* bulunan = locate(25, list);
	dumplist(bulunan);
	cout << "Aradýðýnýz deðer var mi: " << member(locate(32,list),list);
	

	
	
	system("pause");
	return 0;
}
