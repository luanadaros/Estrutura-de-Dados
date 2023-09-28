#ifndef NODE_H
#define NODE_H

typedef void * data_type;

typedef struct Node
{
    data_type value;
    struct Node *next;
} Node;


Node *node_construct(data_type value, Node *next);
data_type node_value(Node *n);
Node *node_next(Node *n);
void node_destroy(Node *n);

#endif