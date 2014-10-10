/*
 * =====================================================================================
 *
 *       Filename:  725.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/10/2014 11:28:58
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

int N;

bool slots[10];

void solve() {
    bool possible = false;
    for (int i1 = 0; i1 <= 9; ++i1) {
        memset(slots, 0, sizeof(slots));
        slots[i1] = true;
        for (int i2 = 0; i2 <= 9; ++i2) {
            if (slots[i2]) continue;
            slots[i2] = true;
            for (int i3 = 0; i3 <= 9; ++i3) {
                if (slots[i3]) continue;
                slots[i3] = true;
                for (int i4 = 0; i4 <= 9; ++i4) {
                    if (slots[i4]) continue;
                    slots[i4] = true;
                    for (int i5 = 0; i5 <= 9; ++i5) {
                        if (slots[i5]) continue;
                        int value = i1 * 10000 + i2 * 1000 + i3 * 100 + i4 * 10 + i5; 
                        //printf("%d\n", value);
                        long long dividend = value * N;
                        if (dividend >= 100000) {
                            break;
                        }
                        long long temp = dividend;
                        bool ok = true;
                        bool slots2[10];
                        memcpy(slots2, slots, sizeof(slots2));
                        slots2[i5] = true;
                        while (temp) {
                            int v = temp % 10;
                            temp /= 10;
                            if (slots2[v]) {
                                ok = false;
                                break;
                            }
                            slots2[v] = true;
                        }
                        for (int i = 0; i < 10; ++i) {
                            if (!slots2[i]) {
                                ok = false;
                                break;
                            }
                        }
                        if (ok) {
                            possible = true;
                            printf("%lld / %d%d%d%d%d = %d\n", dividend, i1, i2, i3, i4, i5, N); 
                        }
                    }
                    slots[i4] = false;
                }
                slots[i3] = false;
            }
            slots[i2] = false;
        }
        slots[i1] = false;
    }
    if (!possible) {
        printf("There are no solutions for %d.\n", N);
    }
}

int main() {
#ifdef Debug
    freopen("725.in", "r", stdin);
#endif
    int cases = 0;
    while (scanf("%d", &N) == 1 && N) {
        if (cases) {
            printf("\n");
        }
        solve();
        ++cases;
    }
    return 0;
}

