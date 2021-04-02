#include<iostream>
using namespace std;

typedef struct tipo_no no;
typedef int tipo_dado;

struct tipo_no {
	tipo_dado dado;
	struct tipo_no *esq;
	struct tipo_no *dir;
};

void pre_ordem(no *Raiz) {
	if(Raiz != NULL) {
		cout<<Raiz->dado;
		pre_ordem(Raiz->esq);
		pre_ordem(Raiz->dir);
	}
}

void em_ordem(no *Raiz) {
	if(Raiz != NULL) {
		em_ordem(Raiz->esq);
		cout<<Raiz->dado;
		em_ordem(Raiz->dir);
	}
}

void pos_ordem(no *Raiz) {
	if(Raiz != NULL) {
		pos_ordem(Raiz->esq);
		pos_ordem(Raiz->dir);
		cout<<Raiz->dado;
	}
}

void inserir_binaria(no **Raiz, tipo_dado valor) {
	no *E;
	
	if(*Raiz == NULL) {
		E = (no *)malloc(sizeof(no));
		E->dado = valor;
		E->esq = NULL;
		E->dir = NULL;
		*Raiz = E;
	} else if( valor < (*Raiz)->dado ) {
		inserir_binaria(&(*Raiz)->esq, valor);
	} else if( valor > (*Raiz)->dado ) {
		inserir_binaria(&(*Raiz)->dir, valor);	
	} else {
		cout<<"Elemento já existente";
	}
}

tipo_dado retornar_maior(no **X) {
	tipo_dado valor;
	no *AUX;
	
	if( (*X)->dir != NULL ) {
		return(retornar_maior(&(*X)->dir));
	} else {
		AUX = *X;
		valor = (*X)->dado;
		*X = (*X)->esq;
		
		free(AUX);
		return(valor);
	}
}

void remover_binaria(no **Raiz, tipo_dado valor) {
	no *AUX;
	if(*Raiz !== NULL) {
		if( (*Raiz)->dado == valor ) {
			AUX = *Raiz;
			if( (*Raiz)->esq == NULL ) {
				*Raiz = (*Raiz)->dir;
				free(AUX);
			} else if( (*Raiz)->dir == NULL ) {
				*Raiz = ( (*Raiz)->esq );
				free(AUX);	
			} else {
				(*Raiz)->dado = retornar_maior( &(*Raiz)->esq );
			}
		} else if( (*Raiz)->dado < valor ) {
			remover_binaria( &(*Raiz)->dir, valor );
		} else if( (*Raiz)->dado > valor ) {
			remover_binaria( &(*Raiz)->esq, valor );
		}
	} else {
		cout<<"Elemento inexistente";
	}
}

main() {
}
