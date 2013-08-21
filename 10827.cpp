// the harder version of uva 108, row and col should consider the circle, for row, copy the matrix NxN to 2NxN
// for col, use % operation
#include<cstdio>
#include<cstring>

#define MAXN 75 

int matrix[MAXN*2][MAXN];
int cache[MAXN][MAXN*2][MAXN];

int n;

int get_col(int i, int j, int col) {
	if (cache[i][j][col] != 0) return cache[i][j][col];
	int ret = 0;
	for (int k = i; k <= j; ++k) {
		ret += matrix[k][col];
	}
	cache[i][j][col] = ret;
	return ret;
}

int main() {
#ifdef Debug
	freopen("10827.in", "r", stdin);
#endif
	int cases, i, j, k, cur, max, cl;
	scanf("%d", &cases);
	for (int l = 0; l < cases; ++l) {
		max = -1280000;
		memset(cache, 0, sizeof(cache));
		scanf("%d", &n);
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				scanf("%d", &matrix[i][j]);
			}
		}
		for (i = 0; i < n; ++i) {
			memcpy(matrix[i+n], matrix[i], sizeof(int)*n);
		}
		for (i = 0; i < n; ++i) {
			for (j = i; j < i+n; ++j) {
				for (cl = 0; cl < n; ++cl) {
					cur = 0;
					for (k = 0; k < n; ++k) {
						cur += get_col(i, j, (cl+k)%n);
						if (cur > max) max = cur;
						if (cur < 0) cur = 0;
					}
				}
			}
		}
		printf("%d\n", max);
	}
	return 0;
}
