#include<iostream>
using namespace std;
#define TAM 4

struct pilha {
	int topo;
	int informacao[TAM];
};

void push(struct pilha *p, int info) {
	if(p->topo < TAM) {
		p->informacao[p->topo] = info;
		p->topo++;	
	} else {
		cout<<"Pilha cheia"<<endl;
	}
}

int pop(struct pilha *p) {
	int valor;
	if(p->topo > 0) {
		p->topo--;
		valor = p->informacao[p->topo];
		p->informacao[p->topo] = -1;
		return valor;
	} else {
		cout<<"Pilha vazia"<<endl;
	}
}

void imprimir(struct pilha p) {
	for(int i = 0; i < p.topo; i++) {
		cout<<"Informacoes: "<<p.informacao[i]<<endl;
	}
}

main() {
	int i = 0, valor_retirado;
	struct pilha pi;
	pi.topo = 0;
	
	for(int i = 0; i < TAM; i++) {
		pi.informacao[i] = -1;
	}
	
	push(&pi, 10);
	imprimir(pi);
	push(&pi, 20);
	imprimir(pi);
	push(&pi, 30);
	imprimir(pi);
	push(&pi, 5);
	imprimir(pi);
	push(&pi, 70);
	imprimir(pi);
	push(&pi, 88);
	imprimir(pi);
	
	valor_retirado = pop(&pi);
	imprimir(pi);
	valor_retirado = pop(&pi);
	imprimir(pi);
	valor_retirado = pop(&pi);
	imprimir(pi);
	valor_retirado = pop(&pi);
	imprimir(pi);
	valor_retirado = pop(&pi);
	imprimir(pi);	
}
