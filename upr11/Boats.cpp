/**
 * @file Boats.cpp
 *
 * Input: weighted undirected graph. The weights of the edges
 * represent how wide a canal is between vertices (we are
 * traveling with a boat). The cost of a path is defined as the
 * minimum weight of all edges in that path. This means that a
 * boat with that width will 'fit' in every canal and thus be
 * able to traverse the path. Moreover, no bigger boat will be
 * able to do so. We are interested in the maximum possible
 * width a boat can be to reach a vertex from the source, for
 * every vertex.
 */

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
