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
