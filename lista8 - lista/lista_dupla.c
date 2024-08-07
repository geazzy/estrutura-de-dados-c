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
	No *inicio;
	No *fim;
	int qtde;
};


/**************************************
* FUNÇÕES AUXILIARES
**************************************/
No* criar_no(TipoElemento elemento){
    No* no = (No*) malloc(sizeof(No));
    no->dado = elemento;
    no->prox = NULL;
    no->ant = NULL;
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
    No* aux = l->inicio;
    int i;
    for(i=0; i < pos; i++) 
        aux = aux->prox;
    return aux;
}



/**************************************
* IMPLEMENTAÇÃO
**************************************/

Lista* lista_criar(){
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qtde = 0;
    return lista;
}

void lista_destruir(Lista** endLista){
    Lista* l = *endLista;
    No* aux;
    while(l->inicio->prox != NULL){
        aux = l->inicio->prox;
        l->inicio = l->inicio->prox;
        free(aux);
    }
    free(l->inicio);
    free(l);
    *endLista = NULL;
}

//Anexa um novo elemento no final da lista
bool lista_anexar(Lista* l, TipoElemento elemento){
    if(!lista_ehValida(l)) return false;

    No* novo = criar_no(elemento);
    if(lista_vazia(l)){
        l->inicio = novo;        
    }else{
        l->fim->prox = novo;
        novo->ant = l->fim;
    }
    l->fim = novo;
    l->qtde++;
    return true;
}

//Insere um novo elemento na posição indicada
bool lista_inserir(Lista* l, TipoElemento elemento, int posicao){
    if(!lista_ehValida(l)) return false;
    posicao = converte_posicao(l, posicao);
    if(!posicao_ehValida(l, posicao)) return false;
    
    No* novo = criar_no(elemento);

    if(l->qtde == 0){
        l->inicio = novo;
        l->fim = novo;
    }else if(posicao == l->qtde){
        lista_anexar(l, elemento);
    }else if(posicao == 0){
        novo->prox = l->inicio;
        l->inicio->ant = novo;
        l->inicio = novo;
        l->qtde++;
    }else{
        No* aux = devolve_enderecoNo(l, posicao-1);
        novo->prox = aux->prox;
        novo->ant = aux;
        aux->prox->ant = novo;
        aux->prox = novo;
        l->qtde++;
    }
    return true;
}

bool lista_removerPosicao(Lista* l, int posicao, TipoElemento* endereco){
    if(!lista_ehValida(l)) return false;
    posicao = converte_posicao(l, posicao);
    if(!posicao_ehPreenchida(l, posicao)) return false;

    No* aux;
    if(l->qtde == 1){
        aux = l->inicio;
        l->inicio = NULL;
        l->fim = NULL;

    }else if(posicao == 0){
        aux = l->inicio;
        l->inicio = l->inicio->prox;
        l->inicio->ant = NULL;
        aux->prox = NULL;

    }else if(posicao == l->qtde-1){
        aux = l->fim;
        l->fim = l->fim->ant;
        l->fim->prox = NULL;
        aux->ant = NULL;
    }else{
        aux = devolve_enderecoNo(l, posicao);
        aux->prox->ant = aux->ant;
        aux->ant->prox = aux->prox;
        aux->prox = NULL; 
        aux->ant = NULL; 
    }
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
    No* aux = l->inicio;
    while(aux != NULL){
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
    return (posicao != -1 ? true : false);

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
    No* aux = l->inicio;
    while(aux != NULL){
        sprintf(elemento, FORMATO, aux->dado);
        strcat(str, elemento);
        
        if(aux->prox != NULL) strcat(str, ",");

        aux = aux->prox;
    }

    strcat(str, "]");
    return true;
}

void lista_imprimir(Lista* l){
    if(!lista_ehValida(l)) return;

    printf("[");
    No* aux = l->inicio;
    while(aux != NULL){
        printf(FORMATO, aux->dado);
        if(aux->prox != NULL) printf(",");
        aux = aux->prox;
    }
    printf("]");
}

bool inverte(Lista *l) {
    if (!lista_ehValida(l)) return false;
    if (l->qtde < 2) return true;

    No *temp = NULL;
    No *current = l->inicio;

    // Invertendo o ponteiro de próximo e anterior de todos os nós
    while (current != NULL) {
        temp = current->ant;
        current->ant = current->prox;
        current->prox = temp;
        current = current->ant;
    }

    // Ajustando os ponteiros início e fim
    if (temp != NULL) {
        l->fim = l->inicio;
        l->inicio = temp->ant;
    }

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

    No *no1 = l1->inicio;
    No *no2 = l2->inicio;

    while (no1 != NULL && no2 != NULL) {
        TipoElemento elemento1 = no1->dado;
        TipoElemento elemento2 = no2->dado;
        
        lista_anexar(intercalada, elemento1);
        lista_anexar(intercalada, elemento2);
        
        no1 = no1->prox;
        no2 = no2->prox;
    }

    // Adicionar os elementos restantes de l1, se houver
    while (no1 != NULL) {
        TipoElemento elemento1 = no1->dado;
        lista_anexar(intercalada, elemento1);
        no1 = no1->prox;
    }

    // Adicionar os elementos restantes de l2, se houver
    while (no2 != NULL) {
        TipoElemento elemento2 = no2->dado;
        lista_anexar(intercalada, elemento2);
        no2 = no2->prox;
    }

    // Limpar as listas l1 e l2 (opcional)
    // lista_destruir(&l1);
    // lista_destruir(&l2);

    return intercalada;
}
/// @brief  Troca os elementos das posições x e y da lista
/// @param l Lista
/// @param x Indice x 
/// @param y Indice y
/// @return lista com os elementos trocados
bool troca(Lista* l, int x, int y) {
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
    if (l == NULL || l->inicio == NULL) return true; // Lista vazia é considerada ordenada

    No *atual = l->inicio;
    bool crescente = true;
    bool decrescente = true;

    while (atual->prox != NULL) {
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