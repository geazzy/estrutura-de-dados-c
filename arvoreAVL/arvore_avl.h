#ifndef _ARVORE_AVL_H_
#define _ARVORE_AVL_H_

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

typedef int TipoElemento;
typedef struct no No;



No* avl_inserir(No *raiz, TipoElemento elemento);

//Funções implementadas na Arvore Binária
bool  ab_consulta(No* raiz, TipoElemento dado);
void  ab_destruir(No** enderecoRaiz);
void  ab_pre_ordem(No* raiz);
void  ab_em_ordem(No* raiz);
void  ab_pos_ordem(No* raiz);
int   ab_altura(No *raiz);
int   ab_total_vertices(No *raiz);

#endif