#include "path.h"

#include <stdlib.h>
#include <stdio.h>

Path * path_construct(int size){
    Path * path = (Path *)calloc(1, sizeof(Path));
    path->nodes = (PathNodes **)calloc(size, sizeof(PathNodes *));
    path->size = 0;

    return path;
}

void path_destroy(Path *path){
    for(int i = 0; i < path->size; i++){
        free(path->nodes[i]);
    }
    free(path->nodes);
    free(path);
}

PathNodes * pathnode_read(int id, int parent, int cost, int cost_to_origin){
    PathNodes * node = (PathNodes *)calloc(1, sizeof(PathNodes));
    node->id = id;
    node->parent = parent;
    node->cost = cost;
    node->cost_to_origin = cost_to_origin;

    return node;
}

void path_print(Path *path){
    for(int i = 0; i < path->size; i++){
        printf("%d: %d %d\n", path->nodes[i]->id, path->nodes[i]->parent, path->nodes[i]->cost_to_origin);
    }
}


void path_push(Path * path, PathNodes * node){
    path->nodes[path->size] = node;
    path->size++;
}