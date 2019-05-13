#include "PriorityQueue.h"
#include <cassert>

inline int leftIndex(int i)
{
    return i*2 + 1;
}

inline int rightIndex(int i)
{
    return i*2 + 2;
}

inline int parentIndex(int i)
{
    return (i-1) / 2;
}

static void siftDown(PriorityQueue& q, int i)
{
    size_t l = leftIndex(i);
    size_t r = rightIndex(i);

    int biggest = i;
    if (l < q.h.size() && q.h[l].w > q.h[i].w) biggest = l;
    if (r < q.h.size() && q.h[r].w > q.h[biggest].w) biggest = r;

    if (biggest != i)
    {
        std::swap(q.h[i], q.h[biggest]);
        std::swap(q.pos[q.h[i].to], q.pos[q.h[biggest].to]);
        siftDown(q, biggest);
    }
}

static void siftUp(PriorityQueue& q, int i)
{
    int parent;
    while (i != 0 && q.h[i].w > q.h[parent=parentIndex(i)].w)
    {
        std::swap(q.h[i], q.h[parent]);
        std::swap(q.pos[q.h[i].to], q.pos[q.h[parent].to]);
        i = parent;
    }
}

const Edge& heapMaximum(const PriorityQueue& q)
{
    return q.h[0];
}

bool heapEmpty(const PriorityQueue& q)
{
    return q.h.empty();
}

bool heapHasElement(const PriorityQueue& q, int v)
{
    int n = q.pos.size();
    return (0 <= v && v < n) && q.pos[v] != -1;
}

int heapElementPrio(const PriorityQueue& q, int v)
{
    assert (heapHasElement(q, v));

    return q.h[q.pos[v]].w;
}

void buildMaxHeap(PriorityQueue& q, const std::vector<double>& v)
{
    int n = v.size();

    q.h.resize(n);
    q.pos.resize(n);
    for (int i = 0; i < n; ++i)
    {
        q.h[i] = Edge{i, v[i]};
        q.pos[i] = i;
    }

    for (int i = parentIndex(n-1); i >= 0; --i)
    {
        siftDown(q, i);
    }
}

void heapDequeue(PriorityQueue& q)
{
    assert(!heapEmpty(q));

    q.pos[q.h.back().to] = 0;
    q.pos[q.h.front().to] = -1;
    std::swap(q.h.front(), q.h.back());
    q.h.pop_back();

    siftDown(q, 0);
}

void heapIncreaseKey(PriorityQueue& q, int v, double key)
{
    int pos = q.pos[v];
    if (pos != -1 && q.h[pos].w < key)
    {
        q.h[pos].w = key;
        siftUp(q, pos);
    }
}
