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
        next = node_it->next;
        print_fn(node_it->value);
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
        node_it = node_it->next;
        aux++;
    }

    return node_it->value;
}

data_type forward_list_pop_front(ForwardList *l){
    data_type removed = l->head->value;
    Node * new_head = l->head->next;

    node_destroy(l->head);

    l->head = new_head;
    l->size--;

    return removed;
}

ForwardList *forward_list_reverse(ForwardList *l){
    ForwardList * reversed_list = forward_list_construct();
    reversed_list->size = l->size;

    Node * node_it = l->head;
    Node * next;

    while(node_it != NULL){
        next = node_it->next;
        forward_list_push_front(reversed_list, node_it->value);
        node_it = next;
    }

    return reversed_list;
}

void forward_list_remove(ForwardList *l, data_type val){
    Node * node_it = l->head;
    Node * next, * previous = NULL;

    while(node_it != NULL){
        next = node_it->next;
        if(node_it->value == val){
            if(node_it == l->head){
                l->head = next;
            }
            if(previous != NULL){
                previous->next = node_it->next;
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
        next_m = node_it_m->next;
        forward_list_push_front(l, node_it_m->value);
        node_it_m = next_m;
    }
}


void forward_list_destroy(ForwardList *l){
    Node * node_it= l->head;
    Node * next;

    while(node_it != NULL){
        next = node_it->next;
        node_destroy(node_it);
        node_it = next;
    }

    free(l);
}
