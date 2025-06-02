#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100

typedef struct {
    int u, v, weight;
} Edge;

Edge edges[MAX_EDGES];
int parent[MAX_EDGES];
int n, e;  
int compare(const void* a, const void* b) {
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    return e1->weight - e2->weight;
}

// Find function with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}
void unionSets(int x, int y) {
    int xRoot = find(x);
    int yRoot = find(y);
    parent[xRoot] = yRoot;
}

void kruskal() {
    int i, count = 0, totalWeight = 0;

    
    for (i = 0; i < n; i++)
        parent[i] = i;

   
    qsort(edges, e, sizeof(Edge), compare);

    printf("Edges in Minimum Spanning Tree:\n");
    for (i = 0; i < e && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        if (find(u) != find(v)) {
            printf("%d -- %d == %d\n", u, v, w);
            unionSets(u, v);
            totalWeight += w;
            count++;
        }
    }

    printf("Total weight of MST: %d\n", totalWeight);
}

int main() {
    // Example graph input
    n = 4;  // number of vertices
    e = 5;  // number of edges

    edges[0] = (Edge){0, 1, 1};
    edges[1] = (Edge){0, 2, 3};
    edges[2] = (Edge){1, 2, 2};
    edges[3] = (Edge){1, 3, 4};
    edges[4] = (Edge){2, 3, 5};

    kruskal();

    return 0;
}
