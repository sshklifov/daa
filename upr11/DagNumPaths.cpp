#include <vector>
#include <stack>
#include <climits>

enum Color {WHITE, GRAY, BLACK};
static std::vector<Color> color;
static std::vector<int> topologicalOrder;

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
    topologicalOrder.push_back(u);
}

static void dfs(std::vector<int>* g, int n)
{
    color.assign(n, WHITE);

    for (int u = 0; u < n; ++u)
    {
        if (color[u] == WHITE) dfsVisit(g, n, u);
    }
}

void dagNumPaths(std::vector<int>* g, int n)
{
    int* cnt = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cnt[i] = 0;
    }

    dfs(g, n);

    for (int i = 0; i < n; ++i)
    {
        // NOTE: reverse topological order traversal
        int u = topologicalOrder[i];
        for (int v : g[u])
        {
            cnt[u] += cnt[v] + 1;
        }
    }

    delete[] cnt;
}
