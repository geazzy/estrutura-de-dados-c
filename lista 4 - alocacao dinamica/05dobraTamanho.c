#include <stdio.h>
#include <stdlib.h>

int vetor_dobraTamanho(int **vetor, int tamanho) {
    // Alocar um novo vetor com o dobro do tamanho do vetor original
    int novo_tamanho = tamanho * 2;
    int *novo_vetor = (int*)calloc(novo_tamanho, sizeof(int));
    if (novo_vetor == NULL) {
        printf("Erro: não foi possível alocar memória.\n");
        exit(1);
    }

    // Copiar os valores para o vetor novo
    for (int i = 0; i < tamanho; i++) {
        novo_vetor[i] = (*vetor)[i];
    }

    // Preencher com 0 as novas posições
    for (int i = tamanho; i < novo_tamanho; i++) {
        novo_vetor[i] = 0;
    }

    // Desalocar o vetor antigo
    free(*vetor);

    // Atualizar a referência do vetor recebido por parâmetro
    *vetor = novo_vetor;

    return novo_tamanho;
}

int main() {
    int* v = (int*)calloc(3, sizeof(int));
    v[0] = 2;
    v[1] = 4;
    v[2] = 6;

    int novoTamanho = vetor_dobraTamanho(&v, 3);

    // Exibir o resultado esperado
    printf("[");
    for (int i = 0; i < novoTamanho; i++) {
        printf("%d", v[i]);
        if (i < novoTamanho - 1) {
            printf(",");
        }
    }
    printf("]\n");

    free(v);

    return 0;
}
