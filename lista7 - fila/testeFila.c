#include<stdio.h>
#include<stdlib.h>
#include "FilaCircular.h"
//#include "FilaEncadeada.h"

int main(){
	Fila* fila = fila_criar();
    TipoElemento elemento;

    // Testando fila_inserir
    printf("Inserindo elementos na fila:\n");
    for (int i = 1; i <= 10; i++) {
        if (fila_inserir(fila, i)) {
            printf("Inserido: %d\n", i);
        } else {
            printf("Falha ao inserir: %d\n", i);
        }
    }

    // Testando fila_imprimir
    printf("Elementos na fila: ");
    fila_imprimir(fila);

    // Testando fila_remover
    printf("Removendo elementos da fila:\n");
    for (int i = 0; i < 5; i++) {
        if (fila_remover(fila, &elemento)) {
            printf("Removido: %d\n", elemento);
        } else {
            printf("Falha ao remover\n");
        }
    }

    // Testando fila_primeiro
    if (fila_primeiro(fila, &elemento)) {
        printf("Primeiro elemento: %d\n", elemento);
    } else {
        printf("Fila vazia\n");
    }

    // Testando fila_vazia
    printf("Fila está vazia? %s\n", fila_vazia(fila) ? "Sim" : "Não");

    // Testando fila_tamanho
    printf("Tamanho da fila: %d\n", fila_tamanho(fila));

    // Testando fila_clone
    Fila* fila_clonada = fila_clone(fila);
    printf("Elementos na fila clonada: ");
    fila_imprimir(fila_clonada);

    // Testando fila_toString
    char str[100];
    if (fila_toString(fila, str)) {
        printf("Fila como string: %s\n", str);
    } else {
        printf("Falha ao converter fila para string\n");
    }

    // Testando fila_inserirTodos
    TipoElemento novosElementos[] = {11, 12, 13, 14, 15};
    if (fila_inserirTodos(fila, novosElementos, 5)) {
        printf("Inseridos novos elementos: 11, 12, 13, 14, 15\n");
    } else {
        printf("Falha ao inserir todos os novos elementos\n");
    }

    printf("Elementos na fila após inserir novos elementos: ");
    fila_imprimir(fila);

    // Destruir filas
    fila_destruir(fila);
    fila_destruir(fila_clonada);

    return 0;
}