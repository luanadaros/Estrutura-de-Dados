#include "djikstra.h"

#include <stdlib.h>
#include <stdio.h>


Path * djikstra_solve(Graph * graph){
    int * visited = (int *)calloc(graph->n_corners, sizeof(int));
    Heap * not_visited = heap_construct(graph->n_corners);
    Path * path = path_construct(graph->n_corners);


    int current_corner = 0, cost = 0;
    int n_corners_visited = 0;

    while(n_corners_visited < graph->n_corners){
        for(int i = 1; i < graph->n_corners; i++){
            if(graph->graph[current_corner][i] != 0){

                PathNodes * node = pathnode_read(i, current_corner, graph->graph[current_corner][i], cost + graph->graph[current_corner][i]);

                heap_push(not_visited, node, node->cost_to_origin);
            }
        }

        visited[current_corner] = 1;
        PathNodes * next_node = heap_pop(not_visited);

        if(next_node == NULL){
            break;
        }

        while(visited[next_node->id] == 1 && !heap_empty(not_visited)){
            free((PathNodes *)next_node);
            next_node = heap_pop(not_visited);
        }

        path_push(path, next_node);
        cost = next_node->cost_to_origin;

        current_corner = next_node->id;
        n_corners_visited++;
    }


    heap_destroy(not_visited);
    free(visited);
    return path;
} 