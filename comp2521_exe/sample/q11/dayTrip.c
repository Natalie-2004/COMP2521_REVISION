
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

// iterates through roads
// if balck, only iterate once
// if red, do again

static contains(Vertex vs[], int size, int v) {
    for (int i = 0; i < size; i++) {
        if (vs[i] == v) {
            return 1;
        }
    }
    return 0;
}

int dayTrip(Graph g, Vertex s, Vertex vs[]) {

    int size = 0;
    
    // 走普通路
    for (int i = 0; i < g->nV; i++) {
        // 一天能到
        if (g->stdEdges[s][i] && i != s) {
            if (contains(vs, size, i)) {
                // udpate road
                vs[size] = i;
                size++;
            }
        }
    }

    // 走高速
    for (int i = 0; i < g->nV; i++) {
        if (g->fastEdges[s][i] && i != s) {
            // s -> i
            if (contains(vs, size, i)) {
                // udpate road
                vs[size] = i;
                size++;
            }

            // i -> j
            for (int j = 0; j < g->nV; j++) {
                if (g->fastEdges[i][j] && i != j) {
                    if (!contains(vs, size, j) && j != s) {
                    // udpate road
                    vs[size] = j;
                    size++;
                    }
                }
            }
        }
    }

    return size;
}



