#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 20
#define MAX_NOME 50

// Definição da estrutura para as notas
typedef struct {
    float notas[3];
} Notas;

// Definição da estrutura para a data de nascimento
typedef struct {
    int dia, mes, ano;
} Data;

// Definição da estrutura para o aluno
typedef struct {
    int RA;
    char nome[MAX_NOME];
    Notas notas;
    Data dataNascimento;
} Aluno;

// Função para inserir um novo aluno
void inserirAluno(Aluno alunos[], int *numAlunos) {
    if (*numAlunos >= MAX_ALUNOS) {
        printf("Limite de alunos atingido.\n");
        return;
    }

    printf("Digite o RA do aluno: ");
    scanf("%d", &alunos[*numAlunos].RA);
    printf("Digite o nome do aluno: ");
    scanf("%s", alunos[*numAlunos].nome);
    printf("Digite as 3 notas do aluno: ");
    scanf("%f %f %f", &alunos[*numAlunos].notas.notas[0], &alunos[*numAlunos].notas.notas[1], &alunos[*numAlunos].notas.notas[2]);
    printf("Digite a data de nascimento (dia mes ano): ");
    scanf("%d %d %d", &alunos[*numAlunos].dataNascimento.dia, &alunos[*numAlunos].dataNascimento.mes, &alunos[*numAlunos].dataNascimento.ano);

    (*numAlunos)++;
}

// Função para calcular a média das notas de um aluno
float calcularMedia(Aluno aluno) {
    float soma = 0;
    for (int i = 0; i < 3; i++) {
        soma += aluno.notas.notas[i];
    }
    return soma / 3.0;
}

// Função para listar os nomes e as médias das notas de todos os alunos
void listarMedias(Aluno alunos[], int numAlunos) {
    printf("\nListagem de alunos e suas medias:\n");
    for (int i = 0; i < numAlunos; i++) {
        printf("Nome: %s - Media: %.2f\n", alunos[i].nome, calcularMedia(alunos[i]));
    }
}

// Função para listar os nomes dos alunos que nasceram depois de um certo ano
void listarNascidosDepois(Aluno alunos[], int numAlunos, int ano) {
    printf("\nAlunos nascidos depois de %d:\n", ano);
    for (int i = 0; i < numAlunos; i++) {
        if (alunos[i].dataNascimento.ano > ano) {
            printf("%s\n", alunos[i].nome);
        }
    }
}

int main() {
    Aluno alunos[MAX_ALUNOS];
    int numAlunos = 0;
    int opcao, ano;

    do {
        printf("\nMENU:\n");
        printf("1. Inserir novo aluno\n");
        printf("2. Listar nomes e medias das notas de todos os alunos\n");
        printf("3. Listar nomes dos alunos que nasceram depois de um certo ano\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirAluno(alunos, &numAlunos);
                break;
            case 2:
                listarMedias(alunos, numAlunos);
                break;
            case 3:
                printf("Digite o ano limite: ");
                scanf("%d", &ano);
                listarNascidosDepois(alunos, numAlunos, ano);
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 4);

    return 0;
}
