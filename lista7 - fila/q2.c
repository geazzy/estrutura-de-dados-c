#include <stdio.h>
#include <stdlib.h>
#include "filaCircular.h"
#include "pilhaContigua.h"

void inverter_fila(Fila* f) {
    if (fila_vazia(f)) return;

    Pilha* p = pilha_criar();
    TipoElemento aux;

    // Passo 1: Transferir todos os elementos da fila para a pilha
    while (!fila_vazia(f)) {
        fila_remover(f, &aux);
        pilha_empilhar(p, aux);
    }

    // Passo 2: Transferir todos os elementos da pilha de volta para a fila
    while (!pilha_vazia(p)) {
        pilha_desempilhar(p, &aux);
        fila_inserir(f, aux);
    }

    pilha_destruir(p);
}

int main() {
    Fila* f = fila_criar();

    // Inserindo elementos na fila
    fila_inserir(f, 1);
    fila_inserir(f, 2);
    fila_inserir(f, 3);
    fila_inserir(f, 4);
    fila_inserir(f, 5);

    // Imprimindo fila original
    printf("Fila original: ");
    fila_imprimir(f);

    // Invertendo a fila
    inverter_fila(f);

    // Imprimindo fila invertida
    printf("Fila invertida: ");
    fila_imprimir(f);

    fila_destruir(f);

    return 0;
}
