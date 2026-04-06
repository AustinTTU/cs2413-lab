#include "graph.h"

// Description

// Check whether the graph contains a triangle. A triangle is a set of three nodes that are all connected to each other. 
// The graph is stored as an adjacency matrix. 
// Graph* g is a pointer to a Graph struct, which contains a 2D array adj[MAX_NODES][MAX_NODES]. 
// The value at adj[u][v] is 1 if there is an edge between nodes u and v, and 0 otherwise.

int has_triangle(Graph* g) {
    // TODO: implement
    // return -1;
    for (int a = 0; a < MAX_NODES; a++){
        for (int b = 0; b < MAX_NODES; b++) {
            if (g->adj[b][a]) {
                for (int c = 0; c < MAX_NODES; c++) {
                    if ((g->adj[a][c] == 1) && (g->adj[b][c] == 1)) return 1;
                }
            }
        }
    }
    return 0;
}