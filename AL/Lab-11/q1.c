#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 50

struct edge {
    int u, v, weight;
};

int parent[MAX_EDGES], rank[MAX_EDGES];

void make_set(int x) {
    parent[x] = x;
    rank[x] = 0;
}

int find_set(int x) {
    if (parent[x] != x)
        parent[x] = find_set(parent[x]);
    return parent[x];
}

void union_sets(int x, int y) {
    int root_x = find_set(x);
    int root_y = find_set(y);
    if (root_x != root_y) {
        if (rank[root_x] > rank[root_y])
            parent[root_y] = root_x;
        else if (rank[root_x] < rank[root_y])
            parent[root_x] = root_y;
        else {
            parent[root_y] = root_x;
            rank[root_x]++;
        }
    }
}

int cmpfunc(const void *a, const void *b) {
    struct edge *edge1 = (struct edge *)a;
    struct edge *edge2 = (struct edge *)b;
    return edge1->weight - edge2->weight;
}

void kruskal(int n, struct edge edges[], int num_edges) {
    int i, j;
    struct edge mst[MAX_EDGES];
    int mst_size = 0;
    qsort(edges, num_edges, sizeof(struct edge), cmpfunc);
    for (i = 1; i <= n; i++)
        make_set(i);
    for (i = 0; i < num_edges && mst_size < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find_set(u) != find_set(v)) {
            mst[mst_size++] = edges[i];
            union_sets(u, v);
        }
    }
    if (mst_size != n - 1)
        printf("Graph is not connected\n");
    else {
        printf("Minimum Spanning Tree:\n");
        int mst_cost = 0;
        for (i = 0; i < mst_size; i++) {
            printf("(%d,%d):%d\n", mst[i].u, mst[i].v, mst[i].weight);
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