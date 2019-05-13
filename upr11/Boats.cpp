#include "PriorityQueue.h"
#include <limits>
#include <cmath>

void boats(std::vector<Edge>* g, int n, int s)
{
    std::vector<double> d(n);
    for (int i = 0; i < n; ++i)
    {
        d[i] = 0.0;
    }
    d[s] = std::numeric_limits<double>::infinity();

    PriorityQueue q;
    buildMaxHeap(q, d);

    while (!heapEmpty(q))
    {
        int u = heapMaximum(q).to;
        d[u] = heapMaximum(q).w;
        heapDequeue(q);

        for (const Edge& e : g[u])
        {
            double width = fmin(d[u], e.w);
            if (width > d[e.to])
            {
                d[e.to] = width;
                heapIncreaseKey(q, e.to, d[e.to]);
            }
        }
    }
}
