/*
 * =====================================================================================
 *
 *       Filename:  712.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/18/2014 15:11:32
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
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>

const int kMax = 512;

int n, m, len;
char input[kMax];
int digits[kMax];
int tree[10];

void Resolve() {
    int node_id = 0;
    for (int i = 0; i < n; ++i) {
        node_id *= 2;
        if (!tree[i]) {
            node_id += 1;
        } else {
            node_id += 2;
        }
    }
    node_id -= (len - 1);
    printf("%d", digits[node_id]);
}

int main() {
#ifdef Debug
    freopen("712.in", "r", stdin);
#endif
    int T = 0;
    while (scanf("%d", &n) == 1 && n) {
        printf("S-Tree #%d:\n", ++T);
        for (int i = 0; i < n; ++i)
            scanf("%s", input);
        scanf("%s", input);
        len = pow(2, n);
        for (int i = 0; i < len; ++i) {
            digits[i] = input[i]-'0';
        }
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            scanf("%s", input);
            for (int j = 0; j < n; ++j) {
                tree[j] = input[j]-'0';
            }
            Resolve();
        }
        printf("\n\n");
    }
    return 0;
}

