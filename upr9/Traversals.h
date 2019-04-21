#ifndef TRAVERSLS_INCLUDED
#define TRAVERSLS_INCLUDED

#include <vector>
#include <climits>

extern std::vector<int> pred;
extern std::vector<int> dist;

extern std::vector<int> discover;
extern std::vector<int> finish;
extern int t;

void bfs(std::vector<int>* g, int n, int s);
void dfs(std::vector<int>* g, int n);

#endif
