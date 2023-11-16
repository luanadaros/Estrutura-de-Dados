#include "djikstra.h"

#include <stdlib.h>
#include <stdio.h>

Path * djikstra_solve(Graph * graph){
    int * visited = (int *)calloc(graph->n_corners, sizeof(int));
    Heap * not_visited = heap_construct(graph->n_corners);
    Path * path = path_construct(graph->n_corners);

    visited[0] = 1; //define o nó origem como ja visitado

    int current_corner = 0, next_corner = 0, cost = 0;

    

    heap_destroy(not_visited);
    free(visited);
    return path;
} 