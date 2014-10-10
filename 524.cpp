/*
 * =====================================================================================
 *
 *       Filename:  524.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/10/2014 15:24:58
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
#include <cmath>
#include <cctype>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int n;
set<int> primes;
int values[18];

void permutation(int cur) {
    if (cur == n) {
        printf("%d", values[0]);
        for (int i = 1; i < n; ++i)
            printf(" %d", values[i]);
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (cur == 0 && i > 1) break;
        bool ok = true;
        for (int j = 0; j < cur; ++j) {
            if (values[j] == i) {
                ok = false;
                break;
            }
        }
        if (ok) {
            values[cur] = i;
            if (cur) {
                int temp = values[cur] + values[cur-1];
                if (!primes.count(temp)) {
                    continue; 
                }
            }
            if (cur == n-1) {
                int temp = values[cur] + values[0];
                if (!primes.count(temp)) {
                    continue; 
                }
            }
            permutation(cur+1);
        }
    } 
}

int main() {
#ifdef Debug
    freopen("524.in", "r", stdin);
#endif
    primes.insert(2);
    primes.insert(3);
    primes.insert(5);
    primes.insert(7);
    primes.insert(11);
    primes.insert(13);
    primes.insert(17);
    primes.insert(19);
    primes.insert(23);
    primes.insert(29);
    primes.insert(31);
    primes.insert(37);
    primes.insert(41);
    primes.insert(43);
    primes.insert(47);
    primes.insert(53);
    primes.insert(59);
    primes.insert(61);
    primes.insert(67);
    primes.insert(71);
    primes.insert(73);
    primes.insert(79);
    primes.insert(83);
    primes.insert(89);
    primes.insert(97);
    primes.insert(101);
    int cases = 0;
    while (scanf("%d", &n) == 1) {
        if (cases)
            printf("\n");
        printf("Case %d:\n", ++cases);
        permutation(0);
    }
    return 0;
}
