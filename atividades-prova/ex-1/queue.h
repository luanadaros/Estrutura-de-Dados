#ifndef QUEUE_H
#define QUEUE_H

#include "vector.h"

typedef struct queue Queue;

Queue * queue_construct();
void queue_destroy(Queue*, void(*data_destroy)(data_type));
void queue_push(Queue *, data_type);
data_type queue_pop(Queue *);

#endif