#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum boolean { false = 0, true = 1 } Boolean;
typedef int TipoElemento;

/**************************************
* DADOS
**************************************/
typedef struct no {
    TipoElemento dado;
    struct no *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
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
//void fila_imprimir(Fila* f);
Fila* fila_clone(Fila* f);
Boolean fila_toString(Fila* f, char* str);
Fila* fila_clone(Fila* f);
void fila_inverter(Fila* f);
Boolean fila_inserirTodos(Fila* f, TipoElemento* vetor, int tamVetor);
void fila_imprimir(Fila* f, void (*printElemento)(void*));

/**************************************
* IMPLEMENTAÇÃO
**************************************/

// Cria uma nova fila vazia
Fila* fila_criar() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    f->qtdeElementos = 0;
    return f;
}

// Destroi a fila e libera a memória alocada
void fila_destruir(Fila* f) {
    No* atual = f->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(f);
}

// Insere um elemento no fim da fila
Boolean fila_inserir(Fila* f, TipoElemento elemento) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) return false;

    novoNo->dado = elemento;
    novoNo->prox = NULL;

    if (fila_vazia(f)) {
        f->inicio = novoNo;
    } else {
        f->fim->prox = novoNo;
    }
    f->fim = novoNo;
    f->qtdeElementos++;
    return true;
}

// Remove um elemento do início da fila e retorna ele através do ponteiro saida
Boolean fila_remover(Fila* f, TipoElemento* saida) {
    if (fila_vazia(f)) return false;

    No* temp = f->inicio;
    *saida = temp->dado;
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(temp);
    f->qtdeElementos--;
    return true;
}

// Retorna o primeiro elemento da fila sem removê-lo
Boolean fila_primeiro(Fila* f, TipoElemento* saida) {
    if (fila_vazia(f)) return false;

    *saida = f->inicio->dado;
    return true;
}

// Verifica se a fila está vazia
Boolean fila_vazia(Fila* f) {
    return f->qtdeElementos == 0;
}

// Retorna o tamanho da fila
int fila_tamanho(Fila* f) {
    return f->qtdeElementos;
}

// // Imprime os elementos da fila
// void fila_imprimir(Fila* f) {
//     No* atual = f->inicio;
//     while (atual != NULL) {
//         printf("%d ", atual->dado);
//         atual = atual->prox;
//     }
//     printf("\n");
// }

// Cria uma cópia da fila
Fila* fila_clone(Fila* f) {
    Fila* clone = fila_criar();
    No* atual = f->inicio;
    while (atual != NULL) {
        fila_inserir(clone, atual->dado);
        atual = atual->prox;
    }
    return clone;
}

// Converte os elementos da fila para uma string
Boolean fila_toString(Fila* f, char* str) {
    if (fila_vazia(f)) return false;

    char buffer[12]; // Suficiente para armazenar um int como string
    strcpy(str, "[");

    No* atual = f->inicio;
    while (atual != NULL) {
        if (atual != f->inicio) strcat(str, ", ");
        sprintf(buffer, "%d", atual->dado);
        strcat(str, buffer);
        atual = atual->prox;
    }

    strcat(str, "]");
    return true;
}

void fila_inverter(Fila* f) {
    // Se a fila estiver vazia ou com apenas um elemento, não há necessidade de inverter
    if (f == NULL || f->qtdeElementos <= 1) return;

    No* prev = NULL;
    No* current = f->inicio;
    No* next = NULL;
    f->fim = f->inicio; // O último elemento agora será o primeiro

    // Inverte os ponteiros dos nós
    while (current != NULL) {
        next = current->prox;
        current->prox = prev;
        prev = current;
        current = next;
    }

    f->inicio = prev; // O primeiro elemento agora será o último
}

Boolean fila_inserirTodos(Fila* f, TipoElemento* vetor, int tamVetor) {
    for (int i = 0; i < tamVetor; i++) {
        if (!fila_inserir(f, vetor[i])) return false;
    }
    return true;
}

void fila_imprimir(Fila* f, void (*printElemento)(void*)) {
    if (fila_vazia(f)) {
        printf("Fila vazia\n");
        return;
    }

    No* atual = f->inicio;
    while (atual != NULL) {
        printElemento(&(atual->dado));
        printf(" ");
        atual = atual->prox;
    }
    printf("\n");
}
