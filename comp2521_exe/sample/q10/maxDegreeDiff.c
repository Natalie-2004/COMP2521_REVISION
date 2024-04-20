
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

// Adj List
// 0 -> 1 2 3
// 1 -> 0 2
// 2 -> 1
// 3 -> 

static int in(int v, Graph g);
static int out(int v, Graph g);
static int contains(struct adjNode *head, int v);

static int contains(struct adjNode *head, int v) {
    struct adjNode *curr = head;
    while (curr != NULL) {
        if (curr->v == v) {
            return 1;
        } 
        curr = curr->next;
    }

    return 0;
}

static int in(int v, Graph g) {
    int result = 0;
    for (int i = 0; i < g->nV; i++) {
        if (i != v) {
            struct adjNode *edge = g->edges[i];
            if (contains(edge, v)) {
                result++;
            }
        }
    }

    return result;
}

static int out(int v, Graph g) {
    struct adjNode *t = g->edges[v];
    int count = 0;
    struct adjNode *head = t;
    while (head != NULL) {
        count++;
        head = head->next;
    }

    return count;
}

int maxDegreeDiff(Graph g) {
    int maxDiff = 0;

    // 求每个节点
    for (int v = 0; v < GraphNumVertices(g); v++) {
        int inDegree = in(v, g);
        int outDegree = out(v, g);

        if (abs(inDegree - outDegree) > 1) {
            maxDiff = abs(inDegree - outDegree);
        }
    }

    return maxDiff;
}

