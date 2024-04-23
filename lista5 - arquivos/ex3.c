#include <stdio.h>
#include <stdlib.h>

// Função para carregar um array de inteiros a partir de um arquivo
int getArrayFromFile(FILE* file, int** vet) {
    int tamanho;
    
    fscanf(file, "%d", &tamanho);
    
    // Aloca memória para o array dinamicamente
    *vet = (int*)malloc(tamanho * sizeof(int));
    if (*vet == NULL) {
        printf("Erro ao alocar memória para o array.\n");
        return -1;
    }
    
    // Lê os elementos do array
    for (int i = 0; i < tamanho; i++) {
        fscanf(file, "%d", &((*vet)[i]));
    }
    
    return tamanho;
}

// Função para ordenar um array de inteiros (usando bubble sort)
void sort_array(int* vet, int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (vet[j] > vet[j + 1]) {
                // Troca os elementos
                int temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
        }
    }
}

// Função para escrever um array de inteiros em um arquivo
void escreve_array(int* vet, int tam, FILE* file) {
    // Escreve o tamanho do array no arquivo
    fprintf(file, "%d\n", tam);
    
    // Escreve os elementos do array separados por espaço
    for (int i = 0; i < tam; i++) {
        fprintf(file, "%d ", vet[i]);
    }
}

int main() {
    FILE *input_file, *output_file;
    char input_filename[] = "array.txt";
    char output_filename[] = "array2.txt";
    int *array;
    int tamanho;
    
    // Abre o arquivo de entrada para leitura
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }
    
    // Carrega o array a partir do arquivo de entrada
    tamanho = getArrayFromFile(input_file, &array);
    if (tamanho == -1) {
        fclose(input_file);
        return 1;
    }
    fclose(input_file);
    
    sort_array(array, tamanho);
    
    // Abre o arquivo de saída para escrita
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        free(array); // Libera a memória alocada para o array
        return 1;
    }
    
    // Escreve o array ordenado no arquivo de saída
    escreve_array(array, tamanho, output_file);
    fclose(output_file);
    free(array);
    
    printf("Array ordenado e salvo no arquivo com sucesso!\n");
    return 0;
}
