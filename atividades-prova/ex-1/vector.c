#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

Vector *vector_construct(int size){
    Vector * v = (Vector *)calloc(1, sizeof(Vector));

    v->data = (data_type *)calloc(size, sizeof(data_type));
    v->allocated = size;
    v->size = 0;

    return v;
}

void vector_destroy(Vector *v, void(*data_destroy)(data_type), int size){
    for(int i = 0; i < size; i++){
        if(v->data[i] != NULL){
            data_destroy(v->data[i]);
        }
    }
    free(v->data);
    free(v);
}

void vector_push(Vector *v, int end, data_type value){
    v->data[end] = value;
    v->size++;
}

data_type vector_pop(Vector *v, int start){
    return v->data[start];
}