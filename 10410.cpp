/*
 * =====================================================================================
 *
 *       Filename:  10410.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/25/2014 11:54:38
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  cxwcfea(cxwcfea@163.com), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cassert>
#include <queue>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

const int kMax = 1000 + 5;

int n;
vector<int> result[kMax];
int bfs[kMax];
int dfs[kMax];

void Solve() {
    queue<pair<int, int>> que;
    que.push(make_pair(0, n));

    int bfs_index = 1;
    while (!que.empty()) {
        if (bfs_index == n) break;
        pair<int, int> sub_tree = que.front();
        que.pop();
        if (sub_tree.first + 1 == sub_tree.second) continue;
        int root = dfs[sub_tree.first];
        int sub_root = sub_tree.first+1;
        ++bfs_index;
        result[root].push_back(dfs[sub_root]);
        for (int i = sub_root+1; i < sub_tree.second; ++i) {
            if (bfs[bfs_index] == dfs[i]) {
                result[root].push_back(dfs[i]);
                ++bfs_index;
                que.push(make_pair(sub_root, i));
                sub_root = i;
            }
        }
        if (sub_root < sub_tree.second) {
            que.push(make_pair(sub_root, sub_tree.second));
        }
    }
}

int main() {
#ifdef Debug
    freopen("10410.in", "r", stdin);
#endif
    while (scanf("%d", &n) == 1) {
        int v;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &bfs[i]);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &dfs[i]);
        }
        for (int i = 1; i <= n; ++i) {
            result[i].clear(); 
        }
        Solve();
        for (int i = 1; i <= n; ++i) {
            printf("%d:", i);
            sort(result[i].begin(), result[i].end());
            for (auto &v : result[i]) {
                printf(" %d", v);
            }
            printf("\n");
        }
    }
    return 0;
}

