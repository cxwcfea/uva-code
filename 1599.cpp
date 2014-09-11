/*
 * =====================================================================================
 *
 *       Filename:  1599.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/11/2014 14:51:11
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
#include <cctype>
#include <cstring>
#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int kMax = 100000 + 5;
const int INF = 1000000000;

struct Edge {
    int u, v, c;
    Edge(int a = 0, int b = 0, int color = 0) : u{a}, v{b}, c{color} {}
};

int n;

vector<Edge> edges; 
vector<int> graph[kMax];

int d[kMax], vis[kMax];

void AddEdge(int u, int v, int c) {
    graph[u].push_back(edges.size());
    edges.emplace_back(u, v, c);
}

void rev_bfs() {
    memset(vis, 0, sizeof(vis));
    memset(d, 0, sizeof(d));
    d[n] = 0;
    vis[n] = 1;
    queue<int> que;
    que.push(n);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto e : graph[v]) {
            int u = edges[e].v;
            if (!vis[u]) {
                d[u] = d[v] + 1;
                que.push(u);
                vis[u] = 1;
            }
        }
    }
}

void bfs() {
    vector<int> ans;
    vector<int> next;
    next.push_back(1);
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < d[1]; ++i) {
        int min_color = INF;
        for (int j = 0; j < next.size(); ++j) {
            int u = next[j];
            for (auto e : graph[u]) {
                int v = edges[e].v;
                if (d[u] == d[v] + 1) {
                    min_color = min(min_color, edges[e].c);
                }
            }
        }
        ans.push_back(min_color);

        vector<int> next2;
        for (int j = 0; j < next.size(); ++j) {
            int u = next[j];
            for (auto e : graph[u]) {
                int v = edges[e].v;
                if (d[u] == d[v] + 1 && !vis[v] && edges[e].c == min_color) {
                    vis[v] = 1;
                    next2.push_back(v);
                }
            }
        }
        swap(next, next2);
    }
    printf("%lu\n", ans.size());
    for (int i = 0; i < ans.size() - 1; ++i) {
        printf("%d ", ans[i]);
    }
    printf("%d\n", ans.back());
}

int main() {
#ifdef Debug
    freopen("1599.in", "r", stdin);
#endif
    int m, a, b, c;
    while (scanf("%d %d", &n, &m) == 2) {
        edges.clear();
        for (auto &v : graph) {
            v.clear();
        }
        while (m--) {
            scanf("%d %d %d", &a, &b, &c);
            AddEdge(a, b, c);
            AddEdge(b, a, c);
        }
        rev_bfs();
        /*
        for (auto a : edges) {
            printf("edge %d %d %d\n", a.u, a.v, a.c);
        }
        for (int i = 1; i <= n; ++i) {
            printf("d[%d] = %d\n", i, d[i]);
        }
  */
        bfs();
    }
    return 0;
}
