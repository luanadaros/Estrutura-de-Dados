#include <stdio.h>
#include <stdlib.h>

#include "hash.h"

int hash_function_string(HashTable * h, void * key){
    int h, a = 31415, b = 27183;
    char * str = key;
    int size = hash_table_size(h);

    for(h = 0; *str != '\0'; str++, a = a*b % (size - 1)){
        h = (a*h + *str) % size;
    }

    return h;
}

int cmp_key(void * k1, void * k2){
    char * c1 = k1;
    char * c2 = k2;

    return strcmp(c1, c2);
}
