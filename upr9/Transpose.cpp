#include <vector>

std::vector<int>* transposeGraph(std::vector<int>* g, int n)
{
    std::vector<int>* t = new std::vector<int>[n];
    for (int u = 0; u < n; ++u)
    {
        for (int v : g[u])
        {
            int edgeFrom = u;
            int edgeTo = v;
            t[edgeTo].push_back(edgeFrom);
        }
    }

    return t;
}
