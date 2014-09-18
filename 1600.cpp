/*
 * =====================================================================================
 *
 *       Filename:  1600.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/18/2014 16:27:34
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
#include <queue>
#include <algorithm>

using namespace std;

const int kMax = 20 + 5;
int T, m, n, k;
int matrix[kMax][kMax];
bool vis[kMax][kMax];

struct Node {
    int r, c, o, step;
    Node(int a = 0, int b = 0) : r{a}, c{b}, o{0}, step{0} {}
};

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int Resolve() {
    memset(vis, 0, sizeof(vis));
    queue<Node> que; 
    que.emplace(0, 0);
    vis[0][0] = true;
    while (!que.empty()) {
        Node node = que.front();
        que.pop();
        if (node.r == (m-1) && node.c == (n-1)) {
            return node.step;
        }
        int r, c;
        for (int i = 0; i < 4; ++i) {
            r = node.r + dr[i];
            c = node.c + dc[i];
            if (r >= 0 && r < m && c >= 0 && c < n && !vis[r][c]) {
                Node next{r, c};
                if (matrix[r][c] == 1) {
                    if (node.o < k) 
                        next.o = node.o + 1;
                    else
                        continue;
                }
                next.step = node.step + 1;
                if (matrix[r][c] != 1) // if have obstacle, should visit it later, maybe from another node, the continuous obstacle will less
                    vis[r][c] = true;
                que.push(move(next));
            } 
        }
    }

    return -1;
}

int main() {
#ifdef Debug
    freopen("1600.in", "r", stdin);
#endif
    scanf("%d", &T); 
    while (T--) {
        scanf("%d %d", &m, &n);
        scanf("%d", &k);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &matrix[i][j]);
            }
        }
        printf("%d\n", Resolve());
    }
    return 0;
}
