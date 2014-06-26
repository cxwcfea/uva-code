/*
 * =====================================================================================
 *
 *       Filename:  1583.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/26/2014 21:42:59
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  cxwcfea(cxwcfea@163.com), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cstring>

const int MAXN = 100000;

int ans[MAXN];

int main() {
#ifdef Debug
	freopen("1583.in", "r", stdin);
#endif
	memset(ans, 0, sizeof ans);
	for (int i = 1; i <= MAXN; ++i) {
		int x = i;
		int y = x;
		while (x) {
			y += x % 10;
			x /= 10;
		}
		if (ans[y] == 0 || i < ans[y]) {
			ans[y] = i;
		}
	}
	int n;
	scanf("%d", &n);
	while (n--) {
		int v;
		scanf("%d", &v);
		printf("%d\n", ans[v]);
	}
	return 0;
}
