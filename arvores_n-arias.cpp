#include <iostream>
using namespace std;

typedef int tipo_dado;
typedef tipo_no no;

struct tipo_no {
    int nro_chaves;
    tipo_dado chaves[N];
    tipo_no *apontadores[N + 1];
};


void ordenado(no *Raiz) {
    int j, Ni;

    if(Raiz != NULL) {
        Ni = Raiz->nro_chaves;
        for(j = 0; j < Ni; j++) {
            ordenado(Raiz->apontadores[j]);
            cout<<Raiz->chaves[j];
        }
        ordenado(Raiz->apontadores[j]);
    }
}

void busca_no(no *Raiz, tipo_dado Ch, no **i, int *j) {
    int Ni;
    if(Raiz == NULL) {
        *i = NULL;
        *j = -1;
    } else {
        *i = Raiz;
        Ni = (*i)->nro_chaves;
        for(*j = 0; *j < Ni; (*j)++) {
            cout<<"Chave visitada = "<<(*i)->chaves[*j];
            if((*i)->chaves[*j] == Ch) {
                return;
            } else if(Ch < ((*i)->chaves[*j])) {
                break;
            }
        }
        busca_no((*i)->apontadores[*j], Ch,&(*i),&(*j));
    }
}

void busca_no_ins(no *Raiz, tipo_dado Ch, no **i, int *j) {
    int Ni;
    if(Raiz != NULL) {
        *i = Raiz;
        Ni = (*i)->nro_chaves;

        for(*j = 0; *j < Ni; (*j)++) {
            if( (*i)->chaves[*j] == Ch) {
                *j = -1;
                return;
            } else if(Ch < (*i)->chaves[*j] ) {
                if(Ni < GRAU - 1) {
                    return;
                } else {
                    break;
                }
            }
        }
        busca_no_ins((*i)->apontadores[*j], Ch, &(*i), &(*j));
    }
}

void inserir_n_naria(no **Raiz, tipo_dado Ch) {
    no *i;
    int j;
    int Ni, k;

    if(*Raiz == NULL) {
        *Raiz = (no *)malloc(sizeof(no));
        for(k = 0; k < GRAU - 1; k++) {
            (*Raiz)->chaves[k] = -1;
            (*Raiz)->apontadores[k] = NULL;
        }
        (*Raiz)->apontadores[k] = NULL;
        (*Raiz)->chaves[0] = Ch;
        (*Raiz)->nro_chaves = 1;
    } else {
        i = *Raiz;
        j = 0;
        busca_no_ins(*Raiz,Ch,&i,&j);
        if(j == -1) {
            cout<<"Chave já existente na arvore";
        } else {
            Ni = i->nro_chaves;
            if(Ni == GRAU - 1) {
                no *E;
                E = (no *)malloc(sizeof(no));
                for(k = 0; k < Ni; k++) {
                    E->chaves[k] = -1;
                    E->apontadores[k] = NULL;
                }
                E->apontadores[k] = NULL;
                E->chaves[0] = Ch;
                E->nro_chaves = 1;
                E->apontadores[j] = E;
            } else {
                if(j == Ni) {
                    i->apontadores[j+1] = NULL;
                } else {
                    i->apontadores[Ni+1] = i->apontadores[Ni];
                    for(k = Ni; k > j; k--) {
                        i->chaves[k] = i->chaves[k-1];
                        i->apontadores[k] = i->apontadores[k-1];
                    }
                    i->apontadores[j] = NULL;
                }
                i->chaves[j] = Ch;
                i->nro_chaves = i->nro_chaves + 1;
            }
        }
    }
}