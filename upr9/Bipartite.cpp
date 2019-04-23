#include <queue>

enum {WHITE, BLACK1, BLACK2};
std::vector<int> color;

void bfsVisit(std::vector<int>* g, int s)
{
    color[s] = BLACK1;

    std::queue<int> q;
    q.push(s);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : g[u])
        {
            if (color[v] == WHITE)
            {
                color[v] = (color[u]==BLACK1 ? BLACK2 : BLACK1);
                q.push(v);
            }
        }
    }
}

bool isBipartite(std::vector<int>* g, int n)
{
    color.assign(n, WHITE);

    for (int v = 0; v < n; ++v)
    {
        if (color[v] == WHITE)
        {
            bfsVisit(g, v);
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
