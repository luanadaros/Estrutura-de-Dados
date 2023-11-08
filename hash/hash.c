#include "hash.h"

#include <stdlib.h>
#include <stdio.h>

/* 
define o tipo HashFunction como um ponteiro de função que recebe como entrada a tabela hash (para que o número de buckets possa ser usado para calcular o hash) e a chave do tipo void* e gera como saída um inteiro.
*/
typedef int (*HashFunction)(HashTable *h, void *);

/* 
define o tipo CmpFunction como um ponteiro de função que recebe como entrada dois void* e gera como saída um inteiro com a mesma semântica da strcmp.
*/
typedef int (*CmpFunction)(void *k1, void *k2);

/*
A estrutura da hash terá um vetor de ForwardLists, o tamanho do vetor, e as funções de hash e de comparação de chaves. Por fim, é armazenado o número de elementos atualmente na tabela hash.
*/
struct HashTable
{
    ForwardList **buckets;
    HashFunction hash_fn;
    CmpFunction cmp_fn;
    int table_size;
    int n_elements;
};

HashTable *hash_table_construct(int table_size, HashFunction hash_fn, CmpFunction cmp_fn){
    HashTable * h = (HashTable *)malloc(sizeof(HashTable));
    h->table_size = table_size;
    h->hash_fn = hash_fn;
    h->cmp_fn = cmp_fn;
    h->n_elements = 0;

    h->buckets = calloc(table_size, sizeof(ForwardList *));

    return h;
}

void hash_table_set(HashTable *h, void *key, void *val){
    int key_val = h->hash_fn(h, key);
    key_val = key_val % h->table_size;
    HashTableItem * h_item;
    h_item->key = key;
    h_item->val = val;

    if(h->buckets[key_val]){
        int idx = forward_list_find(h->buckets[key_val], h_item, h->cmp_fn);
        HashTableItem * temp = forward_list_get(h->buckets[key_val], idx);
        temp->key = h_item->key;
        temp->val = h_item->val;
    }
    else {
        h->buckets[key_val] = forward_list_construct();
        forward_list_push_front(h->buckets[key_val], h_item);
    }
}

void *hash_table_get(HashTable *h, void *key);

void *hash_table_pop(HashTable *h, void *key);

int hash_table_size(HashTable *h);

void hash_table_destroy(HashTable *h);