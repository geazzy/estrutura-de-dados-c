#include <stdio.h>

#define MAX_SIZE 3


struct Matriz {
    int dimensao;
    int elementos[MAX_SIZE][MAX_SIZE];
};


int determinante2x2(int a, int b, int c, int d) {
    return a * d - b * c;
}


int determinante3x3(int matriz[3][3]) {
    return matriz[0][0] * determinante2x2(matriz[1][1], matriz[1][2], matriz[2][1], matriz[2][2]) -
           matriz[0][1] * determinante2x2(matriz[1][0], matriz[1][2], matriz[2][0], matriz[2][2]) +
           matriz[0][2] * determinante2x2(matriz[1][0], matriz[1][1], matriz[2][0], matriz[2][1]);
}


int cofator(struct Matriz m, int linha, int coluna) {
    int submatriz[MAX_SIZE - 1][MAX_SIZE - 1];
    int submatriz_i = 0, submatriz_j = 0;

    // Construindo a submatriz excluindo a linha e coluna do elemento
    for (int i = 0; i < m.dimensao; i++) {
        if (i == linha)
            continue;

        for (int j = 0; j < m.dimensao; j++) {
            if (j == coluna)
                continue;

            submatriz[submatriz_i][submatriz_j] = m.elementos[i][j];
            submatriz_j++;
        }
        submatriz_i++;
        submatriz_j = 0;
    }

    // Calculando o determinante da submatriz
    if (m.dimensao == 2)
        return determinante2x2(submatriz[0][0], submatriz[0][1], submatriz[1][0], submatriz[1][1]);
    else if (m.dimensao == 3)
        return determinante3x3(submatriz);
}


void matrizAdjunta(struct Matriz m, int adjunta[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < m.dimensao; i++) {
        for (int j = 0; j < m.dimensao; j++) {
            adjunta[j][i] = cofator(m, i, j) * ((i + j) % 2 == 0 ? 1 : -1);
        }
    }
}


void imprimirMatriz(int matriz[MAX_SIZE][MAX_SIZE], int dimensao) {
    for (int i = 0; i < dimensao; i++) {
        for (int j = 0; j < dimensao; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct Matriz m;
    int adjunta[MAX_SIZE][MAX_SIZE];

    printf("Digite a dimensao da matriz (2 ou 3): ");
    scanf("%d", &m.dimensao);

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < m.dimensao; i++) {
        for (int j = 0; j < m.dimensao; j++) {
            scanf("%d", &m.elementos[i][j]);
        }
    }

    matrizAdjunta(m, adjunta);

    printf("Matriz adjunta:\n");
    imprimirMatriz(adjunta, m.dimensao);

    return 0;
}
