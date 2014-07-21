/*
 * =====================================================================================
 *
 *       Filename:  133.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/10/2014 10:20:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  cxwcfea(cxwcfea@163.com), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cstring>

const int kMax = 25;

int peoples[kMax];

int N;

int go(int s, int d, int step) {
	while (step) {
		do {
			s = s+d;
			if (s > N) {
				s = s % N;
			}
			if (s < 1) {
				s = s + N;
			}
		} while (peoples[s] == 0);
		--step;
	}
	return s;
}

void printPeopel() {
	printf("\n");
	for (int i = 0; i <= N; ++i) {
		printf("%d ", peoples[i]);
	}
	printf("\n");
}

int main() {
#ifdef Debug
	freopen("133.in", "r", stdin);
#endif
	int k, m;
	while (scanf("%d%d%d", &N, &k, &m) == 3 && N != 0) {
		memset(peoples, 0, sizeof(peoples));
		for (int i = 1; i <= N; ++i) {
			peoples[i] = i;
		}
		int left = N;
		int v1 = 0;
		int v2 = N+1;
		while (left > 0) {
			if (left != N)
				printf(",");
			v1 = go(v1, 1, k);
			v2 = go(v2, -1, m);
			if (v1 != v2) {
				printf("%3d%3d", v1, v2);
				left -= 2;
			} else {
				printf("%3d", v1);
				--left;
			}
			peoples[v1] = 0;
			peoples[v2] = 0;
		}
		printf("\n");
	}
	return 0;
}
