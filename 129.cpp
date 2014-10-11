/*
 * =====================================================================================
 *
 *       Filename:  129.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/11/2014 10:18:33
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
#include <cmath>
#include <algorithm>

const int kMax = 80 + 5;

int n, L;
char sequence[kMax];
int cnt;

int dfs(int cur) {
    //printf("cur %d\n", cur);
    if (cnt++ == n) {
        int numGroup = 0;
        for (int i = 0; i < cur; ++i) {
            if (i && i%4 == 0) {
                ++numGroup; 
                if (numGroup == 16) {
                    printf("\n");
                    numGroup = 0;
                } else {
                    printf(" ");
                }
            }
            printf("%c", sequence[i]);
        }
        printf("\n");
        printf("%d\n", cur); 
        return 0;
    } else {
        for (int i = 0; i < L; ++i) {
            sequence[cur] = 'A' + i;
            bool ok = true;
            for (int j = 1; 2 * j <= cur+1; ++j) {
                bool same = true;
                for (int k = 0; k < j; ++k) {
                    //printf("cur %d, j %d, k %d, %c %c\n", cur, j, k, sequence[cur-k], sequence[cur-j-k]);
                    if (sequence[cur-k] != sequence[cur-j-k]) {
                        same = false; 
                        break;
                    }
                }
                if (same) { 
                    ok = false;
                    break;
                }
            }
            if (ok && !dfs(cur+1)) return 0;
        }
    }
    return 1;
}

int main() {
#ifdef Debug
    freopen("129.in", "r", stdin);
#endif
    while (true) {
        scanf("%d%d", &n, &L);
        if (!n && !L) break;
        cnt = 0;
        dfs(0);
    }
    return 0;
}
