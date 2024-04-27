#include <stdio.h>
#include <stdlib.h>
#include "pilhaContigua.h"

void inverter_palavras(char* texto) {
    // Criar uma pilha para armazenar as letras de cada palavra
    Pilha* pilha = pilha_criar();

    // Percorrer o texto
    for (int i = 0; texto[i] != '\0'; i++) {
        // Verificar se é uma letra
        if ((texto[i] >= 'A' && texto[i] <= 'Z') || (texto[i] >= 'a' && texto[i] <= 'z')) {
            // Empilhar a letra
            pilha_empilhar(pilha, texto[i]);
        } else {
            // Desempilhar e imprimir as letras, invertendo a palavra
            while (!pilha_vazia(pilha)) {
                TipoElemento letra;
                pilha_desempilhar(pilha, &letra);
                printf("%c", letra);
            }
            // Imprimir o caractere não letra (espaço ou ponto)
            printf("%c", texto[i]);
        }
    }

    // Destruir a pilha
    pilha_destruir(pilha);
}

int main() {
    // Texto de exemplo
    char texto[] = "MESTRADO EM CIENCIA DA COMPUTACAO.";

    // Inverter as palavras do texto
    inverter_palavras(texto);

    return 0;
}
