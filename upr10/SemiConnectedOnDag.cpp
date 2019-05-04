#include "SemiConnectedOnDag.h"

#include <vector>
#include <stack>

enum Color {WHITE, GRAY, BLACK};
static std::vector<Color> color;
static std::stack<int> topologicalOrder;

static void dfsVisit(std::vector<int>* g, int n, int u)
{
    color[u] = GRAY;

    for (int v : g[u])
    {
        if (color[v] == WHITE)
        {
            dfsVisit(g, n, v);
        }
    }

    color[u] = BLACK;
    topologicalOrder.push(u);
}

static void dfs(std::vector<int>* g, int n)
{
    color.assign(n, WHITE);

    for (int u = 0; u < n; ++u)
    {
        if (color[u] == WHITE) dfsVisit(g, n, u);
    }
}

bool semiConnectedOnDag(std::vector<int>* g, int n)
{
    dfs(g, n);

    int prev = topologicalOrder.top();
    topologicalOrder.pop();

    while (!topologicalOrder.empty())
    {
        int curr = topologicalOrder.top();
        topologicalOrder.pop();

        bool found = false;
        for (int v : g[prev])
        {
            if (v == curr)
            {
                found = true;
                break;
            }
        }

        if (!found) return false;
        prev = curr;
    }

    return true;
}
