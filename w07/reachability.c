#include "Set.h"
#include "Queue.h" // bfs
#include "Stack.h" // dfs

typedef int Vertex;

typedef struct graph* Graph;
struct graph {
    int nV;
    int nE;
    int **matrix; // adjacency matrix (2d array)
    //List *adjList; // adjacency list (array of lists)
};

// Return a set containing all nodes that are reachable from v
Set reachable (Graph g, Vertex v) {
    Set seen = newSet();
    Queue q = newQueue();
    QueueEnter(q, v);
    while (!QueueIsEmpty(q)) {
        Vertex cur = leaveQueue(q);
        if (!setFind(seen, cur)) {
            setInsert(seen, cur);
            for (int i = 0; i < g->nV; i++) {
                if (g->matrix[cur][i] == 1) {
                    QueueEnter(q, i);
                }
            }
        }
    }
    return seen;
}