#include "Traversals.h"

bool isBipartite(std::vector<int>* g, int n)
{
    enum {COLOR1, COLOR2, NOCOLOR};
    std::vector<int> color (n, NOCOLOR);

    for (int i = 0; i < n; ++i)
    {
        if (color[i] == NOCOLOR)
        {
            bfs(g, n, i);

            std::vector<bool> good;
            for (int u = 0; u < n; ++u)
            {
                if (dist[u]!=INT_MAX && dist[u] % 2 == 1)
                {
                    color[u] = COLOR1;
                }
                if (dist[u]!=INT_MAX && dist[u] % 2 == 0)
                {
                    color[u] = COLOR2;
                }
            }
        }
    }

    for (int u = 0; u < n; ++u)
    {
        for (int v : g[u])
        {
            if (color[u] == color[v]) return false;
        }
    }
    return true;
}
