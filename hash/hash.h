#ifndef HASH_H
#define HASH_H

#include "forward-list.h"
#include "node.h"

typedef struct HashTable HashTable;

typedef int (*CmpFunction)(void *k1, void *k2);
typedef int (*HashFunction)(HashTable *h, void * key);

HashTable *hash_table_construct(int table_size, HashFunction hash_fn, CmpFunction cmp_fn);

// funcao para insercao/atualizacao de pares chave-valor em O(1). Esta função deve usar hash modular para garantir que o valor da chave será mapeado em um bucket válido da tabela hash.
void hash_table_set(HashTable *h, void *key, void *val);

// retorna o valor associado com a chave key ou NULL se ela nao existir em O(1). Esta função deve usar hash modular para garantir que o valor da chave será mapeado em um bucket válido da tabela hash.
void *hash_table_get(HashTable *h, void *key);

// remove o par chave-valor e retorna o valor ou NULL se nao existir tal chave em O(1).
void *hash_table_pop(HashTable *h, void *key);

// numero de elementos
int hash_table_size(HashTable *h);

// libera o espaco alocado para a tabela hash
void hash_table_destroy(HashTable *h);

#endif