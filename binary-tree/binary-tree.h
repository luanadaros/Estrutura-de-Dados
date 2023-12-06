#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct BinaryTree BinaryTree;

BinaryTree* binary_tree_construct();
void binary_tree_destroy(BinaryTree* tree, void (*destroy)(void*, void*));
void binary_tree_insert(BinaryTree* tree, void * val, void * key, int (*cmp)(void*, void*));
void * binary_tree_remove(BinaryTree* tree, void * val, int (*cmp)(void*, void*));
void * binary_tree_search(BinaryTree* tree, void * key, int (*cmp)(void*, void*));


#endif