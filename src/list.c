#include "list.h"


node_t* criar_List() { //função que cria a lista encadeada, com um único nó

    return NULL; //retorna NULL para indicar que a lista está vazia inicialmente
}

void *ponteiroparaVoid(unsigned char byte) {
    unsigned char *ponteiro = malloc(sizeof(unsigned char));
    *ponteiro = byte;
    return (void*) ponteiro;
}

// função para inserir os nós ordenados na lista encadeada, de acordo com a frequência
void inserir_ord(node_t **head, int freq, char byte) { //recebe a cabeça da lista encadeada, a frequência que aparece o caractere e o caractere
    
    node_t *novo = (node_t*) malloc(sizeof(node_t)); //cria um ponteiro do tipo nó e aloca dinamicamente na memória o espaço de um nó;
    novo->freq = freq; //atualiza a variável freq do nó nomeado novo, com o valor recebido na entrada da função de inserir
    novo->byte = *((char*)ponteiroparaVoid(byte)); //atualiza a variável byte com o caractere recebido na entrada da função
    novo->filhoE = NULL; //filho 1 aponta para NULL
    novo->filhoD = NULL; //filho 2 aponta para NULL

    node_t *atual = *head;  //criamos o ponteiro atual, apontando para a cabeça da lista, para referenciar na hora de inserir o nó
    node_t *anter = NULL;   //criamos o ponteiro anter também para referenciar, apontando para NULL

    if (*head == NULL) { //se não houver cabeça da lista
        *head = novo; //apontamos o novo nó como cabeça da lista
        novo->prox = NULL; //o ponteiro prox, do novo nó, aponta agora para nulo. Porque é o único elemento da lista.
        return; //após isso, sai da função
    }

    while (atual != NULL) {// condição para começarmos a percorrer a lista para inserção do novo nó
        if (atual->freq < novo->freq){ //se a frequência do nó atual for menor que a frequencia do novo nó, avançamos um nó(?):

            anter = atual; //o nó anterior agora aponta para o nó atual
            atual = atual->prox; //o nó atual agora aponta para o próximo
        } else { //se o nó atual tiver frequência maior ou igual ao novo nó, iremos inserir o novo nó na frente do atual

            if (anter == NULL) { //se o nó anterior for nulo

                *head = novo; //o novo nó aponta para a cabeça da lista (passa a ser a cabeça da lista)
            } else { //se o nó anterior não for nulo

                anter->prox = novo; //o ponteiro de próximo do anterior, aponta para o novo nó
            }

            novo->prox = atual; //pronto. Inserimos o novo nó, ordenado! O ponteiro próximo do novo nó agora aponta para o nó atual.
            return; //encerra o if, e volta ao inicio do looping.
        }
    }
    anter->prox = novo; //se todos os nós da lista forem maiores que o que queremos inserir(?), inserimos ele no final
    novo->prox = NULL; //o ponteiro próximo do novo nó aponta para NULL
}

void exib_List(node_t* head) { //função de printar a lista encadeada. Tem como argumento a cabeça da lista.
    node_t *atual = head; //criamos um ponteiro auxiliar que aponta para a cabeça da lista, para percorrermos a lista

    while (atual != NULL) { //enquanto existir o nó atual, o ponteiro atual percorre a lista
        printf("\n'%c' | %d", atual->byte, atual->freq); //printamos o caraacter e sua respectiva frquência do nó atual
        atual = atual->prox; //o ponteiro atual agora aponta para o seu próximo
    }
}

// função para inserir os nós ordenados na lista encadeada, de acordo com a frequência
node_t* listFreq(FILE *arq) { //recebe o nome do arquivo como argumento

    // Tabela de frequências: cada índice representa um caractere (0 a 255 do ASCII)
    char frequencias[256] = {0}; //inicializa a tabela de frequências com zeros
    unsigned char caractere; //variável para armazenar cada caractere lido

    // Contagem das frequências
    while (fread(&caractere, sizeof(unsigned char), 1, arq)) { //lê cada caractere do arquivo
        frequencias[caractere]++; //incrementa a frequência do caractere lido
    }
    fclose(arq); //fecha o arquivo após a leitura

    node_t *lista = criar_List(); //cria uma lista encadeada vazia

    // Criação da lista com base nas frequências
    for (int i = 0; i < 256; i++) { //percorre todos os caracteres possíveis
        if (frequencias[i] > 0) { //se o caractere apareceu no arquivo
            inserir_ord(&lista, frequencias[i], i); //insere o caractere e sua frequência na lista de forma ordenada
        }
    }
    //exib_List(lista);

    return lista; //retorna a cabeça da lista encadeada contendo os caracteres e suas frequências
}
