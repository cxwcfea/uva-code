#include<cstdio>

#define MAXN 103

char matrix[MAXN][MAXN];
int N, M;

int dir[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

void dfs(int i, int j) {
	for (int index = 0; index < 8; ++index) {
		int row = i+dir[index][0];
		int col = j+dir[index][1];
		if (matrix[row][col] == 'W') {
			matrix[row][col] = '.';
			dfs(row, col);
		}
	}	
}

int main() {
#ifdef Debug
	freopen("poj_2386.in", "r", stdin);
#endif
	scanf("%d%d", &N, &M);
	int ponds = 0;
	for (int i = 0; i <= N+1; ++i) {
		for (int j = 0; j <= M+1; ++j) {
			matrix[i][j] = '.';
		}
	}
	for (int i = 1; i <= N; ++i) {
		getchar();
		for (int j = 1; j <= M; ++j) {
			scanf("%c", &matrix[i][j]);
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (matrix[i][j] == 'W') {
				++ponds;
				matrix[i][j] = '.';
				dfs(i, j);
			}
		}
	}
	printf("%d\n", ponds);
	return 0;
}
