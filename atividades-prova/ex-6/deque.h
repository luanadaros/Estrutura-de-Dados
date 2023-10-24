#ifndef DEQUE_H
#define DEQUE_H

#define MAX_SIZE 10

typedef struct deque Deque;
typedef int data_type;

Deque * deque_construct();
void deque_destroy(Deque *);
void deque_push_front(Deque *, data_type);
void deque_push_back(Deque *, data_type);
data_type deque_pop_front(Deque *);
data_type deque_pop_back(Deque *);

#endif