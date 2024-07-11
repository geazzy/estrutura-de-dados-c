#include "lista.h"
#include "string.h"

/**************************************
* DADOS
**************************************/
typedef struct no{
	TipoElemento dado;
	struct no    *ant;
	struct no    *prox;
}No;

struct lista{
	No *sentinela;
	int qtde;
};


/**************************************
* FUNÇÕES AUXILIARES
**************************************/
No* criar_no(TipoElemento elemento){
    No* no = (No*) malloc(sizeof(No));
    no->dado = elemento;
    return no;
}

No* criar_noSentinela(){
    No* no = (No*) malloc(sizeof(No));
    no->ant = no;
    no->prox = no;
    return no;
}

bool lista_ehValida(Lista* l){
    return (l != NULL? true: false);    
}

bool posicao_ehValida(Lista* l, int pos){
    if(pos < 0) return false;
    if(pos > l->qtde) return false;

    return true;
}

bool posicao_ehPreenchida(Lista* l, int pos){
    if(pos < 0) return false;
    if(pos >= l->qtde) return false;

    return true;
}

int converte_posicao(Lista* l, int pos){
    return (pos < 0? l->qtde + pos : pos);
}

No* devolve_enderecoNo(Lista* l, int pos){
    No* aux = l->sentinela;
    int i;
    for(i=0; i <= pos; i++) 
        aux = aux->prox;
    return aux;
}

void insere_direita(No* referencia, No* novo){
    novo->ant = referencia;
    novo->prox = referencia->prox;

    referencia->prox->ant = novo;
    referencia->prox = novo;
}

void desconecta_no(No* no){
    no->prox->ant = no->ant;
    no->ant->prox = no->prox;
    no->ant = no->prox = NULL;
}


/**************************************
* IMPLEMENTAÇÃO
**************************************/

Lista* lista_criar(){
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    lista->sentinela = criar_noSentinela();
    lista->qtde = 0;
    return lista;
}

void lista_destruir(Lista** endLista){
    Lista* l = *endLista;
    No* aux;
    while(l->sentinela->prox != l->sentinela){
        aux = l->sentinela->prox;
        l->sentinela = l->sentinela->prox;
        free(aux);
    }
    free(l->sentinela);
    free(l);
    *endLista = NULL;
}

bool lista_anexar(Lista* l, TipoElemento elemento){
    if(!lista_ehValida(l)) return false;

    lista_inserir(l, elemento, l->qtde);

    return true;
}

bool lista_inserir(Lista* l, TipoElemento elemento, int posicao){
    if(!lista_ehValida(l)) return false;
    posicao = converte_posicao(l, posicao);
    if(!posicao_ehValida(l, posicao)) return false;
    
    No* novo = criar_no(elemento);
    No* aux = devolve_enderecoNo(l, posicao-1);

    insere_direita(aux, novo);

    l->qtde++;
    return true;

}

bool lista_removerPosicao(Lista* l, int posicao, TipoElemento* endereco){
    if(!lista_ehValida(l)) return false;
    posicao = converte_posicao(l, posicao);
    if(!posicao_ehPreenchida(l, posicao)) return false;
    

    No* aux = devolve_enderecoNo(l, posicao);
    desconecta_no(aux);
    *endereco = aux->dado;
    free(aux);
    l->qtde--;
    return true;
}

int lista_removerElemento(Lista* l, TipoElemento elemento){
    if(!lista_ehValida(l)) return false;

    int posicao = lista_posicao(l, elemento);
    if(posicao == -1) return -1;
    
    TipoElemento item;
    lista_removerPosicao(l, posicao, &item);
    return posicao;
}

bool lista_substituir(Lista* l, int posicao, TipoElemento novoElemento){
    if(!lista_ehValida(l)) return false;
    posicao = converte_posicao(l, posicao);
    if(!posicao_ehPreenchida(l, posicao)) return false;

    No* no = devolve_enderecoNo(l, posicao);
    no->dado = novoElemento;
    return true;
}

bool lista_vazia(Lista* l){
    if(!lista_ehValida(l)) return true;

    return (l->qtde == 0 ? true : false);
}

int lista_posicao(Lista* l, TipoElemento elemento){
    if(!lista_ehValida(l)) return -1;

    int i = 0;
    No* aux = l->sentinela->prox;
    while(aux != l->sentinela){
        if(elemento == aux->dado) return i;
        aux = aux->prox;
        i++;
    }
    return -1;

}

