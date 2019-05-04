#ifndef PRIORITY_QUEUE_INCLUDED
#define PRIORITY_QUEUE_INCLUDED

/**
 * @file PriorityQueue.h
 * @brief Custom priority queue.
 *
 * Prim's algorithm uses a priority queue. Except the standard
 * methods, such as heapDecreaseKey and heapMinimum, it must also
 * support lookup based on the vertex, i.e. given a vertex, we need
 * to be able to deduce its position in the binary heap in constant
 * time. This can be achieved with addition linear space by keeping
 * the position of each vertex in a lookup array and maintaining it
 * on heapDequeue and heapDecreaseKey operations.
 */

#include <vector>

/**
 * @brief Used in PriorityQueue.
 *
 * Will contain the least cost edge (with weight `w`) to vertex `to`
 * seen thus far during the execution of Prim's algorithm.
 */
struct Edge
{
    int to;
    int w;
};

/**
 * @brief Custom min heap priority queue.
 *
 * Each priority queue will contain the min heap `h` and the lookup
 * array `pos`, which at index `v` contains the position of vertex
 * `v` inside the min heap `h`.
 */
struct PriorityQueue
{
    std::vector<Edge> h;
    std::vector<int> pos;
};

/**
 * @brief Minimum of heap.
 * @param q The heap.
 * @return The pair <vertex, weight> where weight is minimal.
 */
extern const Edge& heapMinimum(const PriorityQueue& q);

/**
 * @brief Check if heap is empty.
 * @param q The heap.
 * @return True iff the heap is empty.
 */
extern bool heapEmpty(const PriorityQueue& q);

/**
 * @brief Check for membership.
 * @param q The heap.
 * @param v The vertex.
 * @return True iff there exists an Edge with to=`v` inside `q`.
 */
extern bool heapHasElement(const PriorityQueue& q, int v);

/**
 * @brief Get priority for vertex.
 * @param q The heap.
 * @param v The vertex.
 * @return The weight attribte of pair <`v`, weight> in q.
 * @remark The pair<`v`, weight> is assumed to exist.
 */
extern int heapElementPrio(const PriorityQueue& q, int v);

/**
 * @brief Build a min heap.
 * @param q Where to store the result.
 * @param v A vector containing the initial weights of vertices.
 * @return Void
 * @remark The old contents of `q` will be erased.
 *
 */
extern void buildMinHeap(PriorityQueue& q, const std::vector<int>& v);

/**
 * @brief Remove heap minimum.
 * @param q The heap.
 * @return Void.
 */
extern void heapDequeue(PriorityQueue& q);

/**
 * @brief Increase the priority of a vertex
 * @param q The heap
 * @param v The vertex whose priority to increase
 * @param key The new priority for `v`.
 * @return Void.
 * @remark Does nothing if `v`s priority is higher than `key`.
 */
extern void heapDecreaseKey(PriorityQueue& q, int v, int key);

#endif
