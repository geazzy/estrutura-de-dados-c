#include <stdlib.h>
#include <stdio.h>

typedef enum boolean{false=0, true=1} Boolean;
typedef int TipoElemento;

// Estrutura do nó da pilha
typedef struct no{
    TipoElemento dado;
    struct no *prox;
} No;

// Estrutura da pilha
typedef struct {
    No *topo;
    int qtdeElementos;
} Pilha;

// Protótipos de Funções

Pilha* pilha_criar();
void pilha_destruir(Pilha* p);
Boolean pilha_empilhar(Pilha* p, TipoElemento elemento);
Boolean pilha_desempilhar(Pilha* p, TipoElemento* saida);
Boolean pilha_topo(Pilha* p, TipoElemento* saida);
Boolean pilha_vazia(Pilha* p);
//void pilha_imprimir(Pilha* p);
int pilha_tamanho(Pilha* p);
Pilha* pilha_clone(Pilha* p);
void pilha_inverter(Pilha* p);
Boolean pilha_empilharTodos(Pilha* p, TipoElemento* vetor, int tamVetor);
void pilha_imprimir(Pilha* p, void (*printElemento)(void*));
// Implementação das Funções

Pilha* pilha_criar() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    if (p != NULL) {
        p->topo = NULL;
        p->qtdeElementos = 0;
    }
    return p;
}

void pilha_destruir(Pilha* p) {
    if (p != NULL) {
        No* atual = p->topo;
        while (atual != NULL) {
            No* proximo = atual->prox;
            free(atual);
            atual = proximo;
        }
        free(p);
    }
}

Boolean pilha_empilhar(Pilha* p, TipoElemento elemento) {
    if (p != NULL) {
        No* novoNo = (No*)malloc(sizeof(No));
        if (novoNo != NULL) {
            novoNo->dado = elemento;
            novoNo->prox = p->topo;
            p->topo = novoNo;
            p->qtdeElementos++;
            return true;
        }
    }
    return false;
}

Boolean pilha_desempilhar(Pilha* p, TipoElemento* saida) {
    if (p != NULL && p->topo != NULL) {
        No* temp = p->topo;
        *saida = temp->dado;
        p->topo = temp->prox;
        free(temp);
        p->qtdeElementos--;
        return true;
    }
    return false;
}

Boolean pilha_topo(Pilha* p, TipoElemento* saida) {
    if (p != NULL && p->topo != NULL) {
        *saida = p->topo->dado;
        return true;
    }
    return false;
}

Boolean pilha_vazia(Pilha* p) {
    return (p == NULL || p->topo == NULL) ? true : false;
}

// void pilha_imprimir(Pilha* p) {
//     if (p != NULL) {
//         No* atual = p->topo;
//         while (atual != NULL) {
//             printf("%d\n", atual->dado);
//             atual = atual->prox;
//         }
//     }
// }
void pilha_imprimir(Pilha* p, void (*printElemento)(void*)) {
    if (p != NULL && printElemento != NULL) {
        No* atual = p->topo;
        while (atual != NULL) {
            // Chamando a função de impressão para cada elemento da pilha
            printElemento(&(atual->dado));
            atual = atual->prox;
        }
    }
}

void imprimirInteiro(void* elemento) {
    int* num = (int*)elemento;
    printf("%d\n", *num);
}

int pilha_tamanho(Pilha* p) {
    return (p != NULL) ? p->qtdeElementos : -1;
}

Pilha* pilha_clone(Pilha* p) {
    if (p != NULL) {
        Pilha* clone = pilha_criar();
        if (clone != NULL) {
            No* atual = p->topo;
            while (atual != NULL) {
                // Empilhar elementos do topo ao fundo da pilha original
                // para manter a ordem correta na pilha clone
                pilha_empilhar(clone, atual->dado);
                atual = atual->prox;
            }
            // Invertendo a pilha clone para reverter a ordem dos elementos
            pilha_inverter(clone);
        }
        return clone;
    }
    return NULL;
}


void pilha_inverter(Pilha* p) {
    if (p != NULL && p->topo != NULL) {
        No* anterior = NULL;
        No* atual = p->topo;
        No* proximo = NULL;
        while (atual != NULL) {
            proximo = atual->prox;
            atual->prox = anterior;
            anterior = atual;
            atual = proximo;
        }
        p->topo = anterior;
    }
}

Boolean pilha_empilharTodos(Pilha* p, TipoElemento* vetor, int tamVetor) {
    if (p != NULL && vetor != NULL) {
        for (int i = 0; i < tamVetor; i++) {
            if (!pilha_empilhar(p, vetor[i])) {
                return false;
            }
        }
        return true;
    }
    return false;
}
