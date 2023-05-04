#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 50

struct edge {
    int u, v, weight;
};

int cmpfunc(const void *a, const void *b) {
    struct edge *edge1 = (struct edge *)a;
    struct edge *edge2 = (struct edge *)b;
    return edge1->weight - edge2->weight;
}

void kruskal(int n, struct edge edges[], int num_edges) {
    int i;
    struct edge mst[MAX_EDGES];
    int mst_size = 0;
    qsort(edges, num_edges, sizeof(struct edge), cmpfunc);
    int parent[n];
    for (i = 1; i <= n; i++)
        parent[i] = i;
    for (i = 0; i < num_edges && mst_size < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        while (parent[u] != u)
            u = parent[u];
        while (parent[v] != v)
            v = parent[v];
        if (u != v) {
            mst[mst_size++] = edges[i];
            parent[v] = u;
        }
    }
    if (mst_size != n - 1)
        printf("Graph is not connected\n");
    else {
        printf("Minimum Spanning Tree:\n");
        int mst_cost = 0;
        for (i = 0; i < mst_size; i++) {
            printf("(%d,%d) -> %d\n", mst[i].u, mst[i].v, mst[i].weight);
            mst_cost += mst[i].weight;
        }
        printf("Minimum Spanning Tree Cost: %d\n", mst_cost);
    }
}

int main() {
    int n, num_edges, i;
    struct edge edges[MAX_EDGES];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);
    for (i = 0; i < num_edges; i++) {
        printf("Enter edge %d (u,v,w): ", i+1);
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }
    kruskal(n, edges, num_edges);
    return 0;
}
