#include "PriorityQueue.h"
#include <climits>
#include <iostream>

void prim(std::vector<Edge>* g, int n, int r)
{
    PriorityQueue q;
    std::vector<int> key(n, INT_MAX);
    std::vector<int> pred(n, -1);
    key[r] = 0;
    buildMinHeap(q, key);

    int weight = 0;
    while (!heapEmpty(q))
    {
        int u = heapMinimum(q).to;
        weight += heapMinimum(q).w;
        heapDequeue(q);

        for (const Edge& e : g[u])
        {
            if (heapHasElement(q, e.to) && heapElementPrio(q, e.to) > e.w)
            {
                pred[e.to] = u;
                heapDecreaseKey(q, e.to, e.w);
            }
        }
    }

    std::cout << "weight: " << weight;
}
