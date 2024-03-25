#include <stdio.h>

#define MESES 12
#define SEMANAS 4

// Função para calcular o total vendido em um mês específico
float calcularTotalMes(float matriz[MESES][SEMANAS], int mes) {
    float totalMes = 0;
    for (int semana = 0; semana < SEMANAS; semana++) {
        totalMes += matriz[mes][semana];
    }
    return totalMes;
}

// Função para calcular o total vendido em uma semana específica
float calcularTotalSemana(float matriz[MESES][SEMANAS], int semana) {
    float totalSemana = 0;
    for (int mes = 0; mes < MESES; mes++) {
        totalSemana += matriz[mes][semana];
    }
    return totalSemana;
}

// Função para calcular o total vendido no ano
float calcularTotalAno(float matriz[MESES][SEMANAS]) {
    float totalAno = 0;
    for (int mes = 0; mes < MESES; mes++) {
        for (int semana = 0; semana < SEMANAS; semana++) {
            totalAno += matriz[mes][semana];
        }
    }
    return totalAno;
}

int main() {
    float vendas[MESES][SEMANAS];
    
    // Lendo os valores das vendas
    printf("Digite os valores das vendas:\n");
    for (int mes = 0; mes < MESES; mes++) {
        printf("Mês %d:\n", mes + 1);
        for (int semana = 0; semana < SEMANAS; semana++) {
            printf("Semana %d: ", semana + 1);
            scanf("%f", &vendas[mes][semana]);
        }
    }

    // Calculando e imprimindo o total vendido em cada mês
    printf("\nTotal vendido em cada mês do ano:\n");
    for (int mes = 0; mes < MESES; mes++) {
        printf("Mês %d: R$ %.2f\n", mes + 1, calcularTotalMes(vendas, mes));
    }

    // Calculando e imprimindo o total vendido em cada semana durante todo o ano
    printf("\nTotal vendido em cada semana durante todo o ano:\n");
    for (int semana = 0; semana < SEMANAS; semana++) {
        printf("Semana %d: R$ %.2f\n", semana + 1, calcularTotalSemana(vendas, semana));
    }

    // Calculando e imprimindo o total vendido no ano
    printf("\nTotal vendido no ano: R$ %.2f\n", calcularTotalAno(vendas));

    return 0;
}
