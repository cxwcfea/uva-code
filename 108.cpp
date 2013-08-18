#include<cstdio>

#define MAXN 100

int matrix[MAXN][MAXN];

int get_col(int i, int j, int col) {
	int ret = 0;
	for (int k = i; k <= j; ++k) {
		ret += matrix[k][col];
	}
	return ret;
}

int main() {
#ifdef Debug
	freopen("108.in", "r", stdin);
#endif
	int n, i, j, k, cur, max = -1280000;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			scanf("%d", &matrix[i][j]);
		}
	}
	for (i = 0; i < n; ++i) {
		for (j = i; j < n; ++j) {
			cur = 0;
			for (k = 0; k < n; ++k) {
				cur += get_col(i, j, k);
				if (cur > max) max = cur;
				if (cur < 0) cur = 0;
			}
		}
	}
	printf("%d\n", max);
	return 0;
}
