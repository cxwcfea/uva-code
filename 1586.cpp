/*
 * =====================================================================================
 *
 *       Filename:  1586.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/01/2014 11:08:41
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
#include <cctype>

const int MAXN = 90;
int data[4];
char input[MAXN];

int getIndex(char c) {
	switch (c) {
		case 'C':
			return 0;
		case 'H':
			return 1;
		case 'O':
			return 2;
		default:
			return 3;
	}
}

int main() {
#ifdef Debug
	freopen("1586.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", input);
		memset(data, 0, sizeof data);
		int len = strlen(input);
		int index = getIndex(input[0]);
		int count = 0;
		for (int i = 1; i < len; ++i) {
			if (isalpha(input[i])) {
				if (!count)
					count = 1;
				data[index] += count;
				index = getIndex(input[i]);
				count = 0;
			} else {
				int v = input[i]-'0';
				count = count * 10 + v;
			}	
		}
		if (!count)
			count = 1;
		data[index] += count;
		double sum = data[0] * 12.01 + data[1] * 1.008 + data[2] * 16.00 + data[3] * 14.01;
		printf("%.3f\n", sum);
	}
	return 0;
}
