#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

struct queue
{
    Vector * array;
    int start;
    int end;
    int size;
};

Queue * queue_construct(){
    Queue * q = (Queue *)malloc(sizeof(Queue));
    q->array = vector_construct(MAX_SIZE);
    int start = 0;
    int end = 0;
    int size = 0;

    return q;
}

void queue_destroy(Queue* q, void(*data_destroy)(data_type)){
    vector_destroy(q->array, data_destroy, q->size);
    free(q);
}

void queue_push(Queue * q, data_type value){
    if(q->size == MAX_SIZE){
        printf("Fila cheia! Libere espaço para continuar\n");
    }
    else{
    vector_push(q->array, q->end, value);
    q->end = (q->end + 1) % MAX_SIZE;
    q->size ++;
    }
}

data_type queue_pop(Queue * q){
    data_type removed = vector_pop(q->array, q->start);
    q->start = (q->start + 1) % MAX_SIZE;
    q->size --;
}