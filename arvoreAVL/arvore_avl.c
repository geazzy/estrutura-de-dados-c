#include "arvore_avl.h"

/**************************************
* DADOS
**************************************/

struct no{
  TipoElemento dado;
  int altura;
  struct no *esq, *dir;
};

/**************************************
* FUNÇÕES AUXILIARES
**************************************/

int altura(No *no){
    if (no == NULL)
        return 0;
    return no->altura;
}

int fator_balanceamento(No *no){
    return altura(no->esq) - altura(no->dir);
}

No* novoNo(TipoElemento valor){
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->esq = novo->dir = NULL;
    novo->altura = 1;
    return novo;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

No* rotacao_direita(No *y){
    No *x = y->esq;
    No *T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    y->altura = max(altura(y->esq), altura(y->dir)) + 1;
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;

    return x;
}

No* rotacao_esquerda(No *x){
    No *y = x->dir;
    No *T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->altura = max(altura(x->esq), altura(x->dir)) + 1;
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;

    return y;
}

No* rotacao_dupla_direita(No *z){
    z->esq = rotacao_esquerda(z->esq);
    return rotacao_direita(z);
}

No* rotacao_dupla_esquerda(No *z){
    z->dir = rotacao_direita(z->dir);
    return rotacao_esquerda(z);
}

/**************************************
* IMPLEMENTAÇÃO
**************************************/

No* avl_inserir(No *raiz, TipoElemento elemento){
    if (raiz == NULL)
        return novoNo(elemento);

    if (elemento < raiz->dado)
        raiz->esq = avl_inserir(raiz->esq, elemento);
    else if (elemento > raiz->dado)
        raiz->dir = avl_inserir(raiz->dir, elemento);
    else
        return raiz;

    raiz->altura = 1 + max(altura(raiz->esq), altura(raiz->dir));

    int balance = fator_balanceamento(raiz);

    if (balance > 1 && elemento < raiz->esq->dado)
        return rotacao_direita(raiz);

    if (balance < -1 && elemento > raiz->dir->dado)
        return rotacao_esquerda(raiz);

    if (balance > 1 && elemento > raiz->esq->dado)
        return rotacao_dupla_direita(raiz);

    if (balance < -1 && elemento < raiz->dir->dado)
        return rotacao_dupla_esquerda(raiz);

    return raiz;
}

bool ab_consulta(No* raiz, TipoElemento dado) {
    if (raiz == NULL) return false;
    if (dado < raiz->dado) return ab_consulta(raiz->esq, dado);
    if (dado > raiz->dado) return ab_consulta(raiz->dir, dado);
    return true;
}

void ab_destruir(No** enderecoRaiz) {
    if (*enderecoRaiz == NULL) return;
    ab_destruir(&(*enderecoRaiz)->esq);
    ab_destruir(&(*enderecoRaiz)->dir);
    free(*enderecoRaiz);
    *enderecoRaiz = NULL;
}

void ab_pre_ordem(No* raiz) {
    if (raiz == NULL) return;
    printf("%d ", raiz->dado);
    ab_pre_ordem(raiz->esq);
    ab_pre_ordem(raiz->dir);
}

void ab_em_ordem(No* raiz) {
    if (raiz == NULL) return;
    ab_em_ordem(raiz->esq);
    printf("%d ", raiz->dado);
    ab_em_ordem(raiz->dir);
}

void ab_pos_ordem(No* raiz) {
    if (raiz == NULL) return;
    ab_pos_ordem(raiz->esq);
    ab_pos_ordem(raiz->dir);
    printf("%d ", raiz->dado);
}

int ab_altura(No *raiz) {
    if (raiz == NULL) return 0;
    int esq_altura = ab_altura(raiz->esq);
    int dir_altura = ab_altura(raiz->dir);
    return 1 + (esq_altura > dir_altura ? esq_altura : dir_altura);
}

int ab_total_vertices(No *raiz) {
    if (raiz == NULL) return 0;
    return 1 + ab_total_vertices(raiz->esq) + ab_total_vertices(raiz->dir);
}