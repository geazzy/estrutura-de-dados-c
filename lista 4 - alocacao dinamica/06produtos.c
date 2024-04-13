#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned int codigo;
    char nome[50];
    float preco;
} Produto;

Produto* criarProduto(unsigned int codigo, const char* nome, float preco) {
    Produto* novoProduto = (Produto*)malloc(sizeof(Produto));
    if (novoProduto == NULL) {
        printf("Erro: não foi possível alocar memória para o produto.\n");
        exit(1);
    }

    novoProduto->codigo = codigo;
    strncpy(novoProduto->nome, nome, sizeof(novoProduto->nome));
    novoProduto->preco = preco;

    return novoProduto;
}

void imprimirProduto(Produto* produto) {
    printf("Código: %u\n", produto->codigo);
    printf("Nome: %s\n", produto->nome);
    printf("Preço: %.2f\n", produto->preco);
}

int main() {
    // Exemplo de utilização das funções
    Produto* produto1 = criarProduto(1, "Produto A", 10.99);
    Produto* produto2 = criarProduto(2, "Produto B", 20.49);

    printf("Produto 1:\n");
    imprimirProduto(produto1);

    printf("\nProduto 2:\n");
    imprimirProduto(produto2);

    // Liberar memória alocada dinamicamente
    free(produto1);
    free(produto2);

    return 0;
}
