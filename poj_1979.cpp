#include <cstdio>
#include <cstring>

#define MAXN 21

int W, H, result;
char matrix[MAXN][MAXN];
int dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

void dfs(int x, int y) {
	if (x >= W || y >= H || x < 0 || y < 0) return;
	if (matrix[y][x] == '.')  {
		++result;
		matrix[y][x] = 'x';
		for (int i = 0; i < 4; ++i) {
			dfs(x+dir[i][0], y+dir[i][1]);
		}
	}
}

int main() {
#ifdef Debug
	freopen("poj_1979.in", "r", stdin);
#endif
	int startX, startY;
	while (1) {
		scanf("%d%d", &W, &H);
		if (!W && !H) break;
		for (int h = 0; h < H; ++h) {
			getchar();
			for (int w = 0; w < W; ++w) {
				matrix[h][w] = getchar();
				if (matrix[h][w] == '@') {
					startX = w;
					startY = h;
				}
			}
		}
		result = 0;
		matrix[startY][startX] = '.';
		dfs(startX, startY);
		printf("%d\n", result);
	}
	return 0;
}
