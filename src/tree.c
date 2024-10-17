#include "tree.h"

bool ehFolha(node_t **head){
    return (*head)->filhoE == NULL && (*head)->filhoD == NULL;
}

node_t *montarArvore(node_t **head, int *tamLista){

    node_t *FilhoE, *FilhoD, *Pai;

    while(*tamLista > 1){

        FilhoE = removeCabeca(head, tamLista);
        FilhoD = removeCabeca(head, tamLista);
        
        Pai = inserir_ord(head, FilhoE->freq + FilhoD->freq, '*', tamLista);
        Pai->filhoE = FilhoE;
        Pai->filhoD = FilhoD;
    }

    return Pai;

}

int profundidade(node_t *no) {
    if (no == NULL) {
        return 0;
    } else {
        int esq = profundidade(no->filhoE);
        int dir = profundidade(no->filhoD);

        // Retorna a maior profundidade entre os ramos esquerdo e direito
        return 1 + (esq > dir ? esq : dir);
    }
}


void print_filhos(node_t *raiz) {
    if (raiz == NULL) {
        return;
    }

    printf("No atual: %c, freq: %d\n", raiz->byte, raiz->freq);

    if (raiz->filhoE != NULL) {
        printf("Filho esquerdo: byte = %c, freq = %d\n", raiz->filhoE->byte, raiz->filhoE->freq);
    } else {
        printf("Filho esquerdo: NULL\n");
    }

    if (raiz->filhoD != NULL) {
        printf("Filho direito: byte = %c, freq = %d\n", raiz->filhoD->byte, raiz->filhoD->freq);
    } else {
        printf("Filho direito: NULL\n");
    }

    // Recursão para imprimir os filhos dos nós seguintes
    print_filhos(raiz->filhoE);
    print_filhos(raiz->filhoD);
}