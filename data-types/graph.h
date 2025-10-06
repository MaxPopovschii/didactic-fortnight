#ifndef GRAPH_H
#define GRAPH_H

#define GRAPH_MAX_VERTICES 32

typedef struct {
    int adj[GRAPH_MAX_VERTICES][GRAPH_MAX_VERTICES];
    int num_vertices;
} Graph;

void graph_init(Graph *g, int n);
void graph_add_edge(Graph *g, int u, int v);
int  graph_has_edge(const Graph *g, int u, int v);

#endif // GRAPH_H
