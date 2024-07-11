#include <stdio.h>
#include <stdlib.h>
#include "filaCircular.h"

// Função principal para testar as funcionalidades
int main() {
    Fila* f = fila_criar();
    fila_inserir(f, 1);
    fila_inserir(f, 2);
    fila_inserir(f, 3);

    printf("Fila antes de inverter: ");
    fila_imprimir_(f, printElementoInt);

    fila_inverter(f);

    printf("Fila após inverter: ");
    fila_imprimir_(f, printElementoInt);

    fila_destruir(f);
    return 0;
}

