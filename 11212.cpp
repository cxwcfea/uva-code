/*
 * =====================================================================================
 *
 *       Filename:  11212.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/16/2014 11:30:41
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
#include <algorithm>

using namespace std;

const int kMax = 15;

int n;
int numbers[kMax];

bool isSorted() {
	for (int i = 0; i < n-1; ++i) {
		if (numbers[i] >= numbers[i+1]) return false;
	}
	return true;
}

int reverseNum() {
	int cnt = 0;
	for (int i = 0; i < n-1; ++i) {
		if (numbers[i]+1 != numbers[i+1]) ++cnt;
	}
	if (numbers[n-1] != n) ++cnt;
	return cnt;
}

bool dfs(int d, int maxd) {
	if (3*d+reverseNum() > 3*maxd) return false;
	if (isSorted()) return true;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			int temp[kMax], old[kMax];

			int cur = 0;
			for (int k = 0; k < n; ++k) {
				if (k < i || k > j) temp[cur++] = numbers[k];
			}

			for (int k = 0; k < cur; ++k) {
				memcpy(old, numbers, sizeof(old));

				int cur2 = 0;
				for (int p = 0; p < k; ++p) numbers[cur2++] = temp[p];
				for (int p = i; p <= j; ++p) numbers[cur2++] = old[p];
				for (int p = k; p < cur; ++p) numbers[cur2++] = temp[p];

				if (dfs(d+1, maxd)) return true;

				memcpy(numbers, old, sizeof(numbers));
			}
		}
	}
	return false;
}

int main() {
#ifdef Debug
	freopen("11212.in", "r", stdin);
#endif
	int cases = 0;
	while (scanf("%d", &n) == 1 && n) {
		for (int i = 0; i < n; ++i) {
			scanf("%d", &numbers[i]);
		}
		for (int maxd = 0; maxd < 9; ++maxd) {
			if (dfs(0, maxd)) {
				printf("Case %d: %d\n", ++cases, maxd);
				break;
			}
		}
	}
	return 0;
}

