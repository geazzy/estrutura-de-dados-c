#include "lista.h"

/**
 * INSERIR
 * Teste das funções anexar e inserir
*/
void teste_inserir(){
    printf("\n------------------------------------------------\n");
    printf(">>> TESTE INSERIR \n");
    printf("------------------------------------------------\n");
    
    Lista* l = lista_criar();
    lista_anexar(l, 10);
    lista_anexar(l, 20);
    lista_anexar(l, 30);
    lista_imprimir(l);         // [10,20,30]
    printf("\n");

    // inicio
    lista_inserir(l, 5, 0);
    lista_inserir(l, 3, 0);
    lista_imprimir(l);         // [3,5,10,20,30]
    printf("\n");

    // fim
    lista_inserir(l, 40, 5);
    lista_inserir(l, 50, 6);
    
    // meio
    lista_inserir(l, 15, 3);
    lista_inserir(l, 45, 7);
    
    lista_imprimir(l);        // [3,5,10,15,20,30,40,45,50]
    printf("\n");
    
}

/**
 * REMOVER
 * Teste da função remover por posição
*/
void teste_removerPosicao(){
    printf("\n------------------------------------------------\n");
    printf(">>> TESTE REMOVER POR POSICAO\n");
    printf("------------------------------------------------\n");
    
    Lista* l = lista_criar();
    lista_anexar(l, 10);
    lista_anexar(l, 20);
    lista_anexar(l, 30);
    lista_anexar(l, 40);
    lista_anexar(l, 50);

    TipoElemento item;
  
    lista_imprimir(l);                    // [10,20,30,40,50]
    lista_removerPosicao(l, 0, &item);
    printf("\n");
    lista_imprimir(l);                    // [20,30,40,50]
    printf("\nRemovido: %d\n\n", item);   // Removido: 10

    lista_imprimir(l);                    //[20,30,40,50]
    lista_removerPosicao(l, 3, &item);
    printf("\n");
    lista_imprimir(l);                    // [20,30,40]
    printf("\nRemovido: %d\n\n", item);   // Removido: 50
    
    lista_imprimir(l);                    // [20,30,40]
    lista_removerPosicao(l, 1, &item);
    printf("\n");
    lista_imprimir(l);                    // [20,40]
    printf("\nRemovido: %d\n\n", item);   // Removido: 30

    lista_imprimir(l);                    // [20,40]
    lista_removerPosicao(l, -1, &item);
    printf("\n");
    lista_imprimir(l);                    // [20]
    printf("\nRemovido: %d\n\n", item);   // Removido: 40

    lista_imprimir(l);                    // [20]
    lista_removerPosicao(l, -1, &item);
    printf("\n");
    lista_imprimir(l);                    // []
    printf("\nRemovido: %d\n", item);     // Removido: 20
}

/**
 * REMOVER POR ELEMENTO
 * Teste da função remover por elemento
*/
void teste_removerElemento(){
    printf("\n------------------------------------------------\n");
    printf(">>> TESTE REMOVER POR ELEMENTO\n");
    printf("------------------------------------------------\n");
    
    Lista* l = lista_criar();
    lista_anexar(l, 10);
    lista_anexar(l, 20);
    lista_anexar(l, 30);
    lista_anexar(l, 40);
    lista_anexar(l, 50);

    int posicao;


    lista_imprimir(l);                             // [10,20,30,40,50]
    printf("\n");
    posicao = lista_removerElemento(l, 100);
    lista_imprimir(l);                             // [10,20,30,40,50]
    printf("\nRemovido posicao: %d\n\n", posicao); // Removido posicao: -1


    lista_imprimir(l);                             // [10,20,30,40,50]
    printf("\n");
    posicao = lista_removerElemento(l, 10);
    lista_imprimir(l);                             // [20,30,40,50]
    printf("\nRemovido posicao: %d\n\n", posicao); // Removido posicao: 0

    lista_imprimir(l);                             // [20,30,40,50]
    printf("\n");
    posicao = lista_removerElemento(l, 50);
    lista_imprimir(l);                             // [20,30,40]
    printf("\nRemovido posicao: %d\n\n", posicao); // Removido posicao: 3

    lista_imprimir(l);                             // [20,30,40]
    printf("\n");
    posicao = lista_removerElemento(l, 30);
    lista_imprimir(l);                             // [20,40]
    printf("\nRemovido posicao: %d\n\n", posicao); // Removido posicao: 1

    lista_imprimir(l);                             // [20,40]
    printf("\n");
    posicao = lista_removerElemento(l, 40);
    lista_imprimir(l);                             // [20]
    printf("\nRemovido posicao: %d\n\n", posicao); // Removido posicao: 1

    lista_imprimir(l);                             // [20]
    printf("\n");
    posicao = lista_removerElemento(l, 20);
    lista_imprimir(l);                             // []
    printf("\nRemovido posicao: %d\n\n", posicao); // Removido posicao: 0

    lista_imprimir(l);                             // []
    printf("\n");
    posicao = lista_removerElemento(l, 40);
    lista_imprimir(l);                             // []
    printf("\nRemovido posicao: %d\n", posicao);   // Removido posicao: -1
}

