/**
 * @file VerifyDijkstra.cpp
 *
 * You are given a weighted directed graph and a random spanning
 * tree of the graph, which is rooted at s. You are interested
 * whether any instance of Dijkstra's algorithm will generate
 * this tree. For simplicity, you will be given the cost to reach
 * each vertex, instead of the whole tree.
 */

#include <vector>

struct Edge
{
    int to;
    int w;
};

bool verifyDijkstra(std::vector<Edge>* g, int n, std::vector<int> d)
{
    for (int u = 0; u < n; ++u)
    {
        for (const Edge& e : g[u])
        {
            int v = e.to;
            if (d[u] + e.w < d[v]) return false;
        }
    }
    return true;
}
