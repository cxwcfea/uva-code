/*
 * =====================================================================================
 *
 *       Filename:  11059.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/10/2014 14:14:36
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  cxwcfea(cxwcfea@163.com), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>

const int kMax = 20;

int N;

int nums[kMax];

void solve(int T) {
    long long max = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            long long ret = 1;
            for (int k = i; k < j; ++k) {
                ret *= nums[k];
            }
            if (ret > max) {
                max = ret;
            }
        }
    }
    printf("Case #%d: The maximum product is %lld.\n\n", T, max);
}

int main() {
#ifdef Debug
    freopen("11059.in", "r", stdin);
#endif
    int cases = 0;
    while (scanf("%d", &N) == 1) {
        //printf("%d\n", N);
        for (int i = 0; i < N; ++i) {
            scanf("%d", &nums[i]);
        }
        solve(++cases);
    }
    return 0;
}
