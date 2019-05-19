/**
 * @file WeightedVertices.cpp
 *
 * Given a directed graph and a weight function, determine the
 * least cost to reach a vertex, for every vertex. The problem
 * is that the weight function is defined for vertices, instead
 * of edges. That is, given a path v1 -> v2 -> v3, the cost
 * is calculated as w(v1) + w(v2) + w(v3).
 */

#include <vector>

struct Edge
{
    int to;
    int w;
};

void weightedVertices(std::vector<int>* g, int n, int s, std::vector<int> w)
{
    std::vector<Edge>* gg = new std::vector<Edge>[n];
    for (int u = 0; u < n; ++u)
    {
        for (int v : g[u])
        {
            gg[u].push_back(Edge{v, w[v]});
        }
    }

    /* d <- Dijkstra(gg, n, s) */
    /* for u <- 0 to n-1 */
    /*     d[u] <- d[u] + w[s] */

    delete[] gg;
}
