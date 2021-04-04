#include <iostream>
using namespace std;

int altura(tipo_no *R) {
    int Alt_esq, Alt_dir;
    if(R == NULL) {
        return -1;
    } else {
        Alt_dir = altura(R->dir);
        Alt_esq = altura(R->esq);
        if(Alt_dir > Alt_esq) {
            return Alt_dir + 1;
        } else {
            return Alt_esq + 1;
        }
    }
}

void rotacao_direita(no **R) {
    no *Aux;
    if(*R != NULL) {
        Aux = (*R)->esq;
        (*R)->esq = Aux->dir;
        Aux->dir = *R;
        *R = Aux;
    }
}

void rotacao_esquerda(no **R) {
    no *Aux;
    if(*R != NULL) {
        Aux = (*R)->dir;
        (*R)->dir = Aux->esq;
        Aux->esq = *R;
        *R = Aux;
    }
}