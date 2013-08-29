#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define MAXN 101
#define MAXS 10001

int n, s;
int v[MAXN];
int maxd[MAXS], mind[MAXS], vis[MAXS];

int dp_max(int value) {
	int &ans = maxd[value];
	if (ans != -1) return ans;
	ans = -1 << 30;
	for (int i = 0; i < n; ++i) {
		if (value >= v[i]) {
			ans = max(ans, dp_max(value-v[i])+1);
		}
	}
	return ans;
}

int dp_min(int value) {
	int &ans = mind[value];
	if (vis[value]) return ans;
	vis[value] = 1;
	ans = 1 << 30;
	for (int i = 0; i < n; ++i) {
		if (value >= v[i]) {
			ans = min(ans, dp_min(value-v[i])+1);
		}
	}
	return ans;
}

int main() {
#ifdef Debug
	freopen("tyvj_1214.in", "r", stdin);
#endif
	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &v[i]);
	}
	memset(vis, 0, sizeof(vis));
	memset(mind, 0, sizeof(mind));
	mind[0] = 0, vis[0] = 1;
	printf("%d\n", dp_min(s));
	memset(maxd, -1, sizeof(maxd));
	maxd[0] = 0;
	printf("%d\n", dp_max(s));
	return 0;
}
