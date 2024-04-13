#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned int codigo;
    char nome[50];
    float *notas;
    int quantidade_notas;
} Aluno;

Aluno* criarAluno(unsigned int codigo, const char* nome, int quantidade_notas) {
    Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));
    if (novoAluno == NULL) {
        printf("Erro: não foi possível alocar memória para o aluno.\n");
        exit(1);
    }

    novoAluno->codigo = codigo;
    strncpy(novoAluno->nome, nome, sizeof(novoAluno->nome));
    novoAluno->quantidade_notas = quantidade_notas;

    novoAluno->notas = (float*)malloc(quantidade_notas * sizeof(float));
    if (novoAluno->notas == NULL) {
        printf("Erro: não foi possível alocar memória para as notas do aluno.\n");
        exit(1);
    }

    return novoAluno;
}

void imprimirAluno(Aluno* aluno) {
    printf("Código: %u\n", aluno->codigo);
    printf("Nome: %s\n", aluno->nome);
    printf("Notas: ");
    for (int i = 0; i < aluno->quantidade_notas; i++) {
        printf("%.2f ", aluno->notas[i]);
    }
    printf("\n");
}

int main() {
    // Exemplo de utilização das funções
    Aluno* aluno1 = criarAluno(1, "Aluno A", 3);
    aluno1->notas[0] = 7.5;
    aluno1->notas[1] = 8.0;
    aluno1->notas[2] = 6.5;

    Aluno* aluno2 = criarAluno(2, "Aluno B", 5);
    aluno2->notas[0] = 6.0;
    aluno2->notas[1] = 7.0;
    aluno2->notas[2] = 8.0;
    aluno2->notas[3] = 9.0;
    aluno2->notas[4] = 8.5;

    printf("Aluno 1:\n");
    imprimirAluno(aluno1);

    printf("\nAluno 2:\n");
    imprimirAluno(aluno2);

    // Liberar memória alocada dinamicamente
    free(aluno1->notas);
    free(aluno1);
    free(aluno2->notas);
    free(aluno2);

    return 0;
}
