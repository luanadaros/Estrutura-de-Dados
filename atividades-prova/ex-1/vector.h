
#ifndef _DATA_STRUCTURES_VECTOR_H_
#define _DATA_STRUCTURES_VECTOR_H_

typedef int data_type;

typedef struct
{
    data_type *data;
    int size;
    int allocated;
} Vector;

// Aloca espaço para um elemento do tipo vector e inicializa os seus atributos.
Vector *vector_construct(int size); 

// Libera o espaço reservado para o vector.
void vector_destroy(Vector *v, void(*data_destroy)(data_type), int size); 

void vector_push(Vector *v, int end, data_type value);

data_type vector_pop(Vector *v, int start);

#endif