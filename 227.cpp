/*
 * =====================================================================================
 *
 *       Filename:  227.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/04/2014 09:22:23
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

const int kMaxN = 1024;

char matrix[5][8];
char input[kMaxN];

int main() {
#ifdef Debug
	freopen("227.in", "r", stdin);
#endif
	int x = -1, y = -1;
	int cases = 0;
	int len;
	while (1) {
		fgets(matrix[0], 8, stdin);
		len = strlen(matrix[0]);
		matrix[0][len-1] = '\0';
		if (strcmp(matrix[0], "Z") == 0)
			break;

		fgets(matrix[1], 8, stdin);
		fgets(matrix[2], 8, stdin);
		fgets(matrix[3], 8, stdin);
		fgets(matrix[4], 8, stdin);
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (matrix[i][j] == ' ') {
					x = j;
					y = i;
					break;
				}
			}
		}

		if (cases)
			printf("\n");

		/*
		printf("%s\n", matrix[0]);
		printf("%s\n", matrix[1]);
		printf("%s\n", matrix[2]);
		printf("%s\n", matrix[3]);
		printf("%s\n", matrix[4]);
		printf("x:%d y:%d\n", x, y);
  */

		int cur = 0;
		bool invalid = false;
		fgets(input, kMaxN, stdin);
		while (1) {
			len = strlen(input);
			if (input[cur] == '0')
				break;
			if (cur == len) {
				fgets(input, kMaxN, stdin);
				cur = 0;
				continue;
			}
			if (invalid || !isalpha(input[cur])) {
				++cur;
				continue;
			}
			int move_x = x, move_y = y;
			switch (input[cur]) {
				case 'A':
					move_y = y - 1;
					break;
				case 'B':
					move_y = y + 1;
					break;
				case 'R':
					move_x = x + 1;
					break;
				case 'L':
					move_x = x - 1;
					break;
				default:
					move_x = move_y = -1;
					break;
			}
			if (move_x < 0 || move_x > 4 || move_y < 0 || move_y > 4) {
				invalid = true;
			} else {
				matrix[y][x] = matrix[move_y][move_x];
				matrix[move_y][move_x] = ' ';
				x = move_x;
				y = move_y;
			}
			++cur;
		}

		printf("Puzzle #%d:\n", ++cases);
		if (invalid) {
			printf("This puzzle has no final configuration.\n");
		} else {
			for (int i = 0; i < 5; ++i) {
				printf("%c %c %c %c %c\n", matrix[i][0], matrix[i][1], matrix[i][2], matrix[i][3], matrix[i][4]);
			}
		}
	}
	return 0;
}

