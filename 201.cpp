/*
 * =====================================================================================
 *
 *       Filename:  201.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/12/2014 15:02:36
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

const int kMax = 12;

int row[kMax][kMax][kMax];
int col[kMax][kMax][kMax];

int n;

void CheckRowConnect(int row_num, int start, int len) {
	if (start + len > n)
		return;
	if (row[row_num][start+1][len-1]) {
		if (row[row_num][start][1]) {
			row[row_num][start][len] = 1;
		}
	}
}

void CheckColConnect(int col_num, int start, int len) {
	if (col[col_num][start+1][len-1]) {
		if (col[col_num][start][1]) {
			col[col_num][start][len] = 1;
		}
	}
}

void CheckConnect() {
	for (int i = 1; i <= n; ++i) {
		for (int j = n; j > 0 ; --j) {
			for (int k = 2; k < n; ++k) {
				CheckRowConnect(i, j, k);
				CheckColConnect(j, i, k);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = n; j > 0 ; --j) {
			for (int k = 2; k < n; ++k) {
				CheckColConnect(i, j, k);
			}
		}
	}

	/*
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k < n; ++k) {
				printf("row:%d start:%d len:%d connect:%d\n", i, j, k, row[i][j][k]);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k < n; ++k) {
				printf("col:%d start:%d len:%d connect:%d\n", i, j, k, col[i][j][k]);
			}
		}
	}
  */
}

bool IsRect(int r, int c, int size) {
	if (r + size > n || c + size > n) {
		return false;
	}
	if (row[r][c][size] && row[r+size][c][size] && col[c][r][size] && col[c+size][r][size]) {
		return true;
	}
	return false;
}

int CheckRec(int size) {
	int ret = 0;
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < n; ++j) {
			if (IsRect(i, j, size)) {
				++ret;
			}
		}	
	}
	return ret;
}

int main() {
#ifdef Debug
	freopen("201.in", "r", stdin);
#endif
	
	int cases = 0;
	while (scanf("%d", &n) == 1) {
		//printf("%d\n", n);
		if (cases) {
			printf("\n");
			printf("**********************************\n");
			printf("\n");
		}
		printf("Problem #%d\n\n", ++cases);
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		int m;
		scanf("%d", &m);
		//printf("%d\n", m);
		getchar();
		char t;
		int a, b;
		for (int i = 0; i < m ; ++i) {
			scanf("%c %d %d", &t, &a, &b);
			//printf("%c %d %d\n", t, a, b);
			getchar();
			if (t == 'H') {
				row[a][b][1] = 1;
			} else if (t == 'V') {
				col[a][b][1] = 1;
			}
		}
		
		CheckConnect();
		bool found = false;
		for (int i = 1; i < n; ++i) {
			int num = CheckRec(i);
			if (num > 0) {
				found = true;
				printf("%d square (s) of size %d\n", num, i);
			}
		}
		if (!found) {
			printf("No completed squares can be found.\n");
		}
	}
	return 0;
}
