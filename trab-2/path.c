#include "path.h"

#include <stdlib.h>
#include <stdio.h>

Path * paths_construct(int size){
    Path * path = (Path *)calloc(size, sizeof(Path));

    return path;
}

void paths_print(Path *path, int size){
    
}

void paths_destroy(Path *path, int size){
    free(path);
}