#include "heap.h"
#include "path.h"

#include <stdlib.h>
#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);
    scanf("%*c");

    int * visited = calloc(n, sizeof(int));
    Heap * not_visited = heap_construct();
    Path * path = calloc(n, sizeof(Path));


    heap_destroy(not_visited);
    free(visited);
    free(path);

    return 0;
}