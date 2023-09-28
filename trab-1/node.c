#include "node.h"

#include <stdlib.h>

Node *node_construct(data_type value, Node *next){
    Node *n = (Node *)malloc(sizeof(Node));
    n->next = next;
    n->value = value;

    return n;
}

data_type node_value(Node *n){
    return n->value;
}

Node *node_next(Node *n){
    return n->next;
}

void node_destroy(Node *n){
    free(n);
}