#include <stdio.h>
#include <stdlib.h>

int* vetor_novoA(int tamanho, int valor) {

    int* novo_vetor = (int*)malloc(tamanho * sizeof(int));
    if (novo_vetor == NULL) {
        printf("Erro: não foi possível alocar memória.\n");
        exit(1);
    }

    for (int i = 0; i < tamanho; i++) {
        novo_vetor[i] = valor++;
    }

    return novo_vetor;
}

void vetor_novoB(int tamanho, int valor, int **vetor) {

    *vetor = (int*)malloc(tamanho * sizeof(int));
    if (*vetor == NULL) {
        printf("Erro: não foi possível alocar memória.\n");
        exit(1);
    }

    for (int i = 0; i < tamanho; i++) {
        (*vetor)[i] = valor++;
    }
}

int main() {
    int *v1, *v2;
    v1 = vetor_novoA(10, 1);
    vetor_novoB(5, 2, &v2);

    // Exemplo de uso dos vetores criados
    printf("v1: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", v1[i]);
    }
    printf("\n");

    printf("v2: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", v2[i]);
    }
    printf("\n");

    free(v1);
    free(v2);

    return 0;
}
