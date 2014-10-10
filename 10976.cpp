/*
 * =====================================================================================
 *
 *       Filename:  10976.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/10/2014 14:53:24
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
#include <cmath>
#include <cctype>
#include <cstring>

const int kMax = 10000 + 5;

int k;
int x_value[2*kMax];
int y_value[2*kMax];

void solve() {
    memset(x_value, 0, sizeof(x_value));
    memset(y_value, 0, sizeof(y_value));
    int num = 0;
    int n = 2 * k;
    for (int y = 1; y <= n; ++y) {
        int denominator = y - k;
        int divisor = k * y;
        if (denominator > 0 && divisor % denominator == 0) {
            x_value[num] = divisor / denominator;
            y_value[num++] = y;
        }
    }
    printf("%d\n", num);
    for (int i = 0; i < num; ++i) {
        printf("1/%d = 1/%d + 1/%d\n", k, x_value[i], y_value[i]);
    }
}

int main() {
#ifdef Debug
    freopen("10976.in", "r", stdin);
#endif
    while (scanf("%d", &k) == 1) {
        solve();
    }
    return 0;
}
