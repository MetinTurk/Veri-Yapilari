// main.cpp
#include "bbdol.h"
#include <iostream>
#include <locale.h>

using namespace std;


int main(int argc, char** argv) {
	setlocale(LC_ALL , "Turkish");
	
	node* tree = NULL;
	for(int i = 0 ; i< 5 ; i++){
		inserttree(tree , newnode());
	}
	printtree(tree);
	int yaprak = 0;
	int nodeSayisi = say(tree , yaprak);
	cout << "Toplam yaprak sayýsý: " << yaprak << " Toplam node sayýsý: " << nodeSayisi << endl;
	
	
	return 0;
}
