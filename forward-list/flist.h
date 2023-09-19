#ifndef FLIST_H
#define FLIST_H

typedef int data_type;
typedef struct node Node;
typedef struct flist Flist;


struct node {
    data_type value;
    Node * next;
};

struct flist {
    Node * head;
    int size;
};

Node * node_construct(data_type value, Node *next);
void node_destroy(Node* node);

Flist * flist_construct();
void flist_push_front(Flist *flist, data_type value);
void flist_destroy(Flist * flist);

#endif