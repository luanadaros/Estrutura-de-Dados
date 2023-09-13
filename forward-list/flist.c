#include "flist.h"
#include <stdio.h>
#include <stdlib.h>


Node * node_construct(data_type value, Node* next){
    Node * n = (Node *)calloc(1, sizeof(Node));
    n->value = value;
    n->next = next;

    return n;
}

void node_destroy(Node* node){
    free(node);
}

Flist * flist_construct(){
    return calloc(1,sizeof(Flist));
}

void flist_push_front(Flist *flist, data_type value){
    flist->head = node_construct(value, flist->head);
    flist->size++;
}

void flist_destroy(Flist * flist){
    Node * node_it= flist->head;
    Node * next;

    while(node_it != NULL){
        next = node_it->next;
        free(node_it);
        node_it = next;
    }

    free(flist);
}
