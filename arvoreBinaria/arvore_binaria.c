#include "arvore_binaria.h"

/**************************************
* DADOS
**************************************/

struct no {
    TipoElemento dado;
    struct no *esq, *dir;
};

/**************************************
* FUNÇÕES AUXILIARES
**************************************/
void destruir_no(No* raiz) {
    if (raiz != NULL) {
        destruir_no(raiz->esq);
        destruir_no(raiz->dir);
        free(raiz);
    }
}

No* criar_no(TipoElemento dado) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo != NULL) {
        novo->dado = dado;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

No* remover_no(No* raiz, TipoElemento dado) {
    if (raiz == NULL) return NULL;

    if (dado < raiz->dado) {
        raiz->esq = remover_no(raiz->esq, dado);
    } else if (dado > raiz->dado) {
        raiz->dir = remover_no(raiz->dir, dado);
    } else {
        if (raiz->esq == NULL) {
            No* temp = raiz->dir;
            free(raiz);
            return temp;
        } else if (raiz->dir == NULL) {
            No* temp = raiz->esq;
            free(raiz);
            return temp;
        }

        No* temp = raiz->dir;
        while (temp && temp->esq != NULL)
            temp = temp->esq;

        raiz->dado = temp->dado;
        raiz->dir = remover_no(raiz->dir, temp->dado);
    }
    return raiz;
}

/**************************************
* IMPLEMENTAÇÃO
**************************************/

void ab_destruir(No **enderecoRaiz) {
    if (enderecoRaiz != NULL) {
        destruir_no(*enderecoRaiz);
        *enderecoRaiz = NULL;
    }
}

bool ab_inserir(No **enderecoRaiz, TipoElemento dado) {
    if (enderecoRaiz == NULL) return false;
    if (*enderecoRaiz == NULL) {
        *enderecoRaiz = criar_no(dado);
        return (*enderecoRaiz != NULL);
    }

    No* atual = *enderecoRaiz;
    while (true) {
        if (dado < atual->dado) {
            if (atual->esq == NULL) {
                atual->esq = criar_no(dado);
                return (atual->esq != NULL);
            }
            atual = atual->esq;
        } else if (dado > atual->dado) {
            if (atual->dir == NULL) {
                atual->dir = criar_no(dado);
                return (atual->dir != NULL);
            }
            atual = atual->dir;
        } else {
            return false; // Elemento já existe
        }
    }
}

bool ab_remover(No** enderecoRaiz, TipoElemento dado) {
    if (enderecoRaiz == NULL || *enderecoRaiz == NULL) return false;

    *enderecoRaiz = remover_no(*enderecoRaiz, dado);
    return true;
}

bool ab_consulta(No* raiz, TipoElemento dado) {
    while (raiz != NULL) {
        if (dado < raiz->dado) {
            raiz = raiz->esq;
        } else if (dado > raiz->dado) {
            raiz = raiz->dir;
        } else {
            return true;
        }
    }
    return false;
}

void ab_pre_ordem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);
        ab_pre_ordem(raiz->esq);
        ab_pre_ordem(raiz->dir);
    }
}

void ab_em_ordem(No* raiz) {
    if (raiz != NULL) {
        ab_em_ordem(raiz->esq);
        printf("%d ", raiz->dado);
        ab_em_ordem(raiz->dir);
    }
}

void ab_pos_ordem(No* raiz) {
    if (raiz != NULL) {
        ab_pos_ordem(raiz->esq);
        ab_pos_ordem(raiz->dir);
        printf("%d ", raiz->dado);
    }
}

int ab_altura(No *raiz) {
    if (raiz == NULL) return -1;

    int altura_esq = ab_altura(raiz->esq);
    int altura_dir = ab_altura(raiz->dir);

    return 1 + (altura_esq > altura_dir ? altura_esq : altura_dir);
}

int ab_total_vertices(No *raiz) {
    if (raiz == NULL) return 0;

    int total_esq = ab_total_vertices(raiz->esq);
    int total_dir = ab_total_vertices(raiz->dir);

    return 1 + total_esq + total_dir;
}
