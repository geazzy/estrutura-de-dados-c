#include <stdio.h>

float calcular_salario(float salario_base, int indice_produtividade) {
    if (indice_produtividade == 1) {
        return salario_base * 1.65; // Excelente: +65% do salário base
    } else if (indice_produtividade == 2) {
        return salario_base * 1.20; // Intermediário: +20% do salário base
    } else if (indice_produtividade == 3) {
        return salario_base * 0.90; // Regular: -10% do salário base
    } else {
        return salario_base; // Índice inválido, retorna o salário base
    }
}

int main() {
    float salario_base;
    int indice_produtividade;

    printf("Digite o salário base do funcionário: ");
    scanf("%f", &salario_base);

    printf("Digite o índice de produtividade (1 para Excelente, 2 para Intermediário, 3 para Regular): ");
    scanf("%d", &indice_produtividade);

    float salario_com_abono = calcular_salario(salario_base, indice_produtividade);
    printf("O salário com o abono é: R$ %.2f\n", salario_com_abono);

    return 0;
}
