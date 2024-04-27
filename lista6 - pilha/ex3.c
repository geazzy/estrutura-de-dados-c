//ex3.c
#include <stdio.h>
#include <stdlib.h>
#include "pilhaContigua.h"

Boolean verificar_parenteses(const char* expressao) {
    Pilha* pilha = pilha_criar();

    for (int i = 0; expressao[i] != '\0'; i++) {
        char c = expressao[i];
        if (c == '(' || c == '[' || c == '{') {
            pilha_empilhar(pilha, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (pilha_vazia(pilha)) {
                pilha_destruir(pilha);
                return false; // Mais fechamentos que aberturas
            }
            TipoElemento topo;
            pilha_topo(pilha, &topo);
            if ((c == ')' && topo == '(') ||
                (c == ']' && topo == '[') ||
                (c == '}' && topo == '{')) {
                pilha_desempilhar(pilha, &topo);
            } else {
                pilha_destruir(pilha);
                return false; // Fechamento não corresponde ao abertura
            }
        }
    }

    Boolean esta_correto = pilha_vazia(pilha);
    pilha_destruir(pilha);
    return esta_correto;
}

int main() {
    FILE *arquivo;
    char expressao[100];

    // Abre o arquivo para leitura
    arquivo = fopen("expressoes.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return EXIT_FAILURE;
    }

    // Lê as expressões do arquivo e verifica a correspondência dos parênteses
    while (fgets(expressao, sizeof(expressao), arquivo)) {
        if (verificar_parenteses(expressao)) {
            printf("Correto: %s", expressao);
        } else {
            printf("Incorreto: %s", expressao);
        }
    }

    // Fecha o arquivo
    fclose(arquivo);

    return 0;
}