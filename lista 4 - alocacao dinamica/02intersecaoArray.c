#include <stdio.h>
#include <stdlib.h>

int* intersecao(int *v1, int *v2, int n1, int n2, int* qtde) {
    // Inicializar o ponteiro de quantidade com 0
    *qtde = 0;

    // Verificar se os ponteiros de entrada são NULL
    if (v1 == NULL || v2 == NULL || n1 <= 0 || n2 <= 0) {
        return NULL;
    }

    // Inicializar um array dinâmico para armazenar a interseção
    int* inter = (int*)malloc(n1 * sizeof(int));
    if (inter == NULL) {
        printf("Erro: não foi possível alocar memória.\n");
        exit(1);
    }

    // Verificar interseção e armazenar no array dinâmico
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (v1[i] == v2[j]) {
                inter[(*qtde)++] = v1[i];
                break;
            }
        }
    }

    // Redimensionar o array de interseção para o tamanho exato
    inter = (int*)realloc(inter, (*qtde) * sizeof(int));

    return inter;
}

int main() {
    int v1[] = {8, 2, 3, 4, 5};
    int v2[] = {4, 5, 6, 7, 8};
    
    int n1 = 5;
    int n2 = 5;
    int qtde;

    int* v3 = intersecao(v1, v2, n1, n2, &qtde);

    if (v3 != NULL) {
        printf("Intersecao: ");
        for (int i = 0; i < qtde; i++) {
            printf("%d ", v3[i]);
        }
        printf("\nQuatidade de elementos: %d\n", qtde);

        free(v3); // Liberar memória alocada dinamicamente
    } else {
        printf("Nao ha intersecao entre os arrays.\n");
    }

    return 0;
}
