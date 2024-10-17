#include <list.h>

#ifndef TREE_H
#define TREE_H

bool ehFolha(node_t **head);
node_t *montarArvore(node_t **head, int *tamLista);
int profundidade(node_t *no);
void print_filhos(node_t *raiz);

#endif 