#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define MAXN 103

int n, r, c;
int grid[MAXN][MAXN];
char name[MAXN];
int d[MAXN][MAXN];

int dp(int row, int col) {
	int &ans = d[row][col];
	if (ans >= 0) return ans;
	if (!row || !col || row == r+1 || col == c+1) 
		ans = 0;	
	else {
		ans = 1;
		if (grid[row][col] > grid[row-1][col])
			ans = max(ans, dp(row-1, col)+1);
		if (grid[row][col] > grid[row][col+1])
			ans = max(ans, dp(row, col+1)+1);
		if (grid[row][col] > grid[row+1][col])
			ans = max(ans, dp(row+1, col)+1);
		if (grid[row][col] > grid[row][col-1])
			ans = max(ans, dp(row, col-1)+1);
	}
	return ans;
}

int main() {
#ifdef Debug
	freopen("10285.in", "r", stdin);
#endif
	int max_len, temp;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; ++i) {
		memset(grid, 0, sizeof(grid));
		max_len = 0;
		scanf("%s%d%d", name, &r, &c);
		for (int j = 1; j <= r; ++j)
			for (int k = 1; k <= c; ++k)
				scanf("%d", &grid[j][k]);
		memset(d, -1, sizeof(d));
		for (int j = 1; j <= r; ++j)
			for (int k = 1; k <= c; ++k) {
				temp = dp(j, k);
				if (temp > max_len) max_len = temp;	
			}
		printf("%s: %d\n", name, max_len);
	}
	return 0;
}
