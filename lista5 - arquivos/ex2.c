#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 1000 // Tamanho máximo para o buffer de leitura

int main() {
    FILE *input_file, *output_file;
    char input_filename[] = "texto.txt";
    char output_filename[] = "texto_modificado.txt";
    char buffer[MAX_SIZE];
    
    // Abrir o arquivo de entrada para leitura
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }
    
    // Abrir o arquivo de saída para escrita
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        fclose(input_file);
        return 1;
    }
    
    // Ler o conteúdo do arquivo de entrada e modificar para maiúsculas
    while (fgets(buffer, MAX_SIZE, input_file) != NULL) {
        for (int i = 0; buffer[i] != '\0'; i++) {
            buffer[i] = toupper(buffer[i]); // Converte para maiúsculas
        }
        fputs(buffer, output_file); // Escreve no arquivo de saída
    }
    

    fclose(input_file);
    fclose(output_file);
    
    printf("Arquivo modificado com sucesso!\n");
    return 0;
}