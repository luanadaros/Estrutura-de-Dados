#include "list.h"
#include <stdlib.h>

List *list_construct(){
    List *l = (List*)malloc(sizeof(List));
    l->head = NULL;
    l->last = NULL;
    l->size = 0;

    return l;
}

int list_size(List *l){
    return l->size;
}

void list_push_front(List *l, data_type data){
    Node * new_node = node_construct(data, NULL, l->head);

    if(l->head == NULL){
        l->head = new_node;
        l->last = new_node;
    }
    else {
        l->head->prev = new_node;
        l->head = new_node;
    }

    l->size++;
}

void list_push_back(List *l, data_type data){
    Node * new_node = node_construct(data, l->last, NULL);

    if(l->last == NULL){
        l->last = new_node;
        l->head = new_node;
    }
    else {
        l->last->next = new_node;
        l->last = new_node;
    }

    l->size++;
}

void list_print(List *l, void (*print_fn)(data_type)){
    Node * node_it = l->head;
    Node * next;

    //printf("Size: %d\n", l->size);

    //printf("Lista: [");

    while(node_it != NULL){
        next = node_next(node_it);
        print_fn(node_value(node_it));
        node_it = next;
    }

    //printf("]\n");
}

data_type list_pop_front(List *l){
    Node * aux;
    data_type data;

    if(l->head == NULL){
        exit(printf("Erro! A lista esta vazia.\n"));
    }

    aux = l->head;
    data = aux->value;
    l->head = l->head->next;

    if(l->head != NULL){
        l->head->prev = NULL;
    }

    node_destroy(aux);
    l->size --;

    if(l->size <= 1){
        l->last = l->head;
    }

    return data;
}

data_type list_pop_back(List * l){
    Node * aux;
    data_type data;

    if(l->last == NULL){
        exit(printf("Erro! A lista esta vazia.\n"));
    }

    aux = l->last;
    data = aux->value;
    l->last = l->last->prev;

    if(l->last != NULL){
        l->last->next = NULL;
    }

    node_destroy(aux);
    l->size--;

    if(l->size <= 1){
        l->head = l->last;
    }

    return data;
}

void list_destroy(List *l, void(*data_destroy)(data_type)){
    Node * node_it, * next;
    data_type data;

    node_it = l->head;

    while(node_it != NULL){
        next = node_it->next;
        data = node_it->value;
        data_destroy(data);
        node_destroy(node_it);
        node_it = next;
    }

    free(l);
}