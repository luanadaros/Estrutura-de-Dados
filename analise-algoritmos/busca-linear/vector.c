#include <stdlib.h>
#include <stdio.h>
#include "vector.h"
//#define VECTOR_INIT_SIZE 10

Vector *vector_construct(int tam){
    Vector * v = (Vector *)calloc(1, sizeof(Vector));

    v->data = (data_type *)calloc(tam, sizeof(data_type));
    v->allocated = tam;
    v->size = 0;

    return v;
}

void vector_push_back(Vector *v, data_type val){

    if(v->size == v->allocated){
        v->allocated = v->allocated * 2;
        v->data = (data_type *)realloc(v->data, v->allocated * sizeof(data_type));
    }

    v->data[v->size] = val;
    v->size++;
}

int vector_size(Vector *v){
    return v->size;
}

data_type vector_get(Vector *v, int i){

    if(i >= 0 && i < v->allocated){
        return v->data[i];
    }
    else {
        printf("Indice invalido!\n");
        exit(1);
    }
}

void vector_set(Vector *v, int i, data_type val){
    v->data[i] = val;
}

int vector_find(Vector *v, data_type val){
    for(int i = 0; i < v->size; i++){
        if(v->data[i] == val){
            return i;
        }
    }

    return -1;
}

void vector_destroy(Vector *v){
    free(v->data);
    free(v);
}

data_type vector_remove(Vector *v, int i){
    v->size = v->size - 1;
    data_type removed = v->data[i];

    for(int j = i; j < v->size; j++){
        v->data[j] = v->data[j + 1];
    }

    return removed;
} 

data_type vector_pop_front(Vector *v){
    data_type removed = vector_remove(v, 0);

    return removed;
} 

data_type vector_pop_back(Vector *v){
    data_type removed = vector_remove(v, v->size - 1);

    return removed;
}

void vector_insert(Vector *v, int i, data_type val){

    if(v->size == v->allocated){
        v->allocated = v->allocated * 2;
        v->data = (data_type *)realloc(v->data, v->allocated * sizeof(data_type));
    }
    v->size++;

    for(int j = v->size - 1; j > i; j--){
        v->data[j] = v->data[j-1];
    }

    v->data[i] = val;
} 