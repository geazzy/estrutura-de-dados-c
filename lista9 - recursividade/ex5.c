#include <stdio.h>

int potencia(int x, int n){
    if(n == 0){
        return 1;
    }

    if (n % 2 == 0){
        int temp = potencia(x, n / 2);
        return temp * temp;
    }
    else {
        return x * potencia(x, n - 1);
    }

    return x * potencia(x, n - 1);
}

int main(){
    int x = 2;
    int n = 10;
    int resultado = potencia(x, n);
    printf("%d^%d = %d\n", x, n, resultado);
    x = 2;
    n = 9;
    resultado = potencia(x, n);
    printf("%d^%d = %d\n", x, n, resultado);
    return 0;
}