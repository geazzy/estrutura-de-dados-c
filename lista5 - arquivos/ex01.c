#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contarLetraA(FILE *file) {
    int count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == 'a' || ch == 'A') {
            count++;
        }
    }
    return count;
}

int contarSubstring(FILE *file, char* str) {
    int count = 0;
    char buffer[1024];
    size_t str_len = strlen(str);
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        char *ptr = buffer;
        while ((ptr = strstr(ptr, str)) != NULL) {
            count++;
            ptr += str_len;
        }
    }
    return count;
}

int main() {
    FILE *file;
    file = fopen("texto.txt", "r"); 

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int letras_a = contarLetraA(file);
    printf("O número de letras 'a' e 'A' no arquivo é: %d\n", letras_a);

    rewind(file); // Voltar ao início do arquivo para contar a substring novamente

    char substring[] = "prog"; 
    int substr_count = contarSubstring(file, substring);
    printf("O número de vezes que a substring '%s' aparece no arquivo é: %d\n", substring, substr_count);

    fclose(file);
    return 0;
}


