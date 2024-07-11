#include <stdio.h>
#include <string.h>

#include "fila.h"

int main(){

    TipoElemento elemento;
      /**************************************
    * Teste insercao e primeiro
    **************************************/
    Fila* f1 = fila_criar();
    fila_inserir(f1, 10);
    fila_inserir(f1, 20);
    fila_inserir(f1, 30);
    fila_primeiro(f1, &elemento);

    /**************************************
    * Teste remocao
    **************************************/
    fila_remover(f1, &elemento);
    fila_remover(f1, &elemento);  
    fila_remover(f1, &elemento); 
    bool resultado = fila_remover(f1, &elemento);
    fila_destruir(&f1);

       

    /**************************************
    * Teste inserir todos e clone
    **************************************/
    int vetor[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    f1 = fila_criar();
    //fila_inserirTodos(f1, vetor, 12);
     
    //Fila* f2 = fila_clone(f1);
    //fila_remover(f2, &elemento);
    //fila_remover(f2, &elemento);
    //fila_remover(f2, &elemento);
    //fila_inserir(f2, 20);
    //fila_inserir(f2, 21);
    //fila_inserir(f2, 22);

    fila_destruir(&f1);
    //fila_destruir(&f2);

}
