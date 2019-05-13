#include "PriorityQueue.h"

void communicationChannel(std::vector<Edge>* g, int n, int s)
{
    std::vector<double> d(n);
    for (int i = 0; i < n; ++i)
    {
        d[i] = 0.0;
    }
    d[s] = 1.0;

    PriorityQueue q;
    buildMaxHeap(q, d);

    while (!heapEmpty(q))
    {
        int u = heapMaximum(q).to;
        d[u] = heapMaximum(q).w;
        heapDequeue(q);

        for (const Edge& e : g[u])
        {
            double reliability = d[u] * e.w;
            if (reliability > d[e.to])
            {
                d[e.to] = reliability;
                heapIncreaseKey(q, e.to, d[e.to]);
            }
        }
    }
}
