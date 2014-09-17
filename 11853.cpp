/*
 * =====================================================================================
 *
 *       Filename:  11853.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/17/2014 17:57:42
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  cxwcfea(cxwcfea@163.com), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

const int kMax = 1000 + 5;
const double Width = 1000.0;

double x[kMax], y[kMax], r[kMax];
int n;
double left, right;
int vis[kMax];

bool IsIntersect(int c1, int c2) {
    return sqrt((x[c1]-x[c2])*(x[c1]-x[c2]) + (y[c1]-y[c2])*(y[c1]-y[c2])) < (r[c1]+r[c2]);
}

void CheckCircle(int u) {
    if (x[u] - r[u] < 0) {
        left = min(left, y[u] - sqrt(r[u]*r[u]-x[u]*x[u]));
    }
    if (x[u] + r[u] > Width) {
        right = min(right, y[u] - sqrt(r[u]*r[u]-(Width-x[u])*(Width-x[u])));
    }
}

bool dfs(int u) {
    vis[u] = 1;
    if (y[u] - r[u] < 0) return true;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            if (IsIntersect(u, i) && dfs(i)) return true;
        }
    }
    CheckCircle(u); 

    return false;
}

int main() {
#ifdef Debug
    freopen("11853.in", "r", stdin);
#endif
    while (scanf("%d", &n) == 1) {
        memset(vis, 0, sizeof(vis));
        left = right = Width;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            scanf("%lf %lf %lf", &x[i], &y[i], &r[i]); 
        }
        for (int i = 0; i < n; ++i) {
            if (y[i] + r[i] >= Width && dfs(i)) {
                ok = false;
                break;
            }
        }
        if (ok)
            printf("%.2f %.2f %.2f %.2f\n", 0.00, left, Width, right);
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}
