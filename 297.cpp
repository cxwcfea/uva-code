/*
 * =====================================================================================
 *
 *       Filename:  297.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/31/2014 09:17:43
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

const int kMax = 32 + 3;
const int kLen = 3000;

int data[kMax][kMax];
char input[kLen];
int count;

void ProcessArea(int r, int c, int len, int &pos) {
    //printf("process area at (%d, %d), len:%d, node:%c \n", r, c, len, input[pos]);
    char ch = input[pos];
    ++pos;
    if (ch == 'p') {
        len /= 2;
        ProcessArea(r, c + len, len, pos);
        ProcessArea(r, c, len, pos);
        ProcessArea(r + len, c, len, pos);
        ProcessArea(r + len, c + len, len, pos);
    } else if (ch == 'f') {
        for (int i = r; i < r + len; ++i) {
            for (int j = c; j < c + len; ++j) {
                if (data[i][j] != 1) {
                    data[i][j] = 1;
                    ++count;
                }
            }
        }
    }
}

int main() {
#ifdef Debug
    freopen("297.in", "r", stdin);
#endif
    int N;
    scanf("%d\n", &N);
    while (N--) {
        count = 0;
        memset(data, 0, sizeof(data));
        int pos = 0;
        fgets(input, kLen, stdin);
        ProcessArea(0, 0, 32, pos);
        pos = 0;
        fgets(input, kLen, stdin);
        ProcessArea(0, 0, 32, pos);
        printf("There are %d black pixels.\n", count);
    }
    return 0;
}
