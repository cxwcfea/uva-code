/*
 * =====================================================================================
 *
 *       Filename:  1374.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/06/2014 16:08:06
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

const int kMax = 500;

int ans[kMax];
int n;

bool dfs(int d, int maxd) {
	if (ans[d] == n) return true;
	if (d == maxd) return false;

	int maxv = ans[d];
	for (int i = 0; i <= d; ++i)
		if (ans[i] > maxv) maxv = ans[i];

	if ((maxv << (maxd - d)) < n) return false;

	for (int i = d; i >= 0; --i) {
		ans[d+1] = ans[d] + ans[i];
		if (dfs(d+1, maxd)) return true;
		ans[d+1] = ans[d] - ans[i];
		if (dfs(d+1, maxd)) return true;
	}

	return false;
}

int main() {
#ifdef Debug
	freopen("1374.in", "r", stdin);
#endif
	while (scanf("%d", &n) == 1 && n) {
		ans[0] = 1;
		for (int maxd = 0; maxd < kMax; ++maxd) {
			if (dfs(0, maxd)) {
				printf("%d\n", maxd);
				break;
			}
		}
	}
	return 0;
}

