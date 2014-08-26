/*
 * =====================================================================================
 *
 *       Filename:  11988.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/26/2014 17:04:29
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

const int kMax = 100005;

char input[kMax];
int next[kMax];

int main() {
#ifdef Debug
    freopen("11988.in", "r", stdin);
#endif
    while (fgets(input+1, kMax, stdin)) {
        int i = 0;
        int cur = 0;
        int tail = 0;
        memset(next, sizeof(next), 0);
        while (input[i] != '\n') {
            if (input[i] == '[') {
                cur = 0;
            } else if (input[i] == ']') {
                cur = tail;
            } else {
                next[i] = next[cur];
                next[cur] = i;
                if (cur == tail) {
                    tail = i;
                }
                cur = i;
            }
            ++i;
        }

        for (int i = next[0]; i != 0; i = next[i]) {
            printf("%c", input[i]);
        }
        printf("\n");
    } 

    return 0;
}
