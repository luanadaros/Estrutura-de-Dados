#include "hash.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct
{   
    void *key;
    void *val;
} HashTableItem;

struct HashTable
{
    ForwardList **buckets;
    HashFunction hash_fn;
    CmpFunction cmp_fn;
    int table_size;
    int n_elements;
};

HashTableItem * hash_table_item_construct(){
    HashTableItem * h = malloc(sizeof(HashTableItem));

    return h;
}

HashTable *hash_table_construct(int table_size, HashFunction hash_fn, CmpFunction cmp_fn){
    HashTable * h = (HashTable *)malloc(sizeof(HashTable));
    h->table_size = table_size;
    h->hash_fn = hash_fn;
    h->cmp_fn = cmp_fn;
    h->n_elements = 0;

    h->buckets = calloc(table_size, sizeof(ForwardList *));

    return h;
}

void cmp_node(void *node_1, void *node_2, void *hash_table)
{
    char *i1 = node_1;
    HashTableItem *i2 = node_2;
    HashTable *h = hash_table;

    return h->cmp_fn(i1, i2->key);
}

void hash_table_set(HashTable *h, void *key, void *val){
    int key_val = h->hash_fn(h, key);
    key_val = key_val % h->table_size;


    //se a flist correspondente a chave key_val ja existe
    if(h->buckets[key_val]){
        int idx = forward_list_find(h->buckets[key_val], key, cmp_node, h);

        if(idx == -1){
            HashTableItem * h_item = hash_table_item_construct();
            h_item->key = key;
            h_item->val = val;
            forward_list_push_front(h->buckets[key_val], h_item);
            h->n_elements++;
        }

        else {
            HashTableItem * temp = forward_list_get(h->buckets[key_val], idx);
            temp->key = key;
            temp->val = val;
        }
    }
    else {
        h->buckets[key_val] = forward_list_construct();
        HashTableItem * h_item = hash_table_item_construct();
        h_item->key = key;
        h_item->val = val;
        forward_list_push_front(h->buckets[key_val], h_item);
        h->n_elements++;
    }
}

void *hash_table_get(HashTable *h, void *key){
    int key_val = h->hash_fn(h, key);
    key_val = key_val % h->table_size;

    if(h->buckets[key_val]){
        int idx = forward_list_find(h->buckets[key_val], key, cmp_node, h);
        if(idx != -1){
            return forward_list_get(h->buckets[key_val], idx);
        }
    }   

    printf("Essa chave nao existe na HashTable.\n");
    return NULL;
}

void *hash_table_pop(HashTable *h, void *key){
    int key_val = h->hash_fn(h, key);
    key_val = key_val % h->table_size;

    if(h->buckets[key_val]){
        int idx = forward_list_find(h->buckets[key_val], key, cmp_node, h);
        
        if(idx != -1){
            h->n_elements--;
            return forward_list_remove(h->buckets[key_val], idx);
        }
    }   

    printf("Essa chave nao existe na HashTable.\n");
    return NULL;
}

int hash_table_size(HashTable *h){
    return h->table_size;
}

void hash_table_destroy(HashTable *h)
{
    for (int i = 0; i < h->table_size; i++)
    {
        if (h->buckets[i] != NULL)
        {
            forward_list_destroy(h->buckets[i], free);
        }
    }

    free(h->buckets);
    free(h);
}
