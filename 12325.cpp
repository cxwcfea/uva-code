/*
 * =====================================================================================
 *
 *       Filename:  12325.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/03/2014 14:36:06
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
#include <string>
#include <utility>
#include <algorithm>

int main() {
#ifdef Debug
	freopen("12325.in", "r", stdin);
#endif
	int T, N, S1, V1, S2, V2, cases = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%d%d", &N, &S1, &V1, &S2, &V2);
		long long ans = 0;
		if (S2 < S1) {
			std::swap(S1, S2);
			std::swap(V1, V2);
		}
		if (N / S2 >= 65536) {
			for (long long i = 0; i <= S2; ++i) {
				ans = std::max(ans, V1 * i + (N - S1 * i) / S2 * V2);
			}
			for (long long i = 0; i <= S1; ++i) {
				ans = std::max(ans, V2 * i + (N - S2 * i) / S1 * V1);
			}
		} else {
			for (long long i = 0; i * S2 <= N; ++i) {
				ans = std::max(ans, V2 * i + (N - S2 * i) / S1 * V1);
			}
		}
		printf("Case #%d: %lld\n", ++cases, ans); 
	}
	return 0;
}

