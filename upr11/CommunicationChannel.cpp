/**
 * @file CommunicationChannel.cpp
 *
 * Input: weighted undirected graph. The nodes of the graph are
 * physical devices. The edges represent links between them.
 * The weight of a link is the probability that a packet between
 * the nodes arrives successfully to the destination. It is thus
 * a number in the range[0, 1]. The probability that a packet
 * reaches a destination is independent of its path, i.e. the
 * path x -> y -> z, where w(x, y) = 0.5 and w(y, z) = 0.2, the
 * probability that the packed arrives at z is 0.5*0.2 = 0.1.
 * We are interested in a reliable network. Given a source,
 * determine the optimal probability that a packed reaches it
 * destination, for every destination.
 */

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
