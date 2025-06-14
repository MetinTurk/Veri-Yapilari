#include <iostream>
#include <locale.h>

using namespace std;

struct node{
	int data;
	int row , col;
	node* dlink;
	node* rlink;
};

//newnode
node* newnode(){
	node* newnode = new node;
	newnode->data = 0;
	newnode->row = 0;
	newnode->col = 0;
	newnode->dlink = NULL;
	newnode->rlink = NULL;
	return newnode;
}

//create matris
void createMatris(node*& M , int row , int col)
{
	M = newnode();
	node* yM = M;
	for (int i = 1; i < row+1;i++){
		yM->dlink = newnode();
		yM->dlink->row = i;
		yM = yM->dlink;
	}
	
	yM = M;
	
	for(int i = 1; i < col+1;i++){
		yM->rlink = newnode();
		yM->rlink->col = i;
		yM = yM->rlink;
	}
}

//print matris
void printMatris(node*& M)
{
	node* cM = NULL;
	node* rM = M;
	while(rM!=NULL){
		cout << "["<< rM << "-" << rM->data<<"-"<<rM->row<<"-"<<rM->col<<"-";
		if(rM->dlink==NULL)cout << "00000000-"; else cout << rM->dlink<<"-";
		if(rM->rlink==NULL)cout << "00000000]    "; else cout << rM->rlink<<"]    ";
		cM = rM->rlink;
		while(cM!=NULL)
		{
			cout << "[" << cM << "-" << cM->data<<"-"<<cM->row<<"-"<<cM->col<<"-";
			if(cM->dlink==NULL)cout << "00000000-"; else cout << cM->dlink<<"-";
			if(cM->rlink==NULL)cout << "00000000]    "; else cout << cM->rlink<<"]    ";
			
			if((cM->rlink!= NULL) && (((cM->rlink->col)-(cM->col))>=1))
			{
				for(int i = 1 ; i< ((cM->rlink->col)-(cM->col)>=1);i++)
				{
					cout << "                                                               ";
				}
			}
			cM= cM->rlink;
		}
		cout << endl;
		rM = rM->dlink;
	}
	cout << "------------------------------------------------------------------------------------" << endl;    
}

//insert node to matris
void insertNodeToMatris(node*& M , node* newnode , int r , int c){
	/*
	cout << "["<< newnode << "-" << newnode->data<<"-"<<newnode->row<<"-"<<newnode->col<<"-";
	if(newnode->dlink==NULL)cout << "00000000-"; else cout << newnode->dlink<<"-";
	if(newnode->rlink==NULL)cout << "00000000]    "; else cout << newnode->rlink<<"]    ";
	*/
	newnode->col = c;
	newnode->row =r;
	
	node* gM;
	node* yM = M;
	while(yM!=NULL){
		if(yM->row == r){
			gM=yM;
			while(!(gM->rlink==NULL || gM->rlink->col > c))
			gM= gM->rlink;
			newnode->rlink = gM->rlink;
			gM->rlink=newnode;
			break;
		}
		yM = yM->dlink;
	}
	yM= M;
	while(yM!=NULL)
	{
		if(yM->col == c){
			gM= yM;
			while(!(gM->dlink==NULL || gM->dlink->row > r))
			gM=gM->dlink;
			newnode->dlink=gM->dlink;
			gM->dlink= newnode;
			break;
		}
		yM=yM->rlink;
	}
	
}

void matrisSay(node*& M){
	int adet = 0;
	node* satir = M;
	while (satir != NULL) {
		node* hucre = satir;
		while (hucre != NULL) {
			adet++;
			hucre = hucre->rlink;
		}
		satir = satir->dlink;
	}
	cout << adet << " tane matris düðümü var." << endl;
}


int main(){
	setlocale(LC_ALL , "Turkish");
	
	node* m = NULL;
	createMatris(m, 4, 4);
	printMatris(m);
	
	insertNodeToMatris(m, newnode(), 1, 1);
	insertNodeToMatris(m, newnode(), 2, 2);
	insertNodeToMatris(m, newnode(), 2, 1);
	insertNodeToMatris(m, newnode(), 3, 3);
	insertNodeToMatris(m, newnode(), 4, 4);
	insertNodeToMatris(m, newnode(), 2, 3);
	printMatris(m);
	
	matrisSay(m);

	
	
	system("pause");
	return 0;
}
