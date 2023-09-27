#ifndef FLIST_H
#define FLIST_H

#include "node.h"

typedef struct {
    int size;
    Node * head;
} ForwardList;

ForwardList *forward_list_construct();
int forward_list_size(ForwardList *l);
void forward_list_push_front(ForwardList *l, data_type data);
void forward_list_print(ForwardList *l, void (*print_fn)(data_type));

void forward_list_destroy(ForwardList *l);

#endif