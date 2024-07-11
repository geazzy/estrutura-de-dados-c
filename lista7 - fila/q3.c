#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "filaCircular.h"
#include "pilhaContigua.h"

void processar_cadeia(char* entrada, char* saida) {
    Fila* letras = fila_criar();
    Pilha* digitos = pilha_criar();
    TipoElemento ch;

    // Processar a entrada e separar letras e dígitos
    for (int i = 0; entrada[i] != '\0'; i++) {
        ch = entrada[i];
        if (isalpha(ch)) {
            fila_inserir(letras, ch);
        } else if (isdigit(ch)) {
            pilha_empilhar(digitos, ch);
        }
    }

    // Construir a saída com letras seguidas pelos dígitos invertidos
    int idx = 0;
    while (!fila_vazia(letras)) {
        fila_remover(letras, &ch);
        saida[idx++] = (char)ch; // Cast para char ao armazenar na saída
    }
    while (!pilha_vazia(digitos)) {
        pilha_desempilhar(digitos, &ch);
        saida[idx++] = (char)ch; // Cast para char ao armazenar na saída
    }
    saida[idx] = '\0';  // Termina a string de saída

    fila_destruir(letras);
    pilha_destruir(digitos);
}

int main() {
    char entrada1[] = "M1E5T7R8A8D8O";
    char saida1[strlen(entrada1)];
    char entrada2[] = "C9H4Q6";
    char saida2[strlen(entrada2)];


    processar_cadeia(entrada1, saida1);
    processar_cadeia(entrada2, saida2);

    printf("Entrada: %s\n", entrada1);
    printf("Saída: %s\n", saida1);

    printf("Entrada: %s\n", entrada2);
    printf("Saída: %s\n", saida2);

    return 0;
}
// Entrada: M1E5T7R8A8D8O
// Saída: MESTRADO888751
// Entrada: C9H4Q6
// Saída: CHQ964