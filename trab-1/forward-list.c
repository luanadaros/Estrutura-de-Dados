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

    //printf("[");

    while(node_it != NULL){
        next = node_next(node_it);
        print_fn(node_it->value);
        node_it = next;
    }

    //printf("]\n");
}

void forward_list_destroy(ForwardList *l, void(*data_destroy)(data_type)){
    Node * node_it= l->head;
    Node * next;
    data_type aux;

    while(node_it != NULL){
        next = node_next(node_it);
        aux = node_it->value;
        data_destroy(aux);
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
    Node * node_it = l->head;
    Node * next;
    int i = 0;

    while(node_it != NULL){
        next = node_it->next;
        if(eq(val, node_it->value)){
            return i;
        }
        i++;
        node_it = next;
    }

    return -1;
}

void forward_list_clear(ForwardList *l){
    Node * node_it= l->head;
    Node * next;

    while(node_it != NULL){
        next = node_next(node_it);
        node_destroy(node_it);
        node_it = next;
    }

    l->size = 0;
    l->head = NULL;
}

void forward_list_sort(ForwardList *l, int(*cmp)(void *, data_type)){
    Node * node_it = l->head;
    Node * next;
    int size_aux1 = l->size, size_aux2 = 1;
    data_type value_aux;
    
    while(size_aux1 > 1){
        while(size_aux2 < size_aux1 ){
            next = node_next(node_it);

            if(cmp(node_value(node_it), node_value(next)) > 0){
                value_aux = node_value(node_it);
                node_new_value(node_it, node_value(next));
                node_new_value(next, value_aux);
            }
            node_it = next;
            size_aux2++;
        }

        node_it = l->head;
        size_aux2 = 0;
        size_aux1--;
    }
}
