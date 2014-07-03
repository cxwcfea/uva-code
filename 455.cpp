/*
 * =====================================================================================
 *
 *       Filename:  455.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/02/2014 22:01:18
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

const int kMaxN = 80;

char buf[kMaxN];

void solution1() {
	scanf("%s", buf);
	int len = strlen(buf);
	for (int i = 1; i <= len; ++i) {
		bool fail = false;
		if (len % i == 0) {
			int step = len / i;
			for (int j = 0; j < i; ++j) {
				for (int k = 1; k < step; ++k) {
					if (buf[j] != buf[j+i*k]) {
						fail = true;
						break;
					}
				}
				if (fail) break;
			}
			if (!fail) {
				printf("%d\n", i);
				break;
			}
		}
	}
}

/*
void solution2() {
	scanf("%s", buf);
	int len = strlen(buf);
	int left = 0;
	int result = 0;
	int last_same_pos = 0;
	for (int i = 1; i < len;) {
		if (buf[left] == buf[i]) {
			if (!result) {
				result = i;
				last_same_pos = i;
			}
			++left;
			++i;
		} else {
			if (result) {
				result = 0;
				left = 0;
				i = last_same_pos+1;
			} else {
				++i;
			}
		}
	}
	if (!result) result = len;
	printf("%d\n", result);
}
  */

int main() {
#ifdef Debug
	freopen("455.in", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	while (n--) {
		solution1();
		if (n) {
			printf("\n");
		}
	}
	return 0;
}
