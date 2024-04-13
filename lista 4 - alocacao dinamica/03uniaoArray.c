#include <stdio.h>
#include <stdlib.h>

int* uniao(int *v1, int *v2, int n1, int n2, int* qtde) {
    // Inicializar o ponteiro de quantidade com 0
    *qtde = 0;

    // Verificar se os ponteiros de entrada são NULL
    if (v1 == NULL || v2 == NULL || n1 <= 0 || n2 <= 0) {
        return NULL;
    }

    // Calcular o tamanho total da união
    int total_size = n1 + n2;

    // Inicializar um array dinâmico para armazenar a união
    int* uniao = (int*)malloc(total_size * sizeof(int));
    if (uniao == NULL) {
        printf("Erro: não foi possível alocar memória.\n");
        exit(1);
    }

    // Adicionar elementos de v1 à união
    for (int i = 0; i < n1; i++) {
        uniao[(*qtde)++] = v1[i];
    }

    // Adicionar elementos de v2 à união, evitando duplicatas
    for (int i = 0; i < n2; i++) {
        int j;
        for (j = 0; j < *qtde; j++) {
            if (v2[i] == uniao[j]) {
                break;
            }
        }
        if (j == *qtde) {
            uniao[(*qtde)++] = v2[i];
        }
    }

    // Redimensionar o array de união para o tamanho exato
    uniao = (int*)realloc(uniao, (*qtde) * sizeof(int));

    return uniao;
}

int main() {
    int v1[] = {1, 2, 3, 4, 5};
    int v2[] = {4, 5, 6, 7, 8};
    int n1 = sizeof(v1) / sizeof(v1[0]); // sizeof(v1) retorna o tamanho total em bytes, 
    //sizeof(v1[0]) retorna o tamanho em bytes do primeiro elemento
    int n2 = sizeof(v2) / sizeof(v2[0]);
    int qtde;

    int* v3 = uniao(v1, v2, n1, n2, &qtde);

    if (v3 != NULL) {
        printf("Uniao: ");
        for (int i = 0; i < qtde; i++) {
            printf("%d ", v3[i]);
        }
        printf("\n");
        free(v3); // Liberar memória alocada dinamicamente
    } else {
        printf("Nao ha uniao entre os arrays.\n");
    }

    return 0;
}
