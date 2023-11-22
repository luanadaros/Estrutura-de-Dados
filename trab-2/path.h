#ifndef PATH_H
#define PATH_H

typedef struct{
    int cost;
    int parent;
    int id;
    int cost_to_origin;
} PathNodes;

typedef struct {
    PathNodes ** nodes;
    int size;   
} Path;

Path  * path_construct(int size);
void path_print(Path *path);
void path_destroy(Path *path);
PathNodes * pathnode_read(int id, int parent, int cost, int cost_to_origin);
void path_push(Path * path, PathNodes * node);

#endif