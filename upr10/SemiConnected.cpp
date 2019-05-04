#include <vector>
#include <stack>

#include "SemiConnectedOnDag.h"

enum Color {WHITE, GRAY, BLACK};
std::vector<Color> color;
std::stack<int> topologicalOrder;

void dfsVisitTopo(std::vector<int>* g, int n, int u)
{
    color[u] = GRAY;

    for (int v : g[u])
    {
        if (color[v] == WHITE)
        {
            dfsVisitTopo(g, n, v);
        }
    }

    color[u] = BLACK;
    topologicalOrder.push(u);
}

std::vector<int> component;
int numComps;

void dfsVisitScc(std::vector<int>* g, int n, int u, int id)
{
    color[u] = GRAY;
    component[u] = id;

    for (int v : g[u])
    {
        if (color[v] == WHITE)
        {
            dfsVisitScc(g, n, v, id);
        }
    }

    color[u] = BLACK;
}

std::vector<int>* transpose(std::vector<int>* g, int n)
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

void stronglyConComp(std::vector<int>* g, int n)
{
    color.assign(n, WHITE);
    for (int u = 0; u < n; ++u)
    {
        if (color[u] == WHITE) dfsVisitTopo(g, n, u);
    }

    color.assign(n, WHITE);
    component.assign(n, -1);

    std::vector<int>* t = transpose(g, n);
    while (!topologicalOrder.empty())
    {
        int u = topologicalOrder.top();
        topologicalOrder.pop();

        if (color[u] == WHITE) dfsVisitScc(t, n, u, numComps++);
    }

    delete[] t;
}

bool semiConnected(std::vector<int>* g, int n)
{
    stronglyConComp(g, n);

    std::vector<int>* scc = new std::vector<int>[numComps];
    for (int u = 0; u < numComps; ++u)
    {
        for (int v : g[u])
        {
            if (component[u] != component[v])
            {
                scc[component[u]].push_back(component[v]);
            }
        }
    }

    bool res = semiConnectedOnDag(scc, numComps);
    delete[] scc;
    return res;
}
