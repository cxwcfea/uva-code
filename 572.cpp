/*
 * =====================================================================================
 *
 *       Filename:  572.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/01/2014 21:17:38
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

const int kMax = 103;
char matrix[kMax][kMax];
int m, n;

void dfs(int r, int c) {
    if (r < 0 || r >= m || c < 0 || c >= n || matrix[r][c] != '@') {
        return;
    }
    matrix[r][c] = '*';
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            if (i != 0 || j != 0)
                dfs(r+i, c+j);
        }
    }
}

int main() {
#ifdef Debug
    freopen("572.in", "r", stdin);
#endif
    while (true) {
        scanf("%d %d\n", &m, &n);
        if (!m && !n) break;
        int count = 0;
        for (int i = 0; i < m; ++i) {
            scanf("%s", matrix[i]);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '@') {
                    dfs(i, j);
                    ++count;
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
