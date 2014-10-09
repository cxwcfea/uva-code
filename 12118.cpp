/*
 * =====================================================================================
 *
 *       Filename:  12118.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/09/2014 14:12:26
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  cxwcfea(cxwcfea@163.com), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

const int kMax = 1000 + 10;

int graph[kMax][kMax];
int V, E, T;
bool vis[kMax];
vector<int> current_vertex;
int num_visited;

void dfs(int u) {
    vis[u] = true;
    current_vertex.push_back(u);
    for (int i = 1; i <= V; ++i) {
        if (graph[u][i] && !vis[i]) {
            dfs(i);
        }
    }
}

void calculate_degree() {
    int odd_vertex = 0;
    for (auto &v : current_vertex) {
        int degree = 0;
        for (int i = 1; i <= V; ++i) {
            if (graph[v][i]) {
                ++degree;
            }
        }
        if (degree % 2) {
            ++odd_vertex;
        }
    }
    int k = odd_vertex / 2; 
    if (k > 1) {
        num_visited += k - 1;
    }
}

void solve() {
    num_visited = E;
    memset(vis, 0, sizeof(vis)); 
    // first find the connected sub graph, for each sub graph, see if it is Euler path,
    // if it is Euler path, no need to increase the highway which need visited.
    // otherwise, if the sub grash has 2*k odd vertex, it needs k times travel, so needs add k-1 times highway visit.
    // And each sub grash needs one more time highway visit
    for (int i = 1; i <= V; ++i) {
        if (!vis[i]) {
            current_vertex.clear();
            dfs(i);
            if (current_vertex.size() > 1) { // if the sub graph do not contain any edge, on need to consider it.
                ++num_visited;
                calculate_degree();
            }
        }
    }
    --num_visited;
}

int main() {
#ifdef Debug
    freopen("12118.in", "r", stdin);
#endif
    int cases = 0;
    while (true) {
        scanf("%d %d %d", &V, &E, &T);
        if (!V && !E && !T) break;
        memset(graph, 0, sizeof(graph));
        int u, v;
        for (int i = 0; i < E; ++i) {
            scanf("%d %d", &u, &v); 
            graph[u][v] = graph[v][u] = 1;
        } 
        if (E)
            solve();
        else
            num_visited = 0;
        printf("Case %d: %d\n", ++cases, num_visited * T);
    }
    return 0;
}
