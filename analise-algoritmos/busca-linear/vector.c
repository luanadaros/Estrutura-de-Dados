#include <stdlib.h>
#include <stdio.h>
#include "vector.h"
#define VECTOR_INIT_SIZE 10

Vector *vector_construct(){
    Vector * v = (Vector *)calloc(1, sizeof(Vector));

    v->data = (data_type *)calloc(VECTOR_INIT_SIZE, sizeof(data_type));
    v->allocated = VECTOR_INIT_SIZE;
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

void vector_swap(Vector *v, int i, int j){
    data_type aux1, aux2;

    aux1 = v->data[i];
    aux2 = v->data[j];

    v->data[i] = aux2;
    v->data[j] = aux1;
}

void vector_sort(Vector *v){
    int troca = 0;

    for(int i = 0; i < v->size - 1; i++){
        for(int j = 0; j < v->size - 1 - i; j++){
            if(v->data[j] > v->data[j+1]){
                vector_swap(v, j, j+1);
                troca++;
            }
        }
        if(troca == 0){
            break;
        }

        troca = 0;
    }
}

int vector_binary_search(Vector *v, data_type val){
    int min = 0, max = v->size - 1;
    int central;

    vector_sort(v);

    while(min <= max){
        central = min + (max - min)/2;

        if(v->data[central] > val){
            max = central - 1;
        }
        else if(v->data[central] < val){
            min = central + 1;
        }
        else{
            return central;
        }
    }

    return -1;
}

void vector_reverse(Vector *v){
    int j = v->size;

    for(int i = 0; i < j - i - 1; i++){
        vector_swap(v, i, j - i - 1);
    }
}