void teste_inverter(){
    printf("\n------------------------------------------------\n");
    printf(">>> TESTE INVERTER\n");
    printf("------------------------------------------------\n");
    
    Lista* l = lista_criar();
    lista_anexar(l, 10);
    lista_anexar(l, 20);
    lista_anexar(l, 30);
    lista_anexar(l, 40);
    lista_anexar(l, 50);

    printf("Lista original: ");
    lista_imprimir(l);                  // [10,20,30,40,50]
    printf("\n");

    inverte(l);

    printf("Lista invertida: ");
    lista_imprimir(l);                  // [50,40,30,20,10]
    printf("\n");
}

void teste_toString(){
    printf("\n------------------------------------------------\n");
    printf(">>> TESTE TO STRING\n");
    printf("------------------------------------------------\n");
    
    Lista* l = lista_criar();
    lista_anexar(l, 10);
    lista_anexar(l, 20);
    lista_anexar(l, 30);
    lista_anexar(l, 40);
    lista_anexar(l, 50);

    char str[500];
    lista_toString(l, str); 
    printf("%s\n", str); // [10,20,30,40,50]
    
}

void teste_intercalar(){
    printf("\n------------------------------------------------\n");
    printf(">>> TESTE INTERCALAR LISTAS\n");
    printf("------------------------------------------------\n");

    // Criando a primeira lista (lista1)
    Lista* lista1 = lista_criar();
    lista_anexar(lista1, 1);
    lista_anexar(lista1, 3);
    lista_anexar(lista1, 5);

    // Criando a segunda lista (lista2)
    Lista* lista2 = lista_criar();
    lista_anexar(lista2, 2);
    lista_anexar(lista2, 4);
    lista_anexar(lista2, 6);


    // Intercalando as listas
    Lista* intercalada = intercalaListas(lista1, lista2);

    // Imprimindo a lista1
    printf("Lista 1: ");
    lista_imprimir(lista1);
    printf("\n");

    // Imprimindo a lista2
    printf("Lista 2: ");
    lista_imprimir(lista2);
    printf("\n");


    // Imprimindo a lista intercalada
    printf("Lista intercalada: ");
    lista_imprimir(intercalada);
    printf("\n");

// Imprimindo a lista1
    printf("Lista 1: ");
    lista_imprimir(lista1);
    printf("\n");

    // Imprimindo a lista2
    printf("Lista 2: ");
    lista_imprimir(lista2);
    printf("\n");

    // Destruindo as listas para liberar a memória
    // lista_destruir(intercalada);
    // lista_destruir(lista1);
    // lista_destruir(lista2);


}

void teste_troca(){
    printf("\n------------------------------------------------\n");
    printf(">>> TESTE troca \n");
    printf("------------------------------------------------\n");
    
    Lista* l = lista_criar(); 
    lista_anexar(l, 10);
    lista_anexar(l, 20);
    lista_anexar(l, 30);
    lista_imprimir(l);         // [10,20,30]

    printf("\n");

    bool troca_ok = troca(l, 0, 2); // indice 0 e 2
    if (troca_ok) {
        printf("Lista depois da troca: ");
        lista_imprimir(l);
        printf("\n");
    } else {
        printf("Falha ao trocar elementos na lista.\n");
    }

}

void teste_ordenada() {
    printf("\n------------------------------------------------\n");
    printf(">>> TESTE EH ORDENADA \n");
    printf("------------------------------------------------\n");
    
    Lista* l1 = lista_criar();
    lista_anexar(l1, 10);
    lista_anexar(l1, 20);
    lista_anexar(l1, 30);
    
    printf("Lista 1: ");
    lista_imprimir(l1);
    printf("\n");
    printf("Lista 1 eh ordenada? %s\n", eh_ordenada(l1) ? "Sim" : "Não");
    
    Lista* l2 = lista_criar();
    lista_anexar(l2, 30);
    lista_anexar(l2, 20);
    lista_anexar(l2, 10);
    
    printf("Lista 2: ");
    lista_imprimir(l2);
    printf("\n");
    printf("Lista 2 eh ordenada? %s\n", eh_ordenada(l2) ? "Sim" : "Não");

    Lista* l3 = lista_criar();
    lista_anexar(l3, 10);
    lista_anexar(l3, 30);
    lista_anexar(l3, 20);
    
    printf("Lista 3: ");
    lista_imprimir(l3);
    printf("\n");
    printf("Lista 3 eh ordenada? %s\n", eh_ordenada(l3) ? "Sim" : "Não");

    Lista* l4 = lista_criar(); // Lista vazia
    
    printf("Lista 4: ");
    lista_imprimir(l4);
    printf("\n");
    printf("Lista 4 eh ordenada? %s\n", eh_ordenada(l4) ? "Sim" : "Não");

    Lista* l5 = lista_criar();
    lista_anexar(l5, 10);
    
    printf("Lista 5: ");
    lista_imprimir(l5);
    printf("\n");
    printf("Lista 5 eh ordenada? %s\n", eh_ordenada(l5) ? "Sim" : "Não");

    // Libera a memória das listas
    // lista_destruir(l1);
    // lista_destruir(l2);
    // lista_destruir(l3);
    // lista_destruir(l4);
    // lista_destruir(l5);
}


int main(){

    printf("TESTES\n");

    teste_inserir();
    teste_removerPosicao();
    teste_removerElemento();
    teste_toString();
    teste_inverter();
    teste_intercalar();
    teste_troca();
    teste_ordenada();
    
    return 0;
}