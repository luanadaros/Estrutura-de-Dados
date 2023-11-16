#include "graph.h"

#include <stdlib.h>
#include <stdio.h>

Graph * graph_construct(int n_corners){
    Graph * g = (Graph *)calloc(1, sizeof(Graph));
    g->n_corners = n_corners;
    g->graph = (int **)calloc(n_corners, sizeof(int *));

    for(int i = 0; i < n_corners; i++){
        g->graph[i] = (int *)calloc(n_corners, sizeof(int));
    }

    return g;
}


void graph_read(Graph * graph){
    int next_corner, cost;
    char c = '\0';

    for(int i = 0; i < graph->n_corners; i++){
        while(c != '\n'){
            scanf("%d %d", &next_corner, &cost);
            scanf("%c", &c);

            graph->graph[i][next_corner] = cost;
        }

        c = '\0';
    }
}


void graph_destroy(Graph * graph){
    for(int i = 0; i < graph->n_corners; i++){
        free(graph->graph[i]);
    }

    free(graph->graph);
    free(graph);
}

//printa o grafo para debug
void graph_print(Graph * graph){
    for(int i = 0; i < graph->n_corners; i++){
        for(int j = 0; j < graph->n_corners; j++){
            printf("%d ", graph->graph[i][j]);
        }

        printf("\n");
    }
}