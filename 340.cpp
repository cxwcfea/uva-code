/*
 * =====================================================================================
 *
 *       Filename:  340.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/25/2014 22:30:46
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  cxwcfea (cxwcfea@163.com), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>

const int MAXN = 1005;

int question[MAXN];
int answer[MAXN];

int main() {
#ifdef Debug
	freopen("340.in", "r", stdin);
#endif
	int cases = 0, n, i;
	while (scanf("%d", &n) == 1 && n) {
		printf("Game %d:\n", ++cases);
		for (i = 0; i < n; ++i) {
			scanf("%d", &question[i]);
		}
		while (1) {
			int A = 0, B = 0;
			for (i = 0; i < n; ++i) {
				scanf("%d", &answer[i]);
				if (question[i] == answer[i])
					++A;
			}
			if (answer[0] == 0) break;
			for (int j = 1; j <= 9; ++j) {
				int c1 = 0, c2 = 0;
				for (i = 0; i < n; ++i) {
					if (question[i] == j) {
						++c1;
					}
					if (answer[i] == j) {
						++c2;
					}
				}
				if (c1 > c2) {
					B += c2;
				} else {
					B += c1;
				}
			}
			printf("    (%d,%d)\n", A, B-A);
		}
	}
	return 0;
}
