/*
 * =====================================================================================
 *
 *       Filename:  1572.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/12/2014 13:57:46
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
#include <cctype>
#include <algorithm>

const int kSize = 26 * 2;

int G[kSize][kSize];
int vis[kSize];

int ID(char a, char b) {
    return 2 * (a - 'A') + ((b == '+') ? 0 : 1);
}

void connect(char a1, char a2, char b1, char b2) {
    if (a1 == '0' || b1 == '0') return;
    int u = ID(a1, a2) ^ 1;
    int v = ID(b1, b2);
    G[u][v] = 1;
}

bool dfs(int u) {
    vis[u] = -1;
    for (int i = 0; i < kSize; ++i) {
        if (G[u][i]) {
            if (vis[i] == -1) return true;
            if (!vis[i] && dfs(i)) return true;
        }
    }
    vis[u] = 1;
    return false;
}

bool hasCircle() {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < kSize; ++i) {
        if (!vis[i]) {
            if (dfs(i))
                return true;
        }
    }
    return false;
}

int main() {
#ifdef Debug
    freopen("1572.in", "r", stdin);
#endif
    int n;
    char input[10];
    while (scanf("%d", &n) == 1 && n) {
        memset(G, 0, sizeof(G));
        while (n--) {
            scanf("%s", input);
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    if (i != j) {
                        connect(input[2*i], input[2*i+1], input[2*j], input[2*j+1]);
                    }
                }
            }
        }
        if (hasCircle()) {
            printf("unbounded\n");
        } else {
            printf("bounded\n");
        }
    }
    return 0;
}
