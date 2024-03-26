#!/bin/bash

# Lista de arquivos
arquivos=("L1E1" "L1E1.c" "L1E2" "L1E2.c" "L1E3" "L1E3.c" "L1E4" "L1E4.c" "L1E5" "L1E5.c")

# Função para encontrar o nome do arquivo sem extensão
get_nome_sem_extensao() {
    arquivo_com_extensao="$1"
    echo "${arquivo_com_extensao%.c}"
}

# Iterar sobre a lista de arquivos para criar os arquivos .zip
for arquivo in "${arquivos[@]}"; do
    if [[ $arquivo == *.c ]]; then
        nome_sem_extensao=$(get_nome_sem_extensao "$arquivo")
        if [[ -e $nome_sem_extensao ]]; then
            zip -r "zanoni_${nome_sem_extensao}.zip" "$nome_sem_extensao" "$arquivo"
            echo "Arquivos $nome_sem_extensao e $arquivo adicionados ao ${nome_sem_extensao}.zip"
        fi
    fi
done
