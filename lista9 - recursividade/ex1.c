#include <stdio.h>

float soma(int n, float *v) {
 
    if (n <= 0) {
        return 0.0;
    }
    //soma o primeiro elemento e chama a função recursivamente para o restante do vetor
    return v[0] + soma(n - 1, v + 1);
}

int main() {
   
    float vetor[] = {1.5, 2.0, 3.5, 4.5};
    int n = 4;
    float resultado = soma(n, vetor);
    //Saida esperada: 11.5
    printf("A soma dos elementos do vetor é: %f\n", resultado);
    return 0;
}