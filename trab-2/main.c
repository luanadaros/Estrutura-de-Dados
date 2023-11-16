#include "heap.h"
#include "graph.h"
#include "path.h"
//#include "djikstra.h"

#include <stdlib.h>
#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);
    scanf("%*c");

    Path * paths = path_construct(n);
    Graph * graph = graph_construct(n);

    graph_read(graph);
    paths = djikstra_solve(graph);
    ////paths_print(path, n);

    graph_destroy(graph);
    path_destroy(paths);
    return 0;
}