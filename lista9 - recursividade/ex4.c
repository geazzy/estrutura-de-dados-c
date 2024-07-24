#include <stdio.h>

int ciclo(int n){
    int comprimento = 1;
    printf("%d ", n);
    while(n != 1){
        if(n % 2 == 0){
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        printf("%d ", n);
        comprimento++;
    }
    printf("\n");
    return comprimento;
}

int cicloR(int n){
    printf("%d ", n);
    if(n == 1){
        printf("\n");
        return 1;
    }
    if(n % 2 == 0){
        return 1 + cicloR(n / 2);
    } else {
        return 1 + cicloR(3 * n + 1);
    }
}

int main(){
    int n = 22;
    int resultado = ciclo(n);
    printf("Comprimento do ciclo: %d\n", resultado);
    resultado = cicloR(n);
    printf("[RECURSIVO] Comprimento do ciclo: %d\n", resultado);
    return 0;
}
