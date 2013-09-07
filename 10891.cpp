#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<algorithm>

using namespace std;

#define MAXN 102

int n;
int nums[MAXN];
int d[MAXN][MAXN];
int s[MAXN][MAXN];
int vis[MAXN][MAXN];
int vis2[MAXN][MAXN];

int sum_s(int i, int j) {
	if (vis[i][j]) return s[i][j];
	vis[i][j] = 1;
	s[i][j] = 0;
	for (int k = i; k <= j; ++k) {
		s[i][j] += nums[k];
	}
	return s[i][j];
}

int dp(int i, int j) {
	int &ans = d[i][j];
	if (vis2[i][j]) {
		return ans;
	}
	vis2[i][j] = 1;
	int temp;
	ans = sum_s(i, j);
	for (int k = i + 1; k <= j; ++k) {
		temp = sum_s(i, k-1);
		ans = max(ans, temp - dp(k, j));
	}
	for (int k = j - 1; k >= i; --k) {
		temp = sum_s(k+1, j);
		ans = max(ans, temp - dp(i, k));
	}
	return ans;
}

int main() {
#ifdef Debug
	freopen("10891.in", "r", stdin);
#endif
	int i;
	while (1) {
		scanf("%d", &n);
		if (!n) break;
		for (i = 0; i < n; ++i) {
			scanf("%d", &nums[i]);
		}
		memset(vis, 0, sizeof(vis));
		memset(vis2, 0, sizeof(vis2));
		printf("%d\n", dp(0, n-1));
	}
#ifdef Debug
	printf("time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}
