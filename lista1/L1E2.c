#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;

    printf("Digite a dimensao dos vetores: ");
    scanf("%d", &n);

    // Alocar memória para os vetores
    int *v1 = (int *)malloc(n * sizeof(int));
    int *v2 = (int *)malloc(n * sizeof(int));
    int *v3 = (int *)malloc(2 * n * sizeof(int));

    printf("Digite os elementos do primeiro vetor:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &v1[i]);
    }

    printf("Digite os elementos do segundo vetor:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &v2[i]);
    }

    // Intercalar os vetores
    int j = 0;
    for (i = 0; i < n; i++) {
        v3[j++] = v1[i];
        v3[j++] = v2[i];
    }

    printf("v1: ");
    for (i = 0; i < n; i++) {
        printf("%d ", v1[i]);
    }
    printf("\n");

    printf("v2: ");
    for (i = 0; i < n; i++) {
        printf("%d ", v2[i]);
    }
    printf("\n");

    printf("v3: ");
    for (i = 0; i < 2 * n; i++) {
        printf("%d ", v3[i]);
    }
    printf("\n");

    // Liberar a memória alocada
    free(v1);
    free(v2);
    free(v3);

    return 0;
}
