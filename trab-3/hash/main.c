#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

int hash_function_string(HashTable * h, void * key){
    int k, a = 31415, b = 27183;
    char * str = key;
    int size = hash_table_size(h);

    for(k = 0; *str != '\0'; str++, a = a*b % (size - 1)){
        k = (a*k + *str) % size;
    }

    return k;
}

int cmp_key(void * k1, void * k2){
    char * c1 = k1;
    char * c2 = k2;

    return strcmp(c1, c2);
}

int main(){
    HashTable * h = hash_table_construct(701, hash_function_string, cmp_key);

    char word[20];
    int i = 0;

    while(!strcmp(word, "end")){
        scanf("%s", word);
        scanf("%*c");

        hash_table_set(h, word, i);

        i++;
    }
}