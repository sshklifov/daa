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
