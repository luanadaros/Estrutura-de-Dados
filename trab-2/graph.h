#ifndef GRAPH_H
#define GRAPH_H 

typedef struct{
    int n_corners;
    int ** graph;
} Graph;

Graph * graph_construct(int n_corners);
void graph_read(Graph * graph);
void graph_destroy(Graph * graph);
void graph_print(Graph * graph);

#endif