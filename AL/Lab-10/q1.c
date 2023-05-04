//Warshall's Algorithm
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int closure[MAX_NODES][MAX_NODES];
int opcount = 0;

void transitive_closure(int n) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            closure[i][j] = graph[i][j];
        }
    }
    for (i = 0; i < n; i++) {
        for (k = 0; k < n; k++) {
            for (j = 0; j < n; j++) {
                closure[i][j] = closure[i][j] || (closure[i][k] && closure[k][j]);
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
        }
    }
    transitive_closure(n);
    printf("Warshall's ALgorithm\nThe transitive closure is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", closure[i][j]);
        }
        printf("\n");
    }
    printf("Total number of operations performed: %d\n\n", opcount);
    return 0;
}
