/*
 * =====================================================================================
 *
 *       Filename:  1585.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/30/2014 20:27:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cstring>

const int MAXN = 85;
char buf[MAXN];

int main() {
#ifdef Debug
	freopen("1585.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", buf);
		int len = strlen(buf);
		int sum = 0;
		int base = 1;
		for (int i = 0; i < len; ++i) {
			if (buf[i] == 'O') {
				sum += base;
				++base;
			} else {
				base = 1;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
