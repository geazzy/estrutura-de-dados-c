//pilhaContigua.h
#ifndef PILHA_CONTIGUA_H
#define PILHA_CONTIGUA_H

#include <stdlib.h>
#include <stdio.h>

//typedef enum boolean { false = 0, true = 1 } Boolean;
typedef int TipoElemento;

// DADOS

typedef struct {
    TipoElemento* vetor;
    int tamVetor;
    int qtde;
} Pilha;

//PROTÓTIPOS

Pilha* pilha_criar();
void pilha_destruir(Pilha* p);
Boolean pilha_empilhar(Pilha* p, TipoElemento elemento);
Boolean pilha_desempilhar(Pilha* p, TipoElemento* saida);
Boolean pilha_topo(Pilha* p, TipoElemento* saida);
Boolean pilha_vazia(Pilha* p);
void pilha_imprimir(Pilha* p);
int pilha_tamanho(Pilha* p);
Pilha* pilha_clone(Pilha* p);
void pilha_inverter(Pilha* p);
Boolean pilha_empilharTodos(Pilha* p, TipoElemento* vetor, int tamVetor);

//Implementação da função de criar pilha
Pilha* pilha_criar() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    if (p != NULL) {
        p->tamVetor = 10;
        p->vetor = (TipoElemento*)malloc(p->tamVetor * sizeof(TipoElemento));
        if (p->vetor == NULL) {
            free(p);
            return NULL;
        }
        p->qtde = 0;
    }
    return p;
}

//Implementação da função de destruir pilha
void pilha_destruir(Pilha* p) {
    if (p != NULL) {
        if (p->vetor != NULL) {
            free(p->vetor);
        }
        free(p);
    }
}

//Implementação da função de empilhar
Boolean pilha_empilhar(Pilha* p, TipoElemento elemento) {
    if (p != NULL) {
        if (p->qtde == p->tamVetor) {
            p->tamVetor *= 2;
            TipoElemento* vetorTemp = (TipoElemento*)malloc(p->tamVetor * sizeof(TipoElemento));
            if (vetorTemp == NULL) {
                return false;
            }
            for (int i = 0; i < p->qtde; i++) {
                vetorTemp[i] = p->vetor[i];
            }
            free(p->vetor);
            p->vetor = vetorTemp;
        }
        p->vetor[p->qtde] = elemento;
        p->qtde++;
        return true;
    }
    return false;
}

//Implementação da função de desempilhar
Boolean pilha_desempilhar(Pilha* p, TipoElemento* saida) {
    if (p != NULL && p->qtde > 0) {
        *saida = p->vetor[p->qtde - 1];
        p->qtde--;
        return true;
    }
    return false;
}

//Implementação da função de topo
Boolean pilha_topo(Pilha* p, TipoElemento* saida) {
    if (p != NULL && p->qtde > 0) {
        *saida = p->vetor[p->qtde - 1];
        return true;
    }
    return false;
}

//Implementação da função de vazia
Boolean pilha_vazia(Pilha* p) {
    if (p != NULL) {
        return p->qtde == 0;
    }
    return false;
}

//Implementação da função de imprimir
void pilha_imprimir(Pilha* p) {
    if (p != NULL) {
        for (int i = p->qtde - 1; i >= 0; i--) {
            printf("%d\n", p->vetor[i]);
        }
    }
}

//Implementação da função de tamanho
int pilha_tamanho(Pilha* p) {
    if (p != NULL) {
        return p->qtde;
    }
    return -1;
}

//Implementação da função de clone
Pilha* pilha_clone(Pilha* p) {
    if (p != NULL) {
        Pilha* clone = (Pilha*)malloc(sizeof(Pilha));
        if (clone != NULL) {
            clone->tamVetor = p->tamVetor;
            clone->vetor = (TipoElemento*)malloc(clone->tamVetor * sizeof(TipoElemento));
            if (clone->vetor == NULL) {
                free(clone);
                return NULL;
            }
            clone->qtde = p->qtde;
            for (int i = 0; i < p->qtde; i++) {
                clone->vetor[i] = p->vetor[i];
            }
            return clone;
        }
    }
    return NULL;
}

//Implementação da função de inverter
void pilha_inverter(Pilha* p) {
    if (p != NULL) {
        TipoElemento* vetorTemp = (TipoElemento*)malloc(p->tamVetor * sizeof(TipoElemento));
        if (vetorTemp == NULL) {
            return;
        }
        for (int i = 0; i < p->qtde; i++) {
            vetorTemp[i] = p->vetor[p->qtde - i - 1];
        }
        free(p->vetor);
        p->vetor = vetorTemp;
    }
}

//Implementação da função de empilhar todos
Boolean pilha_empilharTodos(Pilha* p, TipoElemento* vetor, int tamVetor) {
    if (p != NULL) {
        for (int i = 0; i < tamVetor; i++) {
            if (!pilha_empilhar(p, vetor[i])) {
                return false;
            }
        }
        return true;
    }
    return false;
}

#endif // PILHA_CONTIGUA_H
