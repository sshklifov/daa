#include <vector>
#include <stack>
#include <iostream>

struct Edge
{
    int to;
    int weight;
};

enum Color {WHITE, GRAY, BLACK};
std::vector<Color> color;
std::stack<int> topologicalOrder;

void dfsVisit(std::vector<Edge>* g, int n, int u)
{
    color[u] = GRAY;

    for (const Edge& e : g[u])
    {
        if (color[e.to] == WHITE)
        {
            dfsVisit(g, n, e.to);
        }
    }

    color[u] = BLACK;
    topologicalOrder.push(u);
}

void dfs(std::vector<Edge>* g, int n)
{
    color.assign(n, WHITE);

    for (int u = 0; u < n; ++u)
    {
        if (color[u] == WHITE) dfsVisit(g, n, u);
    }
}

void earliestFinish(std::vector<Edge>* g, int n)
{
    dfs(g, n);

    int* earliestStart = new int[n];
    for (int i = 0; i < n; ++i)
    {
        earliestStart[i] = 0;
    }

    while (!topologicalOrder.empty())
    {
        int u = topologicalOrder.top();
        topologicalOrder.pop();

        printf ("%d\n", u);
        for (const Edge& e : g[u])
        {
            int t = earliestStart[u] + e.weight;
            if (t > earliestStart[e.to])
            {
                earliestStart[e.to] = t;
            }
        }
    }

    int res = earliestStart[0];
    for (int i = 1; i < n; ++i)
    {
        if (earliestStart[i] > res)
        {
            res = earliestStart[i];
        }
    }

    std::cout << "Earliest finish: " << res << std::endl;
}
