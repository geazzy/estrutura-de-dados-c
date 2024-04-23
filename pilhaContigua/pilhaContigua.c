#include <stdlib.h>
#include <stdio.h>

typedef enum boolean{false=0, true=1} Boolean;
typedef int TipoElemento;

// DADOS

typedef struct {
	TipoElemento* vetor;
	int tamVetor;
	int qtde;
}Pilha;


//PROTÓTIPOS

Pilha* pilha_criar();
void pilha_destruir(Pilha* p);
Boolean pilha_empilhar(Pilha* p, TipoElemento elemento);
Boolean pilha_desempilhar(Pilha* p, TipoElemento* saida); // estratégia do scanf
Boolean pilha_topo(Pilha* p, TipoElemento* saida); // estratégia do scanf
Boolean pilha_vazia(Pilha* p);
void pilha_imprimir(Pilha* p);
int pilha_tamanho(Pilha* p);
Pilha* pilha_clone(Pilha* p);
void pilha_inverter(Pilha* p);
Boolean pilha_empilharTodos(Pilha* p, TipoElemento* vetor, int tamVetor);


//Implementação da função de criar pilha
Pilha* pilha_criar(){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    if(p != NULL){
        p->tamVetor = 10;
        p->vetor = (TipoElemento*)malloc(p->tamVetor*sizeof(TipoElemento));
        if(p->vetor == NULL){
            free(p);
            return NULL;
        }
        p->qtde = 0;
    }
    return p;
}

//Implementação da função de destruir pilha
void pilha_destruir(Pilha* p){
    if(p != NULL){
        if(p->vetor != NULL){
            free(p->vetor);
        }
        free(p);
    }
}

//Implementação da função de empilhar
Boolean pilha_empilhar(Pilha* p, TipoElemento elemento){
    if(p != NULL){
        if(p->qtde == p->tamVetor){
            p->tamVetor *= 2;
            TipoElemento* vetorTemp = (TipoElemento*)malloc(p->tamVetor*sizeof(TipoElemento));
            if(vetorTemp == NULL){
                return false;
            }
            for(int i = 0; i < p->qtde; i++){
                vetorTemp[i] = p->vetor[i];
            }
            free(p->vetor);
            p->vetor = vetorTemp;
        }
        p->vetor[p->qtde] = elemento;
        p->qtde++;
        return true;
    }
    return false;
}

//Implementação da função de desempilhar
Boolean pilha_desempilhar(Pilha* p, TipoElemento* saida){
    if(p != NULL && p->qtde > 0){
        *saida = p->vetor[p->qtde-1];
        p->qtde--;
        return true;
    }
    return false;
}


//Implementação da função de topo
Boolean pilha_topo(Pilha* p, TipoElemento* saida){
    if(p != NULL && p->qtde > 0){
        *saida = p->vetor[p->qtde-1];
        return true;
    }
    return false;
}

//Implementação da função de vazia
Boolean pilha_vazia(Pilha* p){
    if(p != NULL){
        return p->qtde == 0;
    }
    return false;
}

//Implementação da função de imprimir
void pilha_imprimir(Pilha* p){
    if(p != NULL){
        for(int i = p->qtde-1; i >= 0; i--){
            printf("%d\n", p->vetor[i]);
        }
    }
}

//Implementação da função de tamanho
int pilha_tamanho(Pilha* p){
    if(p != NULL){
        return p->qtde;
    }
    return -1;
}

//Implementação da função de clone
Pilha* pilha_clone(Pilha* p){
    if(p != NULL){
        Pilha* clone = (Pilha*)malloc(sizeof(Pilha));
        if(clone != NULL){
            clone->tamVetor = p->tamVetor;
            clone->vetor = (TipoElemento*)malloc(clone->tamVetor*sizeof(TipoElemento));
            if(clone->vetor == NULL){
                free(clone);
                return NULL;
            }
            clone->qtde = p->qtde;
            for(int i = 0; i < p->qtde; i++){
                clone->vetor[i] = p->vetor[i];
            }
            return clone;
        }
    }
    return NULL;
}

//Implementação da função de inverter
void pilha_inverter(Pilha* p){
    if(p != NULL){
        TipoElemento* vetorTemp = (TipoElemento*)malloc(p->tamVetor*sizeof(TipoElemento));
        if(vetorTemp == NULL){
            return;
        }
        for(int i = 0; i < p->qtde; i++){
            vetorTemp[i] = p->vetor[p->qtde-i-1];
        }
        free(p->vetor);
        p->vetor = vetorTemp;
    }
}

//Implementação da função de empilhar todos
Boolean pilha_empilharTodos(Pilha* p, TipoElemento* vetor, int tamVetor){
    if(p != NULL){
        for(int i = 0; i < tamVetor; i++){
            if(!pilha_empilhar(p, vetor[i])){
                return false;
            }
        }
        return true;
    }
    return false;
}
int main() {
    Pilha* p = pilha_criar();
    TipoElemento vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    pilha_empilharTodos(p, vetor, 10);

    printf("Tamanho da pilha: %d\n", pilha_tamanho(p));

    TipoElemento topo;
    if (pilha_topo(p, &topo)) {
        printf("Elemento do topo: %d\n", topo);
    } else {
        printf("Pilha vazia.\n");
    }

    printf("Pilha:\n");
    pilha_imprimir(p);

    printf("Desempilhando...\n");
    if (pilha_desempilhar(p, &topo)) {
        printf("Elemento desempilhado: %d\n", topo);
    } else {
        printf("Erro ao desempilhar: pilha vazia.\n");
    }

    printf("Desempilhando novamente...\n");
    if (pilha_desempilhar(p, &topo)) {
        printf("Elemento desempilhado: %d\n", topo);
    } else {
        printf("Erro ao desempilhar: pilha vazia.\n");
    }

    printf("Restante da pilha:\n");
    pilha_imprimir(p);

    printf("Invertendo a pilha...\n");
    pilha_inverter(p);
    printf("Pilha invertida:\n");
    pilha_imprimir(p);

    Pilha* clone = pilha_clone(p);
    printf("Pilha clonada:\n");
    pilha_imprimir(clone);

    pilha_destruir(clone);
    pilha_destruir(p);

    return 0;
}
