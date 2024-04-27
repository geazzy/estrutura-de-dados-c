#include "pilhaContigua.h"

// Função para transferir elementos de uma pilha P1 para uma pilha P2
void transferir_pilha(Pilha* p1, Pilha* p2) {
    if (p1 == NULL || p2 == NULL) {
        printf("Pilhas inválidas.\n");
        return;
    }

    // Copia o endereço de memória do vetor de elementos de p1 para p2
    p2->vetor = p1->vetor;
    p2->qtde = p1->qtde;

    // Define o vetor de elementos de p1 como NULL para evitar acesso acidental
    p1->vetor = NULL;
    p1->qtde = 0;
}

int main() {
    Pilha* p1 = pilha_criar();
    Pilha* p2 = pilha_criar();

    TipoElemento vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    pilha_empilharTodos(p1, vetor, 10);

    printf("Pilha P1 antes da transferência:\n");
    pilha_imprimir(p1);
    TipoElemento topo;
    if (pilha_topo(p1, &topo)) { // Passando o endereço de 'topo'
        printf("Topo da pilha P1: %d\n", topo);
    } else {
        printf("Pilha vazia.\n");
    }

    printf("Pilha P2 antes da transferência:\n");
    pilha_imprimir(p2);

    // Transferir elementos de p1 para p2
    transferir_pilha(p1, p2);

    printf("Pilha P1 após a transferência:\n");
    pilha_imprimir(p1);

    printf("Pilha P2 após a transferência:\n");
    pilha_imprimir(p2);

    if (pilha_topo(p2, &topo)) { // Passando o endereço de 'topo'
        printf("Topo da pilha P2: %d\n", topo);
    } else {
        printf("Pilha vazia.\n");
    }

    // Destruir pilhas
    pilha_destruir(p1);
    pilha_destruir(p2);

    return 0;
}

// int main() {
//     Pilha* p = pilha_criar();
//     TipoElemento vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     pilha_empilharTodos(p, vetor, 10);

//     printf("Tamanho da pilha: %d\n", pilha_tamanho(p));

//     TipoElemento topo;
//     if (pilha_topo(p, &topo)) {
//         printf("Elemento do topo: %d\n", topo);
//     } else {
//         printf("Pilha vazia.\n");
//     }

//     printf("Pilha:\n");
//     pilha_imprimir(p);

//     printf("Desempilhando...\n");
//     if (pilha_desempilhar(p, &topo)) {
//         printf("Elemento desempilhado: %d\n", topo);
//     } else {
//         printf("Erro ao desempilhar: pilha vazia.\n");
//     }

//     printf("Desempilhando novamente...\n");
//     if (pilha_desempilhar(p, &topo)) {
//         printf("Elemento desempilhado: %d\n", topo);
//     } else {
//         printf("Erro ao desempilhar: pilha vazia.\n");
//     }

//     printf("Restante da pilha:\n");
//     pilha_imprimir(p);

//     printf("Invertendo a pilha...\n");
//     pilha_inverter(p);
//     printf("Pilha invertida:\n");
//     pilha_imprimir(p);

//     Pilha* clone = pilha_clone(p);
//     printf("Pilha clonada:\n");
//     pilha_imprimir(clone);

//     pilha_destruir(clone);
//     pilha_destruir(p);

//     return 0;
// }
