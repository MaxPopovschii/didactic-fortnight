#include <stdio.h>

#define N 5

int esiste_percorso(int graph[N][N], int start, int end, int visited[N]) {
    if (start == end) return 1;
    visited[start] = 1;
    for (int i = 0; i < N; i++) {
        if (graph[start][i] && !visited[i]) {
            if (esiste_percorso(graph, i, end, visited)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int graph[N][N] = {0};
    int visited[N] = {0};
    int edges, from, to;

    printf("Quanti archi vuoi inserire? ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Inserisci arco (da a): ");
        scanf("%d %d", &from, &to);
        if (from >= 0 && from < N && to >= 0 && to < N) {
            graph[from][to] = 1;
            // Se vuoi grafo non orientato, aggiungi anche: graph[to][from] = 1;
        } else {
            printf("Nodi non validi!\n");
            i--;
        }
    }

    printf("Inserisci nodo di partenza (0-%d): ", N-1);
    scanf("%d", &from);
    printf("Inserisci nodo di arrivo (0-%d): ", N-1);
    scanf("%d", &to);

    for (int i = 0; i < N; i++) visited[i] = 0;

    if (esiste_percorso(graph, from, to, visited)) {
        printf("Esiste un percorso da %d a %d\n", from, to);
    } else {
        printf("Non esiste un percorso da %d a %d\n", from, to);
    }

    return 0;
}