#include "forward_list.h"
#include <stdio.h>
#include <stdlib.h>


ForwardList *forward_list_construct(){
    return calloc(1, sizeof(ForwardList));
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

ForwardList *forward_list_reverse(ForwardList *l){
    ForwardList * reversed_list = forward_list_construct();
    reversed_list->size = l->size;

    Node * node_it = l->head;
    Node * next;

    while(node_it != NULL){
        next = node_next(node_it);
        forward_list_push_front(reversed_list, node_value(node_it));
        node_it = next;
    }

    return reversed_list;
}

void forward_list_remove(ForwardList *l, data_type val){
    Node * node_it = l->head;
    Node * next, * previous = NULL;

    while(node_it != NULL){
        next = node_next(node_it);
        if(node_value(node_it) == val){
            if(node_it == l->head){
                l->head = next;
            }
            if(previous != NULL){
               node_new_next(previous, node_it);
            }

            node_destroy(node_it);
            l->size--;
        }
        else {
            previous = node_it;
        }

        node_it = next;
    }
}

void forward_list_cat(ForwardList *l, ForwardList *m){
    l->size = m->size;

    Node * node_it_m = m->head;
    Node * next_m;

    while(node_it_m != NULL){
        next_m = node_next(node_it_m);
        forward_list_push_front(l, node_value(node_it_m));
        node_it_m = next_m;
    }
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

void forward_list_sort(ForwardList *l){
    Node * node_it = l->head;
    Node * next;
    int size_aux1 = l->size, size_aux2 = 1;
    data_type value_aux;
    
    while(size_aux1 > 1){
        while(size_aux2 < size_aux1 ){
            next = node_next(node_it);

            if(node_value(node_it) > node_value(next)){
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

void forward_list_unique(ForwardList *l);


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
