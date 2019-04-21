#include "Traversals.h"

/* 'g' is the adjacency list representation of the tree.
   The tree can be represented as a directed graph with
   edges only from parent to child. Alternatively, it can
   contain the edges from child to parent as well, making
   it symmetric.

     a
    / \
   b   c

   case 1) Adj[a] = [b, c] ; Adj[b] = []  ; Adj[c] -> []
   case 2) Adj[a] = [b, c] ; Adj[b] = [a] ; Adj[c] -> [a]

   We can convert from 1) to 2) by adding the symmetric edges,
   e.g. create a new graph and for each edge (u, v) add v to
   Adj[u] and add u to Adj[v] of the new graph. Thus, we will
   assume that 'g' is symmetric (case 2).
*/
int treeDiameter(std::vector<int>* g, int n)
{
    int root = 0; // any vertex can be the root
    bfs(g, n, root);

    int from = root;
    int maxDist = 0;
    for (int u = 0; u < n; ++u)
    {
        if (dist[u] > maxDist)
        {
            maxDist = dist[u];
            from = u;
        }
    }

    bfs(g, n, from);

    int to = from;
    maxDist = 0;
    for (int u = 0; u < n; ++u)
    {
        if (dist[u] > maxDist)
        {
            maxDist = dist[u];
            to = u;
        }
    }

    return maxDist;
}
