/*
 * =====================================================================================
 *
 *       Filename:  1354.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/11/2014 22:04:18
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
#include <vector>

using namespace std;

const int kMax = 8;

struct Tree {
    double L, R;
    Tree() : L(0), R(0) {}
};

int N, S;
double R, weight[kMax], sum_weight[1<<kMax];
bool vis[1<<kMax];
vector<Tree> tree[1<<kMax];

void dfs(int subset) {
    if (vis[subset]) return;
    vis[subset] = true;

    bool hasChild = false;
    for (int left = (subset-1)&subset; left; left = (left-1)&subset) {
        hasChild = true;
        int right  = left^subset; 
        double dl = sum_weight[right] / sum_weight[subset];
        double dr = sum_weight[left] / sum_weight[subset];
        dfs(left);
        dfs(right);
        for (int i = 0; i < tree[left].size(); ++i) {
            for (int j = 0; j < tree[right].size(); ++j) {
                Tree t;
                t.L = max(tree[left][i].L + dl, tree[right][j].L - dr);
                t.R = max(tree[right][j].R + dr, tree[left][i].R - dl);
                if (t.L+t.R < R) tree[subset].push_back(t);
            }
        }
    }
    if (!hasChild) {
        tree[subset].push_back(Tree());
    }
}

int main() {
#ifdef Debug
    freopen("1354.in", "r", stdin);
#endif
    scanf("%d", &N);
    while (N--) {
        scanf("%lf%d", &R, &S);
        for (int i = 0; i < S; ++i) {
            scanf("%lf", &weight[i]);
        }
        int len = 1 << S;
        for (int i = 0; i < len; ++i) {
            sum_weight[i] = 0;
            tree[i].clear();
            for (int j = 0; j < S; ++j) {
                if (i & 1 << j) sum_weight[i] += weight[j];
            }
        }

        memset(vis, 0, sizeof(vis));
        --len;
        dfs(len);
        double min = -1;
        for (int i = 0; i < tree[len].size(); ++i) {
            double t = tree[len][i].L + tree[len][i].R;
            if (t > min) {
                min = t;
            }
        }
        printf("%.10lf\n", min);
    }
    return 0;
}

