//Floyd's Algorithm
#include <stdio.h>
#include <limits.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int dist[MAX_NODES][MAX_NODES];
int opcount = 0;

void floyd(int n) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
                opcount++;
            }
        }
    }
}

int main() {
    int n, i, j;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == -1) {
                graph[i][j] = INT_MAX;
            }
        }
    }
    floyd(n);
    printf("The shortest distances between all pairs of nodes are:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("INF\t");
            } else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
    printf("Total number of operations performed: %d\n\n", opcount);
    return 0;
}
