#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

typedef struct tipo_registro registro;

struct tipo_registro {
	int codigo;
	char nome[30];
	struct tipo_registro *prox;
};

int main() {
	registro *p1, *p2, *p3;
	
	p1 = (registro *) malloc(sizeof(registro));
	p2 = (registro *) malloc(sizeof(registro));
	p3 = (registro *) malloc(sizeof(registro));
	
	if((!p1) || (!p2)) {
		cout<< "Não há memória disponível";
	} else {
		
		p1->codigo = 1;
		strcpy(p1->nome, "nome1");
		p1->prox = p2;
		
		p2->codigo = 2;
		strcpy(p2->nome,"nome2");
		p2->prox = p3;
		
		p3->codigo = 3;
		strcpy(p3->nome,"nome3");
		p3->prox = NULL;
		
		cout<<"P1: "<<p1<<" "<<"P2: "<<p2<<" "<<"P3: "<<p3<<endl;
		
		cout<<"Codigo de p1: "<<p1->codigo<<endl;
		cout<<"Nome de p2: "<<p2->nome<<endl;
		cout<<"Endereco contido no campo prox de p1: "<<p1->prox<<endl;
		cout<<"Endereco contido no campo prox de p2: "<<p2->prox<<endl;
		cout<<"Codigo de p2: "<<p2->codigo<<endl;
		cout<<"Codigo de p2: "<<p1->prox->codigo<<endl;
		cout<<p1->prox->prox->nome;
	}
}


