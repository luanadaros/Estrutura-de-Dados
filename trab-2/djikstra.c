#include "djikstra.h"

#include <stdlib.h>
#include <stdio.h>


Path * djikstra_solve(Graph * graph){
    int * visited = (int *)calloc(graph->n_corners, sizeof(int));
    Heap * not_visited = heap_construct(graph->n_corners);
    Path * path = path_construct(graph->n_corners);


    int current_corner = 0, cost = 0;
    int n_corners_visited = 0;

    //loop enquanto nao forem visitados todos os vértices
    while(n_corners_visited < graph->n_corners){

        //analisa a partir do nó 1 para que não registre caminhos que voltariam para a origem
        for(int i = 1; i < graph->n_corners; i++){

            //se existir um caminho entre o current_corner(vertice atual) e o vertice i, ele entra na condição
            if(graph->graph[current_corner][i] != 0){

                //leitura do novo nó e seu caminho
                PathNodes * node = pathnode_read(i, current_corner, graph->graph[current_corner][i], cost + graph->graph[current_corner][i]);

                //registra nó na heap
                heap_push(not_visited, node, node->cost_to_origin);
            }
        }

        //marca o vertice atual como visitado
        visited[current_corner] = 1;
        PathNodes * next_node = heap_pop(not_visited);

        if(next_node == NULL){
            break;
        }

        //enquanto o próximo nó já tiver sido visitado e a heap não estiver vazia, ele é descartado
        while(visited[next_node->id] == 1 && !heap_empty(not_visited)){
            free((PathNodes *)next_node);
            next_node = heap_pop(not_visited);
        }

        //adiciona o menor caminho do nó para a lista de paths
        path_push(path, next_node);
        cost = next_node->cost_to_origin; //usado para calcular o custo para a origem

        current_corner = next_node->id;
        n_corners_visited++;
    }


    heap_destroy(not_visited);
    free(visited);
    return path;
} 