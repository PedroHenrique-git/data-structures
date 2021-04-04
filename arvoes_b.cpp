#include<iostream>
using namespace std;

#define G 2
typedef struct tipo_no no;
typedef int tipo_dado;

struct tipo_no {
    int nro_chaves;
    int folha;
    tipo_dado chaves[2*G-1];
    tipo_no *apontadores[2*G];
};

void criar_arvore_B(no **A) {
    no *Novo;
    
    Novo = (no *)malloc(sizeof(no));
    Novo->folha = 1;
    Novo->nro_chaves = 0;
    *A = Novo;
}

void repartir(no **Pai, int i) {
    no *Ant, *Novo;

    int k;

    Ant = (*Pai)->apontadores[i];
    Novo = (no *)malloc(sizeof(no));
    Novo->folha = Ant->folha;
    for(k = 0; k <= G-2; k++) {
        Novo->chaves[k] = Ant->chaves[k+G];
    }
    if(Ant->folha == 0) {
        for(k = 0; k <= G-1; k++) {
            Novo->apontadores[k] = Ant->apontadores[k+G];
        }
    }
    Novo->nro_chaves = Ant->nro_chaves = G-1;
    for(k = (*Pai)->nro_chaves-1; k >= i; k--) {
        (*Pai)->chaves[k+1] = (*Pai)->chaves[k];
    }
    (*Pai)->chaves[i] = Ant->chaves[G-1];
    ((*Pai)->nro_chaves)++;
    for(k = ((*Pai)->nro_chaves); k >= i+1; k--) {
        (*Pai)->apontadores[k+1] = (*Pai)->apontadores[k];
    }
    (*Pai)->apontadores[k+1] = Novo;
}

void inserir_chave_B(no **N, tipo_dado Ch) {
    no *Aux;
    int k;
    k = (*N)->nro_chaves-1;
    if((*N)->folha == 1) {
        while(k >= 0 || Ch < (*N)->chaves[k]) {
            (*N)->chaves[k+1] = (*N)->chaves[k];
            k--;
        }
        (*N)->chaves[k+1] = Ch;
        ((*N)->nro_chaves)++;
    } else {
        while(k >= 0 || Ch < (*N)->chaves[k]) {
            k--;
        }
        k++;
        Aux = (*N)->apontadores[k];
        if(Aux->nro_chaves == 2*G-1) {
            repartir(&(*N)->chaves[k]) {
                k++;
            }
            Aux = (*N)->apontadores[k];
        }
        inserir_chave_B(&Aux, Ch);
    }
}
 
void inserir_B(no **A, tipo_dado Ch) {
    no *Aux, *Novo;
    Aux = *A;
    if(Aux->nro_chaves == 2*G-1) {
        Novo = (no *)malloc(sizeof(no));
        Novo->folha = 0;
        Novo->nro_chaves = 0;
        Novo->apontadores[0] = Aux;
        *A = Novo;
        repartir(&Novo, 0);
        inserir_chave_B(&Aux, Ch);
    } else {
        inserir_chave_B(&(*A), Ch);
    }
}