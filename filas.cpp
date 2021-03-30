#include<iostream>
using namespace std;
#define TAMANHO 100

struct fila {
	int informacoes[TAMANHO];
	int inicio, fim;
};

void inserir(struct fila *f, int valor) {
	if((f->fim + 1) < TAMANHO) {
		f->fim++;
		f->informacoes[f->fim] = valor;
		cout<<"Valor inserido: "<<valor;
	} else {
		cout<<"Estouro de fila"<<endl;
	}
}

int consumir(struct fila *f) {
	int valor;
	if(f->inicio < TAMANHO) {
		if((f->inicio == 0) && (f->informacoes[f->inicio] == -1)) {
			cout<<"Tentativa de consumir o primeiro elemento que ainda nao existe"<<endl;
			valor = -1;
		} else {
			valor = f->informacoes[f->inicio];
			f->inicio++;
			cout<<"Consumido: "<<valor<<endl;
		}
	} else {
		cout<<"Tentativa de consumir uma informacao inexistente: "<<endl;
		valor = -1;
	}
	return valor;
}

void imprimir(struct fila f) {
	cout<<"\n\n-------------------------- Fila Atual -----------------\n";
	for(int i = f.inicio; i <= f.fim; i++) {
		if(i == f.inicio) cout<<f.informacoes[i];
		else if(i == f.fim) cout<<f.informacoes[i];
		else cout<<f.informacoes[i];
	}
	if(f.inicio == (f.fim + 1))
		cout<<"Fila vazia";
	cout<<"\n-----------------------------------------------------------\n\n";
}

int main() {
	int valor = -1;
	struct fila f;
	f.inicio = 0;
	f.fim = -1;
	
	for(int i = 0; i < TAMANHO; i++)
		f.informacoes[i] = -1;
		
	valor = consumir(&f);
	imprimir(f);
	
	inserir(&f, 10);
	inserir(&f, 20);
	inserir(&f, 30);
	imprimir(f);
	
	valor = consumir(&f);
	valor = consumir(&f);
	imprimir(f);
	
	inserir(&f, 40);
	inserir(&f, 50);
	valor = consumir(&f);
	imprimir(f);	
}
