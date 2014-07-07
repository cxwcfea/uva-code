/*
 * =====================================================================================
 *
 *       Filename:  1339.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/07/2014 17:08:03
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

const int kMax = 210;

char data[2][kMax];

int comp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int main() {
#ifdef Debug
	freopen("1339.in", "r", stdin);
#endif

	while (scanf("%s %s", data[0], data[1]) == 2) {
		int len = strlen(data[0]);
		int count[2][26];
		memset(count, 0, sizeof count);
		for (int i = 0; i < len; ++i) {
			++count[0][data[0][i]-'A'];
			++count[1][data[1][i]-'A'];
		}
		qsort(count[0], 26, sizeof(int), comp);
		qsort(count[1], 26, sizeof(int), comp);
		bool match = true;
		for (int i = 0; i < 26; ++i) {
			if (count[0][i] != count[1][i]) {
				match = false;
				break;
			}
		}
		if (match) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}

	return 0;
}
