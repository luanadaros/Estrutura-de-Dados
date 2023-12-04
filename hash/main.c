#include <stdio.h>
#include <stdlib.h>

#include "hash.h"

int hash_function_string(HashTable * h, void * key){
    char * string = key;
    int k = 0, a = 127;
    int m = hash_table_size(h);

    for(; *string != '\0'; string++)
        k = (a * k + *string) % m;

    return k;    
}

int cmp_key(void * k1, void * k2){
    char * c1 = k1;
    char * c2 = k2;

    return strcmp(c1, c2);
}

