#include "list.h"
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

//MAIN UTILIZADA APENAS PARA TESTES DA TREE.H E LIST.H
int main() {
    char file[256];
    int tamLista = 0;
    scanf("%s", file);

    FILE *arquivo = fopen(file, "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return -1;
    }

    // Correção: Passando tamLista diretamente, já que listFreq espera um int *
    node_t *lista = listFreq(arquivo, &tamLista);

    montarArvore(&lista, &tamLista);

    //print_filhos(lista);

    int prof = profundidade(lista) - 1;
    
    printf("\n%d", prof);
    
    if (lista != NULL) {
        printf("\n#####%d", lista->freq);
    } else {
        printf("Lista vazia.");
    }

    fclose(arquivo);
    return 0;
}