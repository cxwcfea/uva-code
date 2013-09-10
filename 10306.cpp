#include<cstdio>
#include<cstring>
#include<utility>
#include<algorithm>

#define MAXN 43
#define MAXM 302
#define IMPOSSIBLE (1 << 30)
typedef std::pair<int, int> P;

int m;
P coins[MAXN];
int d[MAXM][MAXM];
int total;

int dp(int x, int y) {
	int &ans = d[x][y];
	if (ans != -1) return ans;
	ans = IMPOSSIBLE;
	int nx, ny, remain;
	for (int i = 0; i < m; ++i) {
		nx = x+coins[i].first;
		ny = y+coins[i].second;
		remain = total-nx*nx-ny*ny;
		if (remain == 0) {
			ans = 1;
		} else if (remain > 0) {
			ans = std::min(ans, dp(nx, ny)+1); 
		}	
	}
	return ans;
}

int main() {
#ifdef Debug
	freopen("10306.in", "r", stdin);
#endif
	int n, S, result;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &m, &S);
		total = S*S;
		for (int j = 0; j < m; ++j) {
			scanf("%d%d", &coins[j].first, &coins[j].second);
		}
		memset(d, -1, sizeof(d));
		result = dp(0, 0);
		if (result == IMPOSSIBLE)
			printf("not possible\n");
		else
			printf("%d\n", result);
	}
	return 0;
}
