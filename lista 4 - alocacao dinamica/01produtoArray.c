#include <stdio.h>
#include <stdlib.h>

/**
 * Função que calcula o produto elemento a elemento de dois arrays de inteiros.
 * 
 * @param v1 O primeiro array de inteiros.
 * @param v2 O segundo array de inteiros.
 * @param n O tamanho dos arrays.
 * @return Um ponteiro para um novo array contendo o produto elemento a elemento de v1 e v2.
 *         Retorna NULL se n for negativo ou se algum dos ponteiros de entrada for NULL.
 *         Retorna NULL se não for possível alocar memória para o novo array.
 */
int* produto(int *v1, int *v2, int n) {
    // Verificar se N é negativo
    if (n <= 0) {
        return NULL;
    }

    // Verificar se os ponteiros de entrada são NULL
    if (v1 == NULL || v2 == NULL) {
       return NULL;
    }

    int *v3 = (int*)malloc(n * sizeof(int));
    if (v3 == NULL) {
       return NULL;
    }

    for (int i = 0; i < n; i++) {
        v3[i] = v1[i] * v2[i];
    }

    return v3;
}

int main() {
    // Exemplo de uso
    int v1[5]={0,0,1,2,2};
    int v2[5]={0,0,1,2,2};
    int n = sizeof(v1) / sizeof(v1[0]);

    int *v3 = produto(v1, v2, 5);

    printf("Resultado de v3:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v3[i]);
    }
    printf("\n");
    free(v3); // liberar a memória alocada dinamicamente

    printf("Resultado de v6:\n");
    int v4[8]={7,6,5,4,3,2,1,0};
    int v5[8]={7,6,5,4,3,2,1,0};
    int *v6 = produto(v4, v5, 8);

    for (int i = 0; i < 8; i++){
    printf("%d ", *(v6+i));
    }
    free(v6); // liberar a memória alocada dinamicamente
    printf("\n");

    printf("Testes adicionais, V7:\n");
    int *v7 = produto(NULL, NULL, 8);
    printf("%d\n", v7 == NULL);
    free(v7);
   

    printf("Testes adicionais, V10:\n");
    int v8[8]={7,6,5,4,3,2,1,0};
    int v9[8]={7,6,5,4,3,2,1,0};
    int *v10 = produto(v8, v9, -1);

    printf("%d\n", v10 == NULL);
    free(v10);// liberar a memória alocada dinamicamente

    return 0;
}
