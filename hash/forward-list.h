#ifndef FLIST_H
#define FLIST_H

#include "node.h"

typedef struct ForwardList ForwardList;

ForwardList *forward_list_construct();
int forward_list_size(ForwardList *l);
void forward_list_push_front(ForwardList *l, data_type data);
void forward_list_print(ForwardList *l, void (*print_fn)(data_type));
data_type forward_list_get(ForwardList *l, int i);
data_type forward_list_pop_front(ForwardList *l);
data_type forward_list_remove(ForwardList * l, int idx);
int forward_list_find(ForwardList *l, void * val, int(*eq)(void *, data_type, void* dados_extras), void* dados_extras);

void forward_list_destroy(ForwardList *l, void(*data_destroy)(data_type));
void forward_list_clear(ForwardList *l);
void forward_list_sort(ForwardList *l, int(*cmp)(data_type, data_type));

#endif