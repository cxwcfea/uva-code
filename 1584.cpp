/*
 * =====================================================================================
 *
 *       Filename:  1584.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/26/2014 22:05:47
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

const int MAXN = 105;

char data[MAXN];

bool isLess(int p, int q) {
	int len = strlen(data);
	for (int i = 0; i < len; ++i) {
		int l = (i+p)%len;
		int r = (i+q)%len;
		if (data[l] != data[r]) {
			return data[l] < data[r];
		}
	}
	return true;
}

int main() {
#ifdef Debug
	freopen("1584.in", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	while (n--) {
		scanf("%s", data);
		int len = strlen(data);
		int low = 0;
		for (int i = 0; i < len; ++i) {
			if (isLess(i, low)) {
				low = i;
			}	
		}
		for (int i = 0; i < len; ++i) {
			printf("%c", data[(i+low)%len]);
		}
		printf("\n");
	}
	return 0;
}
