#include "binary-tree.h"
#include <stdlib.h>
#include <stdio.h>

struct Node
{
    void *key;
    void *val;
    struct Node *left;
    struct Node *right;
};

typedef struct Node Node;

struct BinaryTree
{
    Node *root;
    int size;
}; 


//node functions
Node* node_construct(void * val, void * key){
    Node * n = (Node *)malloc(sizeof(Node));
    n->val = val;
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    return n;
};

Node * node_insert(Node * node, void * val, void * key, int (*cmp)(void *, void *)){
    if(node == NULL){
        return node_construct(val, key);
    }
    else if(cmp(key, node->key) < 0){
        node->left = node_insert(node->left, val, key, cmp);
    }
    else if(cmp(key, node->key) > 0){
        node->right = node_insert(node->right, val, key,  cmp);
    }
    return node;
};

Node * node_remove(Node * node, void * key, int (*cmp)(void *, void *)){
    if(node == NULL){
        return NULL;
    }
    else if(cmp(key, node->key) < 0){
        node->left = node_remove(node->left, key, cmp);
    }
    else if(cmp(key, node->key > 0)){
        node->right = node_remove(node->right, key, cmp);
    }
    else {
        if (node->left == NULL && node->right == NULL){
            free(node);
            node = NULL;
        }
        else if (node->left == NULL){
            Node * temp = node;
            node = node->right;
            free(temp);
        }
        else if (node->right == NULL){
            Node * temp = node;
            node = node->left;
            free(temp);
        }
        else {
            Node * f = node->left;
            while(f->right != NULL){
                f = f->right;
            }
            node->key = f->key;
            node->val = f->val;
            f->key = key;
            node->left = node_remove(node->left, key); 
        }
    }

    return node;
}

void node_destroy(Node * node, void (*destroy)(void *, void *)){
    if(node == NULL){
        return NULL;
    }
    node_destroy(node->left, destroy);
    node_destroy(node->right, destroy);
    destroy(node->val, node->key);
    free(node);
};


//binary tree functions
BinaryTree* binary_tree_construct(){
    BinaryTree * btree = (BinaryTree *)malloc(sizeof(BinaryTree));
    btree->root = NULL;
    btree->size = 0;
    return btree;
}

void binary_tree_destroy(BinaryTree* tree, void (*destroy)(void *, void *)){
    node_destroy(tree->root, destroy);
    free(tree);
}

void binary_tree_insert(BinaryTree* tree, void * val, void * key, int (*cmp)(void *, void *)){
        tree->root = node_insert(tree->root, val, key, cmp);
        tree->size++;
}

void * binary_tree_remove(BinaryTree* tree, void * val, int (*cmp)(void*, void*)){
    
}

void * binary_tree_search(BinaryTree* tree, void * key, int (*cmp)(void*, void*)){
    Node * node = tree->root;
    while(node != NULL){
        if(cmp(key, node->key) == 0){
            return node->val;
        }
        else if(cmp(key, node->key) < 0){
            node = node->left;
        }
        else if(cmp(key, node->key) > 0){
            node = node->right;
        }
    }

    return NULL;
}
