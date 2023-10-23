
#include <stdlib.h>
#include "node.h"


Node *node_construct(data_type value, Node *next)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->value = value;
    n->next = next;
    return n;
}

data_type node_value(Node *n){
    return n->value;
}

Node *node_next(Node *n){
    return n->next;
}

void node_new_next(Node *old, Node *new){
    old->next = new->next;
};

void node_new_value(Node *n, data_type new_value){
    n->value = new_value;
}

void node_destroy(Node *n)
{
    free(n);
}