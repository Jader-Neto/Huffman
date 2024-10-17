#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definição da estrutura do nó
typedef struct node {
    char byte; // Caractere do arquivo que será compactado/descompactado
    int freq; // A frequência que o caractere aparece no arquivo
    struct node *filhoE; // Nó filho esquerdo
    struct node *filhoD; // Nó filho direito
    struct node *prox; // Próximo nó na lista encadeada
} node_t;

// Funções que serão implementadas no arquivo .c
node_t* criar_List();
void *ponteiroparaVoid(unsigned char byte);
node_t *removeCabeca(node_t **head, int *tamLista);
node_t *inserir_ord(node_t **head, int freq, char byte, int *tamLista);
void exib_List(node_t* head);
node_t* listFreq(FILE *arq, int *tamLista);

#endif // LIST_H
