/**
 * @file DagNumPaths.cpp
 *
 * Given a weighted dag and a source vertex s, find the least
 * cost of reaching a vertex, for every vertex.
 */

#include <vector>
#include <stack>
#include <climits>

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

void dagShortestPath(std::vector<Edge>* g, int n, int s)
{

    int* cost = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cost[i] = INT_MAX;
    }

    dfs(g, n);

    while (topologicalOrder.top() != s) topologicalOrder.pop();
    cost[s] = 0;

    while (!topologicalOrder.empty())
    {
        int u = topologicalOrder.top();
        topologicalOrder.pop();

        for (const Edge& e : g[u])
        {
            int w = cost[u] + e.weight;
            if (w < cost[e.to])
            {
                cost[e.to] = w;
            }
        }
    }

    delete[] cost;
}
