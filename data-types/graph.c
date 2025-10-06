#include "graph.h"

void graph_init(Graph *g, int n) {
    g->num_vertices = n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g->adj[i][j] = 0;
}

void graph_add_edge(Graph *g, int u, int v) {
    if (u < 0 || v < 0 || u >= g->num_vertices || v >= g->num_vertices) return;
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

int graph_has_edge(const Graph *g, int u, int v) {
    if (u < 0 || v < 0 || u >= g->num_vertices || v >= g->num_vertices) return 0;
    return g->adj[u][v];
}
