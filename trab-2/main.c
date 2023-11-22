#include "heap.h"
#include "graph.h"
#include "path.h"
#include "djikstra.h"

#include <stdlib.h>
#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    Path * path;
    Graph * graph = graph_construct(n);

    graph_read(graph);
    path = djikstra_solve(graph);
    path_print(path);

    graph_destroy(graph);
    path_destroy(path);
    return 0;
}