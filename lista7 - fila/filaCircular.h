#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum boolean { false = 0, true = 1 } Boolean;
typedef int TipoElemento;

/**************************************
* DADOS
**************************************/
typedef struct {
    TipoElemento* vetor;
    int tamVetor;
    int inicio;
    int fim;
    int qtdeElementos;
} Fila;

/**************************************
* PROTÓTIPOS
**************************************/
Fila* fila_criar();
void fila_destruir(Fila* f);
Boolean fila_inserir(Fila* f, TipoElemento elemento);
Boolean fila_remover(Fila* f, TipoElemento* saida);
Boolean fila_primeiro(Fila* f, TipoElemento* saida);
Boolean fila_vazia(Fila* f);
int fila_tamanho(Fila* f);
Fila* fila_clone(Fila* f);
void fila_inverter(Fila* f);
Boolean fila_inserirTodos(Fila* f, TipoElemento* vetor, int tamVetor);
void fila_imprimir(Fila* f);
void fila_imprimir_(Fila* f, void (*printElemento)(void*));
Boolean fura_fila(Fila* f, TipoElemento elemento);

/**************************************
* IMPLEMENTAÇÃO
**************************************/

Fila* fila_criar() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->tamVetor = 10; // Initial size of the vector
    f->vetor = (TipoElemento*)malloc(f->tamVetor * sizeof(TipoElemento));
    f->inicio = 0;
    f->fim = 0;
    f->qtdeElementos = 0;
    return f;
}

void fila_destruir(Fila* f) {
    free(f->vetor);
    free(f);
}

Boolean fila_inserir(Fila* f, TipoElemento elemento) {
    if (f->qtdeElementos == f->tamVetor) {
        // Redimensionar o vetor para o dobro do tamanho
        int novoTam = f->tamVetor * 2;
        TipoElemento* novoVetor = (TipoElemento*)malloc(novoTam * sizeof(TipoElemento));
        if (!novoVetor) return false;

        for (int i = 0; i < f->qtdeElementos; i++) {
            novoVetor[i] = f->vetor[(f->inicio + i) % f->tamVetor];
        }

        free(f->vetor);
        f->vetor = novoVetor;
        f->tamVetor = novoTam;
        f->inicio = 0;
        f->fim = f->qtdeElementos;
    }

    f->vetor[f->fim] = elemento;
    f->fim = (f->fim + 1) % f->tamVetor;
    f->qtdeElementos++;
    return true;
}

Boolean fila_remover(Fila* f, TipoElemento* saida) {
    if (fila_vazia(f)) return false;

    *saida = f->vetor[f->inicio];
    f->inicio = (f->inicio + 1) % f->tamVetor;
    f->qtdeElementos--;
    return true;
}

Boolean fila_primeiro(Fila* f, TipoElemento* saida) {
    if (fila_vazia(f)) return false;

    *saida = f->vetor[f->inicio];
    return true;
}

Boolean fila_vazia(Fila* f) {
    return f->qtdeElementos == 0;
}

int fila_tamanho(Fila* f) {
    return f->qtdeElementos;
}

Fila* fila_clone(Fila* f) {
    Fila* clone = fila_criar();
    if (!clone) return NULL;

    clone->tamVetor = f->tamVetor;
    free(clone->vetor);
    clone->vetor = (TipoElemento*)malloc(clone->tamVetor * sizeof(TipoElemento));
    if (!clone->vetor) return NULL;

    for (int i = 0, idx = f->inicio; i < f->qtdeElementos; i++, idx = (idx + 1) % f->tamVetor) {
        clone->vetor[i] = f->vetor[idx];
    }

    clone->inicio = 0;
    clone->fim = f->qtdeElementos;
    clone->qtdeElementos = f->qtdeElementos;
    return clone;
}

void fila_inverter(Fila* f) {
    if (f == NULL || fila_vazia(f)) return;

    TipoElemento* temp = (TipoElemento*)malloc(f->qtdeElementos * sizeof(TipoElemento));
    if (!temp) return;

    for (int i = 0; i < f->qtdeElementos; i++) {
        temp[i] = f->vetor[(f->inicio + f->qtdeElementos - 1 - i) % f->tamVetor];
    }

    for (int i = 0; i < f->qtdeElementos; i++) {
        f->vetor[(f->inicio + i) % f->tamVetor] = temp[i];
    }

    free(temp);
}

Boolean fila_inserirTodos(Fila* f, TipoElemento* vetor, int tamVetor) {
    for (int i = 0; i < tamVetor; i++) {
        if (!fila_inserir(f, vetor[i])) return false;
    }
    return true;
}

void fila_imprimir(Fila* f) {
    for (int i = 0, idx = f->inicio; i < f->qtdeElementos; i++, idx = (idx + 1) % f->tamVetor) {
        printf("%d ", f->vetor[idx]);
    }
    printf("\n");
}

void fila_imprimir_(Fila* f, void (*printElemento)(void*)) {
    for (int i = 0, idx = f->inicio; i < f->qtdeElementos; i++, idx = (idx + 1) % f->tamVetor) {
        printElemento(&f->vetor[idx]);
    }
    printf("\n");
}

Boolean fura_fila(Fila* f, TipoElemento elemento) {
    if (f->qtdeElementos == f->tamVetor) {
        // Redimensionar o vetor para o dobro do tamanho
        int novoTam = f->tamVetor * 2;
        TipoElemento* novoVetor = (TipoElemento*)malloc(novoTam * sizeof(TipoElemento));
        if (novoVetor == NULL) return false;

        // Copiar elementos para o novo vetor
        for (int i = 0; i < f->qtdeElementos; i++) {
            novoVetor[i] = f->vetor[(f->inicio + i) % f->tamVetor];
        }

        // Atualizar fila
        free(f->vetor);
        f->vetor = novoVetor;
        f->tamVetor = novoTam;
        f->inicio = 0;
        f->fim = f->qtdeElementos;
    }

    // Ajustar o índice de início
    f->inicio = (f->inicio - 1 + f->tamVetor) % f->tamVetor;
    f->vetor[f->inicio] = elemento;
    f->qtdeElementos++;

    return true;
}

// Função para imprimir um elemento do tipo TipoElemento
void printElementoInt(void* elemento) {
    printf("%d ", *(int*)elemento);
}

// // Função principal para testar as funcionalidades
// int main() {
//     Fila* f = fila_criar();
//     fila_inserir(f, 1);
//     fila_inserir(f, 2);
//     fila_inserir(f, 3);

//     printf("Fila antes de inverter: ");
//     fila_imprimir(f, printElementoInt);

//     fila_inverter(f);

//     printf("Fila após inverter: ");
//     fila_imprimir(f, printElementoInt);

//     fila_destruir(f);
//     return 0;
// }

