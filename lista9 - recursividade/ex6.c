#include <stdio.h>

int busca_binaria(int *v, int inicio, int fim, int item){
    if(inicio > fim){
        return -1; // se o item não foi encontrado
    }
    int meio = (inicio + fim) / 2;
    if(v[meio] == item){
        return meio;
    }
    if(v[meio] < item){
        return busca_binaria(v, meio + 1, fim, item);
    }
    return busca_binaria(v, inicio, meio - 1, item);
}

int main(){
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    int item = 10;
    int resultado = busca_binaria(v, 0, n - 1, item);
    if(resultado == -1){
        printf("Item não encontrado\n");
    } else {
        printf("Item encontrado na posição %d\n", resultado);
    }
    return 0;
}