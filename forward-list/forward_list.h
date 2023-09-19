
#ifndef _FORWARD_forward_list_H_
#define _FORWARD_forward_list_H_

#include "node.h"

typedef struct
{
    Node *head;
    int size;
} ForwardList;

//alloca nova lista
ForwardList *forward_list_construct();

//retorna tamanho da lista
int forward_list_size(ForwardList *l);

//adiciona novo nó no início da lista
void forward_list_push_front(ForwardList *l, data_type data);

//imprime lista
void forward_list_print(ForwardList *l, void (*print_fn)(data_type));

//retorna o conteúdo do nó que está no índice solicitado
data_type forward_list_get(ForwardList *l, int i);

//remove o primeiro nó da lista e retorna o valor do nó removido
data_type forward_list_pop_front(ForwardList *l);

//retorna lista invertida
ForwardList *forward_list_reverse(ForwardList *l);

/**
 * @brief Removes all nodes from the linked list.
 * Removes all nodes from the linked list and frees the memory allocated for them.
 * @param l
 * Pointer to the linked list.
 * @note
 * The caller is responsible for freeing the memory allocated for the data stored in the nodes.
 */
void forward_list_clear(ForwardList *l);

//remove da listas os nós que tem o valor indicado 
void forward_list_remove(ForwardList *l, data_type val);

/**
 * @brief Removes all duplicate values from the linked list.
 * Removes all duplicate values from the linked list and frees the memory allocated for them.
 * @param l
 * Pointer to the linked list.
 * @note
 * The linked list must be sorted.
 */
void forward_list_unique(ForwardList *l);

/**
 * @brief Adds all nodes from the given list to the end of the linked list.
 * @param l
 * Pointer to the linked list.
 * @param m
 * Pointer to the linked list to be added to the end of the linked list.
 */
void forward_list_cat(ForwardList *l, ForwardList *m);

/**
 * @brief Sorts the linked list.
 * Sorts the linked list.
 * @param l
 * Pointer to the linked list.
 */
void forward_list_sort(ForwardList *l);

//free na lista e em todos os seus nós
void forward_list_destroy(ForwardList *l);

#endif