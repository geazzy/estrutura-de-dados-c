#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura para os elementos da pilha
struct Elemento {
    int valor;
    struct Elemento* proximo;
};

// Definição da estrutura para a pilha
struct Pilha {
    struct Elemento* topo;
};

// Função para criar uma nova pilha
struct Pilha* criarPilha() {
    struct Pilha* pilha = (struct Pilha*)malloc(sizeof(struct Pilha));
    if (pilha == NULL) {
        printf("Erro ao alocar memória.\n");
        return NULL;
    }
    
    pilha->topo = NULL;
    
    return pilha;
}

// Função para empilhar um novo elemento na pilha
void empilhar(struct Pilha* pilha, int valor) {
    struct Elemento* novoElemento = (struct Elemento*)malloc(sizeof(struct Elemento));
    if (novoElemento == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    
    novoElemento->valor = valor;
    novoElemento->proximo = pilha->topo;
    pilha->topo = novoElemento;
}

// Função para desempilhar um elemento da pilha
int desempilhar(struct Pilha* pilha) {
    if (pilha->topo == NULL) {
        printf("A pilha está vazia.\n");
        return 0;
    }
    
    struct Elemento* temp = pilha->topo;
    int valor = temp->valor;
    pilha->topo = temp->proximo;
    free(temp);
    
    return valor;
}

// Função para imprimir os elementos da pilha
void imprimirPilha(struct Pilha* pilha) {
    struct Elemento* atual = pilha->topo;
    while (atual != NULL) {
        printf("%d\n", atual->valor);
        atual = atual->proximo;
    }
}

// Função para liberar a memória alocada pela pilha
void liberarPilha(struct Pilha* pilha) {
    while (pilha->topo != NULL) {
        struct Elemento* temp = pilha->topo;
        pilha->topo = temp->proximo;
        free(temp);
    }
    
    free(pilha);
}

int main() {
    struct Pilha* pilha = criarPilha();
    
    empilhar(pilha, 10);
    empilhar(pilha, 20);
    empilhar(pilha, 30);
    empilhar(pilha, 40);
    empilhar(pilha, 50);

    printf("Pilha após empilhar:\n");
    imprimirPilha(pilha);
    
    printf("Desempilhando: %d\n", desempilhar(pilha));
    printf("Desempilhando: %d\n", desempilhar(pilha));
    
    printf("Pilha após desempilhar:\n");
    imprimirPilha(pilha);
    
    liberarPilha(pilha);

    // Tentar desempilhar uma pilha vazia
    desempilhar(pilha);

    return 0;
}