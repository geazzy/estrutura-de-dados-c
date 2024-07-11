#include<stdio.h>
#include<stdlib.h>
#include "filaCircular.h"

Fila* fila_intercalar(Fila* f1, Fila* f2) {
    Fila* f3 = fila_criar();
    TipoElemento elemento;
    int tamanho_f1 = fila_tamanho(f1);
    int tamanho_f2 = fila_tamanho(f2);
    int idx_f1 = f1->inicio;
    int idx_f2 = f2->inicio;

    // Intercalando elementos
    while (tamanho_f1 > 0 || tamanho_f2 > 0) {
        if (tamanho_f1 > 0) {
            elemento = f1->vetor[idx_f1];
            fila_inserir(f3, elemento);
            idx_f1 = (idx_f1 + 1) % f1->tamVetor;
            tamanho_f1--;
        }
        if (tamanho_f2 > 0) {
            elemento = f2->vetor[idx_f2];
            fila_inserir(f3, elemento);
            idx_f2 = (idx_f2 + 1) % f2->tamVetor;
            tamanho_f2--;
        }
    }

    return f3;
}

int main() {
    Fila* f1 = fila_criar();
    Fila* f2 = fila_criar();
    Fila* f3;

    // Inserindo elementos na fila f1
    fila_inserir(f1, 1);
    fila_inserir(f1, 3);
    fila_inserir(f1, 5);

    // Inserindo elementos na fila f2
    fila_inserir(f2, 2);
    fila_inserir(f2, 4);
    fila_inserir(f2, 6);

    // Intercalando f1 e f2 em f3
    f3 = fila_intercalar(f1, f2);

    // Imprimindo filas
    printf("Fila 1: ");
    fila_imprimir(f1);
    printf("Fila 2: ");
    fila_imprimir(f2);
    printf("Fila 3 (Intercalada): ");
    fila_imprimir(f3);

    // Destruindo filas
    fila_destruir(f1);
    fila_destruir(f2);
    fila_destruir(f3);

    return 0;
}