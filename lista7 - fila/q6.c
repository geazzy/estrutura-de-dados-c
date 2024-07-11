#include <stdio.h>
#include <stdlib.h>
#include "filaEncadeada.h"

// Função auxiliar para imprimir elementos inteiros
void imprimirInteiro(void* elemento) {
    printf("%d", *(int*)elemento);
}

int main() {
    // Criando uma fila
    Fila* fila = fila_criar();

    // Testando a inserção de elementos na fila
    fila_inserir(fila, 1);
    fila_inserir(fila, 2);
    fila_inserir(fila, 3);

    // Clonando a fila e imprimindo a cópia
    Fila* clone = fila_clone(fila);
    printf("Cópia da fila original: ");
    fila_imprimir(clone, imprimirInteiro);

    // Invertendo a fila original e imprimindo-a
    fila_inverter(fila);
    printf("Fila original invertida: ");
    fila_imprimir(fila, imprimirInteiro);

    // Testando a inserção de múltiplos elementos na fila
    int vetor[] = {4, 5, 6};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    fila_inserirTodos(fila, vetor, tamanho);
    printf("Fila original com elementos adicionais: ");
    fila_imprimir(fila, imprimirInteiro);

    // Liberando a memória das filas
    fila_destruir(fila);
    fila_destruir(clone);

    return 0;
}
