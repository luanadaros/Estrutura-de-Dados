#include "forward-list.h"

#include <stdlib.h>
#include <stdio.h>

ForwardList *forward_list_construct(){
    ForwardList * l = (ForwardList*)calloc(1, sizeof(ForwardList));

    return l;   
}

int forward_list_size(ForwardList *l){
    return l->size;
}

void forward_list_push_front(ForwardList *l, data_type data){
    l->head = node_construct(data, l->head);
    l->size++;
}

void forward_list_print(ForwardList *l, void (*print_fn)(data_type)){
    Node * node_it = l->head;
    Node * next;

    printf("[");

    while(node_it != NULL){
        next = node_next(node_it);
        print_fn(node_it->value);
        node_it = next;
        if(next != NULL){
            printf(", ");
        }
    }

    printf("]\n");
}

void forward_list_destroy(ForwardList *l){
    Node * node_it= l->head;
    Node * next;

    while(node_it != NULL){
        next = node_next(node_it);
        node_destroy(node_it);
        node_it = next;
    }

    free(l);
}

data_type forward_list_get(ForwardList *l, int i){
    Node * node_it = l->head;
    int aux = 0;

    while(node_it != NULL && aux < i){
        node_it = node_next(node_it);
        aux++;
    }

    return node_value(node_it);
}

data_type forward_list_pop_front(ForwardList *l){
    data_type removed = 0;
    Node * new_head;

    if(l->head != NULL){
        removed = node_value(l->head);
        new_head = node_next(l->head);

        node_destroy(l->head);

        l->head = new_head;
        l->size--;
    }
    
    return removed;
}

int forward_list_find(ForwardList *l, void * val, int(*eq)(void *, data_type)){
    Node * node_it = l->head, * next;
    int i = 0;

    while(node_it != NULL){
        next = node_it->next;
        if(eq(val, node_it->value)){
            return i;
        }
        i++;
    }

    return -1;
}