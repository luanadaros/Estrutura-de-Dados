#include "deque.h"

struct deque{
    data_type data[MAX_SIZE];
    int start;
    int end;
    int size;
};

Deque * deque_construct(){
    Deque * d = (Deque *)malloc(sizeof(Deque));
    d->start = 0;
    d->end = 0;
    d->size = 0;
}

void deque_destroy(Deque *d){
    free(d);
}

void deque_push_front(Deque * d, data_type data){
    int next_idx = (MAX_SIZE + d->start - 1) % MAX_SIZE;

    if(d->size == MAX_SIZE){
        exit(printf("Erro! O deque nao possui mais espaco.\n"));
    }

    d->data[next_idx] = data; 
    d->start = next_idx;
    d->size++;
}

void deque_push_back(Deque *d, data_type data){
    int next_idx = (d->end)%MAX_SIZE;

    if(d->size == MAX_SIZE){
        exit(printf("Erro! O deque nao possui mais espaco.\n"));
    }

    d->data[next_idx] = data;
    d->end = next_idx + 1;
    d->size++;
}

data_type deque_pop_front(Deque *d){
    int next_idx = (d->start + 1)%MAX_SIZE;
    data_type removed = d->data[d->start];

    d->start = next_idx;
    d->size--;

    return removed;
}

data_type deque_pop_back(Deque *d){
    int next_idx = (MAX_SIZE + d->end - 1) % MAX_SIZE;
    data_type removed = d->data[next_idx];

    d->end = next_idx;
    d->size--;

    return removed;
}
