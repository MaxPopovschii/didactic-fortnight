#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 5

typedef struct AdjNode {
    int dest;
    struct AdjNode *next;
} AdjNode;

typedef struct {
    AdjNode *head;
} List;

void add_edge(List graph[], int src, int dest) {
    AdjNode *node = malloc(sizeof(AdjNode));
    node->dest = dest;
    node->next = graph[src].head;
    graph[src].head = node;

    node = malloc(sizeof(AdjNode));
    node->dest = src;
    node->next = graph[dest].head;
    graph[dest].head = node;
}

void print_graph(List graph[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        AdjNode *curr = graph[i].head;
        while (curr) {
            printf("%d ", curr->dest);
            curr = curr->next;
        }
        printf("\n");
    }
}

int main() {
    List graph[MAX_NODES] = {0};
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 4);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    print_graph(graph, MAX_NODES);
    return 0;
}