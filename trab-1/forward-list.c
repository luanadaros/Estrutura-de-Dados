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
        print_fn(node_value(node_it));
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