#ifndef HEAP_H
#define HEAP_H

typedef struct Heap Heap;

Heap * heap_construct();
void heap_destroy(Heap * heap);
void heap_push(Heap *heap, void *data, double priority); 
void * heap_pop(Heap *heap);
int heap_empty(Heap *heap); 
void *heap_min(Heap *heap); 
double heap_min_priority(Heap *heap);


#endif