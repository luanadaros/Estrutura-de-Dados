#include "queue.h"

#include <stdlib.h>
#include <stdio.h>

struct queue {
    List * list;
    int size;
};

Queue * queue_construct(){
    Queue * q = (Queue *)malloc(sizeof(Queue));
    q->list = list_construct();
}

void queue_destroy(Queue * q, void(*data_destroy)(data_type)){
    list_destroy(q->list, data_destroy);
    free(q);
}

void queue_push_back(Queue * q, data_type value){
    list_push_back(q->list, value);
    q->size = list_size(q->list);
}

data_type queue_pop_front(Queue * q){
    data_type data = list_pop_front(q->list);
    q->size = list_size(q->list);
}
