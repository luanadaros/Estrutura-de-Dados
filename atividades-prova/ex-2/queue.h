#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"
typedef struct queue Queue;

Queue * queue_construct();
void queue_destroy(Queue *, void(*data_destroy)(data_type));
void queue_push_back(Queue *, data_type);
data_type queue_pop_front(Queue *);

#endif