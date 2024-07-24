#include <stdio.h>

int soma_digitos(int n) {
    if (n < 10) {
        return n;
    }
    return (n % 10) + soma_digitos(n / 10);
}

int main() {
    int numero = 12345;
    int resultado = soma_digitos(numero);
    printf("A soma dos digitos de %d é: %d\n", numero, resultado);
    return 0;
}