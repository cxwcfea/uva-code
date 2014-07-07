/*
 * =====================================================================================
 *
 *       Filename:  1368.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/05/2014 08:51:43
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

const int kMaxN = 1010;

int score[kMaxN][4];
char input[kMaxN];

int main() {
#ifdef Debug
	freopen("1368.in", "r", stdin);
#endif
	int cases, m, n;
	scanf("%d", &cases);
	while (cases--) {
		memset(score, 0, sizeof score);
		getchar();
		scanf("%d %d", &m, &n);
		getchar();
		for (int i = 0; i < m; ++i) {
			scanf("%s", input);
			for (int j = 0; j < n; ++j) {
				switch (input[j]) {
					case 'A':
						++score[j][0];
						break;
					case 'C':
						++score[j][1];
						break;
					case 'G':
						++score[j][2];
						break;
					case 'T':
						++score[j][3];
						break;
				}
			}
		}
		int distance = 0;
		for (int i = 0; i < n; ++i) {
			int max_same = 0, pos = -1;
			for (int j = 0; j < 4; ++j) {
				if (score[i][j] > max_same) {
					max_same = score[i][j];
					pos = j;
				}
			}
			//printf("for pos %d the max is %d\n", i, pos);
			distance += m - max_same;
			switch (pos) {
				case 0:
					printf("A");
					break;
				case 1:
					printf("C");
					break;
				case 2:
					printf("G");
					break;
				case 3:
					printf("T");
					break;
			}
		}
		printf("\n%d\n", distance);
	}
	return 0;
}

