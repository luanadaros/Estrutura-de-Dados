#include "heap.h"

#include <stdlib.h>
#include <stdio.h>


#define INIT_SIZE 100


typedef struct{
    void * data;
    double priority;
} HeapNode;


struct Heap{
    HeapNode * nodes;
    int size;
    int capacity;
};


Heap * heap_construct()
{
    Heap * h = (Heap *)calloc(1, sizeof(Heap));
    h->nodes = (HeapNode *)calloc(INIT_SIZE, sizeof(HeapNode));
    h->size = 0;
    h->capacity = INIT_SIZE;


    return h;
}


void * heap_destroy(Heap * heap){
    free(heap); 
}


void swap_nodes(HeapNode * h1, HeapNode * h2){
    HeapNode * temp;
    temp = h1;
    h1 = h2;
    h2 = temp;
}


void heapify_up(Heap *heap, int idx){
    int parent = (idx - 1) / 2;

    if((parent >= 0) && (heap->nodes[parent].priority > heap->nodes[idx].priority)){
        swap_nodes(&heap->nodes[parent], &heap->nodes[idx]);

        heapify_up(heap, parent);
    }
}


void heapify_down(Heap * heap, int idx){
    int left_child = 2 * idx + 1;
    int right_child = 2 * idx + 2;
    int smallest = idx;

    if (left_child < heap->size && heap->nodes[left_child].priority < heap->nodes[smallest].priority) {
        smallest = left_child;
    }

    if (right_child < heap->size && heap->nodes[right_child].priority < heap->nodes[smallest].priority) {
        smallest = right_child;
    }

    if (smallest != idx) {
        swap_nodes(&heap->nodes[smallest], &heap->nodes[idx]);
        heapify_down(heap, smallest);
    }
}


void heap_push(Heap *heap, void *data, double priority){
    if(heap->size >= heap->capacity){
        heap->capacity *= 2;
        heap->nodes = (HeapNode *)realloc(heap->nodes, heap->capacity * sizeof(HeapNode));
    }

    heap->nodes[heap->size].data = data;
    heap->nodes[heap->size].priority = priority;
    heap->size++;

    heapify_up(heap, heap->size - 1);
} 


void * heap_pop(Heap *heap){
    if(heap->size == 0){
        exit(printf("Heap is empty\n"));
    }

    void * data = heap->nodes[0].data;
    heap->nodes[0] = heap->nodes[heap->size - 1];
    heap->size--;

    heapify_down(heap, 0);

    return data;
} 


void heap_sort(void *array, int array_size, int item_size, double (*key_fn)(void *)){
    Heap * heap = heap_construct();

    for(int i = 0; i < array_size; i++){
        heap_push(heap, array + (i * item_size), key_fn(array + i * item_size));
    }

    for(int i = 0; i < array_size; i++){
        //array[i] = heap_pop(heap);
    }

    heap_destroy(heap);

}

int heap_empty(Heap *heap){
    if(heap->size == 0){
        return 1;
    }
    return 0;
} 

void *heap_min(Heap *heap){
    if(heap->size == 0){
        exit(printf("Heap is empty\n"));
    }

    return heap->nodes[0].data;
} 

double heap_min_priority(Heap *heap){
    if(heap->size == 0){
        exit(printf("Heap is empty\n"));
    }

    return heap->nodes[0].priority;
}