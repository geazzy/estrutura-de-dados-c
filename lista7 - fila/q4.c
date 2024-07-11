#include <stdio.h>
#include <stdlib.h>
#include "filaCircular.h"

Boolean fura_fila(Fila* f, TipoElemento elemento) {
    // Verificar se a fila está cheia
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

int main() {
    Fila* f = fila_criar();
    fila_inserir(f, 1);
    fila_inserir(f, 2);
    fila_inserir(f, 3);

    printf("Fila antes de furar fila: ");
    fila_imprimir(f);

    fura_fila(f, 0);

    printf("Fila após furar fila: ");
    fila_imprimir(f);

    fila_destruir(f);
    return 0;
}
