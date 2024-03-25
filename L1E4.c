#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 20

// Função para ler uma string
void lerString(char *str) {
    printf("Digite uma string (max %d caracteres): ", MAX_LENGTH);
    scanf(" %s", str);
}

// Função para imprimir o tamanho da string
void imprimirTamanho(char *str) {
    printf("O tamanho da string é: %ld\n", strlen(str));
}

// Função para comparar duas strings
void compararStrings(char *str1, char *str2) {
    int cmp = strcmp(str1, str2);
    if (cmp == 0)
        printf("As strings são iguais.\n");
    else
        printf("As strings são diferentes.\n");
}

// Função para concatenar duas strings
void concatenarStrings(char *str1, char *str2) {
    strcat(str1, str2);
    printf("A string concatenada é: %s\n", str1);
}

// Função para imprimir uma string de forma reversa
void imprimirReverso(char *str) {
    printf("A string de forma reversa é: ");
    for (int i = strlen(str) - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

// Função para contar ocorrências de um caractere na string
void contarCaractere(char *str, char c) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == c)
            count++;
    }
    printf("O caractere '%c' aparece %d vezes na string.\n", c, count);
}

// Função para substituir a primeira ocorrência de um caractere por outro
void substituirCaractere(char *str, char c1, char c2) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == c1) {
            str[i] = c2;
            break; // Substituir apenas a primeira ocorrência
        }
    }
    printf("String após a substituição: %s\n", str);
}

// Função para verificar se uma string é uma substring de outra
void verificarSubstring(char *str1, char *str2) {
    if (strstr(str1, str2) != NULL)
        printf("%s é uma substring de %s.\n", str2, str1);
    else
        printf("%s não é uma substring de %s.\n", str2, str1);
}

// Função para retornar uma substring de uma string
void retornarSubstring(char *str, int posicao, int tamanho) {
    if (posicao < 0 || posicao >= strlen(str) || posicao + tamanho > strlen(str)) {
        printf("Posição ou tamanho inválido.\n");
        return;
    }

    char substring[MAX_LENGTH];
    strncpy(substring, str + posicao, tamanho);
    substring[tamanho] = '\0'; // Adicionando o terminador nulo
    printf("Substring: %s\n", substring);
}

int main() {
    char string1[MAX_LENGTH], string2[MAX_LENGTH], c1, c2;
    int opcao, posicao, tamanho;

    do {
        printf("\nMenu:\n");
        printf("1. Ler uma string S1\n");
        printf("2. Imprimir o tamanho da string S1\n");
        printf("3. Comparar a string S1 com uma nova string S2\n");
        printf("4. Concatenar a string S1 com uma nova string S2\n");
        printf("5. Imprimir a string S1 de forma reversa\n");
        printf("6. Contar quantas vezes um dado caractere aparece na string S1\n");
        printf("7. Substituir a primeira ocorrência de um caractere C1 da string S1 pelo caractere C2\n");
        printf("8. Verificar se uma string S2 é substring de S1\n");
        printf("9. Retornar uma substring da string S1\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                lerString(string1);
                break;
            case 2:
                imprimirTamanho(string1);
                break;
            case 3:
                printf("Digite a nova string S2: ");
                scanf(" %s", string2);
                compararStrings(string1, string2);
                break;
            case 4:
                printf("Digite a nova string S2: ");
                scanf(" %s", string2);
                concatenarStrings(string1, string2);
                break;
            case 5:
                imprimirReverso(string1);
                break;
            case 6:
                printf("Digite o caractere: ");
                scanf(" %c", &c1);
                contarCaractere(string1, c1);
                break;
            case 7:
                printf("Digite o caractere a ser substituído: ");
                scanf(" %c", &c1);
                printf("Digite o novo caractere: ");
                scanf(" %c", &c2);
                substituirCaractere(string1, c1, c2);
                break;
            case 8:
                printf("Digite a string S2: ");
                scanf(" %s", string2);
                verificarSubstring(string1, string2);
                break;
            case 9:
                printf("Digite a posição inicial da substring: ");
                scanf("%d", &posicao);
                printf("Digite o tamanho da substring: ");
                scanf("%d", &tamanho);
                retornarSubstring(string1, posicao, tamanho);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
