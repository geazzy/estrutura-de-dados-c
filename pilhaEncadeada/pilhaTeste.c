#include<stdio.h>
#include<stdlib.h>
#include "pilhaEncadeada.h"

int main() {
    // Criando uma pilha
    Pilha* p = pilha_criar();
    
    // Testando pilha_vazia (deve retornar true)
    printf("A pilha está vazia? %s\n", pilha_vazia(p) ? "Sim" : "Não");

    // Testando pilha_empilhar
    pilha_empilhar(p, 10);
    pilha_empilhar(p, 20);
    pilha_empilhar(p, 30);
    
    // Testando pilha_vazia (deve retornar false)
    printf("A pilha está vazia? %s\n", pilha_vazia(p) ? "Sim" : "Não");

    printf("Tamanho da pilha: %d\n", pilha_tamanho(p));

    // Testando pilha_imprimir
    printf("Elementos da pilha:\n");
    pilha_imprimir(p, imprimirInteiro);

        // Testando pilha_clone
    Pilha* clone = pilha_clone(p);
    printf("Clonando a pilha:\n");
    pilha_imprimir(clone, imprimirInteiro);

    // Testando pilha_inverter
    printf("\nInvertendo a pilha original:\n");
    pilha_inverter(p);
    pilha_imprimir(p, imprimirInteiro);

    TipoElemento topo;
    if (pilha_topo(p, &topo)) {
        printf("Elemento do topo: %d\n", topo);
    } else {
        printf("Pilha vazia.\n");
    }

    if (pilha_desempilhar(p, &topo)) {
        printf("Elemento desempilhado: %d\n", topo);
    } else {
        printf("Erro ao desempilhar: pilha vazia.\n");
    }

    if (pilha_desempilhar(p, &topo)) {
        printf("Elemento desempilhado: %d\n", topo);
    } else {
        printf("Erro ao desempilhar: pilha vazia.\n");
    }

    if (pilha_desempilhar(p, &topo)) {
        printf("Elemento desempilhado: %d\n", topo);
    } else {
        printf("Erro ao desempilhar: pilha vazia.\n");
    }

    // Testando pilha_desempilhar (deve retornar falso)
    if (pilha_desempilhar(p, &topo)) {
        printf("Elemento desempilhado: %d\n", topo);
    } else {
        printf("Erro ao desempilhar: pilha vazia.\n");
    }


    // Testando pilha_empilharTodos
    TipoElemento vetor[] = {40, 50, 60};
    printf("\nEmpilhando todos os elementos do vetor:\n");
    pilha_empilharTodos(p, vetor, 3);
    pilha_imprimir(p, imprimirInteiro);

    // Liberando a memória das pilhas
    pilha_destruir(clone);
    pilha_destruir(p);

    return 0;
}
