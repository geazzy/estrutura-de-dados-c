#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura para veículos
struct Veiculo {
    int numero;
    char modelo[50];
    char cor[20];
    float preco;
    int ano;
};

// Função para armazenar um novo registro de veículo no final do arquivo
void adicionarVeiculo(struct Veiculo novoVeiculo, const char* filename) {
    FILE* file = fopen(filename, "ab");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de veículos.\n");
        return;
    }
    
    fwrite(&novoVeiculo, sizeof(struct Veiculo), 1, file);
    
    fclose(file);
}

// Função para ler os registros de veículos do ano de 2014 e retornar um array dinâmico
struct Veiculo* getVeiculos2014(const char* filename, int* numVeiculos) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de veículos.\n");
        *numVeiculos = 0;
        return NULL;
    }
    
    // Conta quantos veículos são do ano de 2014
    *numVeiculos = 0;
    struct Veiculo temp;
    while (fread(&temp, sizeof(struct Veiculo), 1, file) == 1) {
        if (temp.ano == 2014) {
            (*numVeiculos)++;
        }
    }
    
    // Aloca memória para o array dinâmico
    struct Veiculo* veiculos2014 = (struct Veiculo*)malloc(*numVeiculos * sizeof(struct Veiculo));
    if (veiculos2014 == NULL) {
        printf("Erro ao alocar memória.\n");
        fclose(file);
        return NULL;
    }
    
    // Volta para o início do arquivo
    rewind(file);
    
    // Lê os registros dos veículos do ano de 2014
    int i = 0;
    while (fread(&temp, sizeof(struct Veiculo), 1, file) == 1) {
        if (temp.ano == 2014) {
            veiculos2014[i] = temp;
            i++;
        }
    }
    
    fclose(file);
    
    return veiculos2014;
}

// Função para buscar um veículo pelo número no arquivo
struct Veiculo buscarVeiculoPorNumero(const char* filename, int numero) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de veículos.\n");
        exit(1);
    }
    
    struct Veiculo temp;
    while (fread(&temp, sizeof(struct Veiculo), 1, file) == 1) {
        if (temp.numero == numero) {
            fclose(file);
            return temp;
        }
    }
    
    fclose(file);
    
    // Se o veículo não for encontrado, retorna um veículo com número -1
    struct Veiculo notFound = {-1, "", "", 0.0, 0};
    return notFound;
}

int main() {
    // Exemplo de uso das funções
    
    // a) Criar novos veículos
    struct Veiculo novoVeiculo1 = {1234, "Fiat Uno", "Branco", 25000.0, 2014};
    struct Veiculo novoVeiculo2 = {5678, "Volkswagen Gol", "Prata", 30000.0, 2014};
    struct Veiculo novoVeiculo3 = {91011, "Ford Fiesta", "Preto", 28000.0, 2016};
    struct Veiculo novoVeiculo4 = {121314, "Chevrolet Onix", "Vermelho", 35000.0, 2015};
    
    // b) Adicionar os novos veículos ao arquivo
    adicionarVeiculo(novoVeiculo1, "veiculos.dat");
    adicionarVeiculo(novoVeiculo2, "veiculos.dat");
    adicionarVeiculo(novoVeiculo3, "veiculos.dat");
    adicionarVeiculo(novoVeiculo4, "veiculos.dat");
    
    // c) Ler os veículos do ano de 2014
    int numVeiculos2014;
    struct Veiculo* veiculos2014 = getVeiculos2014("veiculos.dat", &numVeiculos2014);
    if (veiculos2014 != NULL) {
        printf("Veículos do ano de 2014:\n");
        for (int i = 0; i < numVeiculos2014; i++) {
            printf("Número: %d, Modelo: %s, Cor: %s, Preço: %.2f, Ano: %d\n",
                veiculos2014[i].numero, veiculos2014[i].modelo, veiculos2014[i].cor,
                veiculos2014[i].preco, veiculos2014[i].ano);
        }
        free(veiculos2014); // Liberar a memória alocada para o array de veículos
    } else {
        printf("Nenhum veículo do ano de 2014 encontrado.\n");
    }
    
    // d) Buscar um veículo pelo número
    int numeroBusca = 1234;
    struct Veiculo encontrado = buscarVeiculoPorNumero("veiculos.dat", numeroBusca);
    if (encontrado.numero != -1) {
        printf("Veículo encontrado:\nNúmero: %d, Modelo: %s, Cor: %s, Preço: %.2f, Ano: %d\n",
            encontrado.numero, encontrado.modelo, encontrado.cor, encontrado.preco, encontrado.ano);
    } else {
        printf("Veículo com número %d não encontrado.\n", numeroBusca);
    }
    
    return 0;
}
