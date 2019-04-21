#include "Traversals.h"

#include <vector>
#include <queue>
#include <climits>

enum Color {WHITE, GRAY, BLACK};
static std::vector<Color> color;

std::vector<int> pred;
std::vector<int> dist;

std::vector<int> discover;
std::vector<int> finish;
int t;

void bfs(std::vector<int>* g, int n, int s)
{
    color.assign(n, WHITE);
    dist.assign(n, INT_MAX);
    pred.assign(n, -1);

    color[s] = GRAY;
    dist[s] = 0;
    pred[s] = -1;

    std::queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : g[u])
        {
            if (color[v] == WHITE)
            {
                color[v] = GRAY;
                dist[v] = dist[u] + 1;
                pred[v] = u;
                q.push(v);
            }
        }
        color[u] = BLACK;
    }
}

static void dfsVisit(std::vector<int>* g, int n, int u)
{
    t = t + 1;
    discover[u] = t;
    color[u] = GRAY;

    for (int v : g[u])
    {
        if (color[v] == WHITE)
        {
            pred[v] = u;
            dfsVisit(g, n, v);
        }
    }

    color[u] = BLACK;
    t = t + 1;
    finish[u] = t;
}

void dfs(std::vector<int>* g, int n)
{
    color.assign(n, WHITE);
    pred.assign(n, -1);

    discover.resize(n);
    finish.resize(n);
    t = 0;

    for (int u = 0; u < n; ++u)
    {
        if (color[u] == WHITE) dfsVisit(g, n, u);
    }
}
