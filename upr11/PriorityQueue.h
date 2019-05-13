#ifndef PRIORITY_QUEUE_INCLUDED
#define PRIORITY_QUEUE_INCLUDED

/**
 * @file PriorityQueue.h
 * @brief Custom max priority queue.
 */

#include <vector>

struct Edge
{
    int to;
    double w;
};

struct PriorityQueue
{
    std::vector<Edge> h;
    std::vector<int> pos;
};

extern const Edge& heapMaximum(const PriorityQueue& q);
extern bool heapEmpty(const PriorityQueue& q);
extern bool heapHasElement(const PriorityQueue& q, int v);
extern int heapElementPrio(const PriorityQueue& q, int v);
extern void buildMaxHeap(PriorityQueue& q, const std::vector<double>& v);
extern void heapDequeue(PriorityQueue& q);
extern void heapIncreaseKey(PriorityQueue& q, int v, double key);

#endif
