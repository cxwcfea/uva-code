#include<cstdio>
#include<cstring>
#include<algorithm>
#include<utility>

typedef std::pair<int, int> P;

P objects[1001];
int person[101];
int N, G;

int d[1001][32];

int dp(int i, int w) {
	int &ans = d[i][w];
	if (ans > 0) return ans;
	if (i == N) {
		ans = 0;
	} else {
		ans = dp(i+1, w);
		if (w >= objects[i].second) {
			ans = std::max(dp(i+1, w-objects[i].second)+objects[i].first, ans);
		}
	}
	return ans;
}

int main() {
#ifdef Debug
	freopen("10130.in", "r", stdin);
#endif
	int cases, j, k, maxV;
	scanf("%d", &cases);	
	for (int i = 0; i < cases; ++i) {
		scanf("%d", &N);
		for (j = 0; j < N; ++j) {
			scanf("%d%d", &objects[j].first, &objects[j].second);
		}
		scanf("%d", &G);
		memset(d, 0, sizeof(d));
		maxV = 0;
		for (k = 0; k < G; ++k) {
			scanf("%d", &person[k]);
			maxV += dp(0, person[k]);;
		}
		printf("%d\n", maxV);
	}
	return 0;
}