bool lista_buscar(Lista* l, int posicao, TipoElemento* endereco){
    if(!lista_ehValida(l)) return false;
    posicao = converte_posicao(l, posicao);
    if(!posicao_ehPreenchida(l, posicao)) return false;

    No* no = devolve_enderecoNo(l, posicao);
    *endereco = no->dado;
    return true;

    
}
bool lista_contem(Lista* l, TipoElemento elemento){
    if(!lista_ehValida(l)) return false;

    int posicao = lista_posicao(l, elemento);
    return (posicao != -1? true : false);

}
int lista_tamanho(Lista* l){
    if(!lista_ehValida(l)) return -1;

    return l->qtde;
}

bool lista_toString(Lista* l, char* str){
    if(!lista_ehValida(l)) return false;

    int qtde = 0;
    char elemento[20];

    str[0] = '\0';
    strcat(str, "[");
    No* aux = l->sentinela->prox;
    while(aux != l->sentinela){
        sprintf(elemento, FORMATO, aux->dado);
        strcat(str, elemento);
        
        if(aux->prox != l->sentinela) strcat(str, ",");
            
        aux = aux->prox;
    }
    strcat(str, "]");
    return true;
}

void lista_imprimir(Lista* l){
    if(!lista_ehValida(l)) return;

    printf("[");
    No* aux = l->sentinela->prox;
    while(aux != l->sentinela){
        printf(FORMATO, aux->dado);
        if(aux->prox != l->sentinela) printf(", ");
        aux = aux->prox;
    }
    printf("]");
}

bool inverte(Lista* l){
    if(!lista_ehValida(l) || l->qtde <= 1) return false;

    No *atual = l->sentinela->prox;
    No *anterior = l->sentinela;
    No *proximo = NULL;

    while(atual != l->sentinela){
        proximo = atual->prox;
        atual->prox = anterior;
        anterior->ant = atual;
        anterior = atual;
        atual = proximo;
    }

    l->sentinela->prox = anterior;
    l->sentinela->prox->ant = l->sentinela;

    return true;
}

Lista* intercalaListas(Lista* l1, Lista* l2) {
    if (l1 == NULL || l2 == NULL) {
        return NULL;
    }

    Lista* intercalada = lista_criar();
    if (intercalada == NULL) {
        return NULL;
    }

    No *no1 = l1->sentinela->prox;
    No *no2 = l2->sentinela->prox;

    while (no1 != l1->sentinela && no2 != l2->sentinela) {
        lista_anexar(intercalada, no1->dado);
        no1 = no1->prox;

        lista_anexar(intercalada, no2->dado);
        no2 = no2->prox;
    }

    while (no1 != l1->sentinela) {
        lista_anexar(intercalada, no1->dado);
        no1 = no1->prox;
    }

    while (no2 != l2->sentinela) {
        lista_anexar(intercalada, no2->dado);
        no2 = no2->prox;
    }

    return intercalada;
}

// Função para trocar elementos das posições x e y na lista com sentinela

bool troca(Lista *l, int x, int y) {
    if (!lista_ehValida(l)) {
        return false;
    }

    // Convertendo posições negativas
    int pos_x = converte_posicao(l, x);
    int pos_y = converte_posicao(l, y);

    // Verificando se as posições são válidas
    if (!posicao_ehPreenchida(l, pos_x) || !posicao_ehPreenchida(l, pos_y)) {
        return false;
    }

    // Encontrando os nós correspondentes às posições x e y
    No *no_x = devolve_enderecoNo(l, pos_x);
    No *no_y = devolve_enderecoNo(l, pos_y);

    // Trocando os elementos
    TipoElemento temp = no_x->dado;
    no_x->dado = no_y->dado;
    no_y->dado = temp;

    return true;
}

bool eh_ordenada(Lista *l) {
    if (l == NULL || l->sentinela->prox == l->sentinela) return true; // Lista vazia ou com um elemento é considerada ordenada

    No *atual = l->sentinela->prox;
    bool crescente = true;
    bool decrescente = true;

    while (atual->prox != l->sentinela) {
        if (atual->dado > atual->prox->dado) {
            crescente = false;
        }
        if (atual->dado < atual->prox->dado) {
            decrescente = false;
        }
        atual = atual->prox;
    }

    return crescente || decrescente;
}
