#ifndef PATH_H
#define PATH_H

typedef struct {
    int cost; //custo para a origem
    int parent; //indice do antecessor
} Path;

Path  * paths_construct(int size);
void paths_print(Path *path, int size);
void paths_destroy(Path *path, int size);

#endif