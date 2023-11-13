#ifndef PATH_H
#define PATH_H

typedef struct {
    int cost; //custo para o antecessor
    int predecessor; //indice do antecessor
} Path;

void paths_print(Path *path, int size);

#endif