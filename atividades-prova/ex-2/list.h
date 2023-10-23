
#ifndef _DOUBLE_LINKED_LIST_H_
#define _DOUBLE_LINKED_LIST_H_

#include "node.h"

typedef struct
{
    Node *head;
    Node *last;
    int size;
} List;

/**
 * @brief Construct a new double linked list object
 *  Allocates memory for a new double linked list and returns a pointer to it.
 * @return List*
 * Pointer to the newly allocated double linked list.
 * @note
 * The caller is responsible for freeing the memory allocated for the double linked list using list_destroy().
 *
 */
List *list_construct();

/**
 * @brief Returns the size of the double linked list.
 *  Returns the number of nodes in the double linked list.
 * @param l
 * Pointer to the double linked list.
 * @return int
 * Number of nodes in the double linked list.
 *
 */
int list_size(List *l);

/**
 * @brief Pushes a new node to the front of the double linked list.
 *  Allocates memory for a new node and inserts it at the front of the double linked list.
 * @param l
 * Pointer to the double linked list.
 * @param data
 * Pointer to the data to be stored in the new node.
 *
 */
void list_push_front(List *l, data_type data);

/**
 * @brief Pushes a new node to the back of the double linked list.
 *
 * @param l
 * Pointer to the double linked list.
 * @param data
 * data to be stored in the new node.
 */
void list_push_back(List *l, data_type data);

/**
 * @brief Print the elements of the double linked list.
 *  Print the elements of the double linked list.
 * @param l
 * Pointer to the double linked list.
 * @param print_fn
 * Pointer to the function to print data_type values.
 *
 */
void list_print(List *l, void (*print_fn)(data_type));

/**
 * @brief Remove the first node of the double linked list and returns its data.
 * @param l
 * Pointer to the double linked list.
 * @return data_type
 * Pointer to the data stored in the first node of the double linked list that was removed.
 *
 */
data_type list_pop_front(List *l);

/**
 * @brief Remove the last node of the double linked list and returns its data.
 * @param l
 * Pointer to the double linked list.
 * @return data_type
 * Data stored in the last node of the double linked list that was removed.
 */
data_type list_pop_back(List *l);

/**
 * @brief Destroys the double linked list.
 *  Frees the memory allocated for the double linked list and all its nodes.
 * @param l
 * Pointer to the double linked list.
 *
 */
void list_destroy(List *l, void(*data_destroy)(data_type));

#endif