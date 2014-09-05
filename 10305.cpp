/*
 * =====================================================================================
 *
 *       Filename:  10305.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/05/2014 21:25:30
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
#include <algorithm>

const int kMax = 100 + 10;
int G[kMax][kMax];
int result[kMax];
int vis[kMax];
int n, m;
int pos;

bool dfs(int v) {
    //printf("visit %d\n", v);
    vis[v] = -1;
    for (int i = 1; i <= n; ++i) {
        if (G[v][i]) {
            if (vis[i] == -1) return false;
            if (vis[i] == 0 && !dfs(i)) return false;
        }
    }
    vis[v] = 1;
    result[--pos] = v;
    return true;
}

void Solve() {
    memset(vis, 0, sizeof(vis));
    pos = n;
    for (int i = 1; i <= n; ++i) {
        bool start = true;
        for (int j = 1; j <= n; ++j) {
            if (G[j][i]) {
                start = false;
                break;
            } 
        }
        if (start && vis[i] == 0) {
            dfs(i);
        }
    }
}

void DebugOutput() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
#ifdef Debug
    freopen("10305.in", "r", stdin);
#endif
    int a, b;
    while (true) {
        scanf("%d %d", &n, &m);
        if (!n && !m) break;
        memset(G, 0, sizeof(G));
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &a, &b);
            G[a][b] = 1;
        }
        //DebugOutput();
        Solve();
        printf("%d", result[0]); 
        for (int i = 1; i < n; ++i) {
            printf(" %d", result[i]);
        }
        printf("\n");
    }
    return 0;
}
