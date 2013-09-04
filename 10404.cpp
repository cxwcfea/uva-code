#include<cstdio>
#include<cstring>

#define MAXN 1000002
#define MAXM 12
#define Stan 0
#define Ollie 1

int num[MAXM];
int d[2][MAXN];
int n, m;
char name[2][6] = {"Stan", "Ollie"};

int solve() {
	for (int i = 0; i < m; ++i) {
		d[Stan][num[i]] = Stan;
		d[Ollie][num[i]] = Ollie;
	}
	for (int i = 1; i <= n; ++i) {
		if (d[Stan][i] != -1) {
			continue;
		}
		for (int j = 0; j < m; ++j) {
			if (i > num[j] && (d[Stan][i-num[j]] == Ollie)) {
				d[Stan][i] = Stan;
				d[Ollie][i] = Ollie;
			}
		}
		if (d[Stan][i] != -1) {
			continue;
		}
		d[Stan][i] = Ollie;
		d[Ollie][i] = Stan;
	}
}

// recursion way, algorithm is right, but num have 1, so when n big, 
// will got stack overflow error, should use iteration
int dp(int name, int value) {
	int &ans = d[name][value];
	if (ans != -1) return ans;
	for (int i = 0; i < m; ++i) {
		if (value == num[i]) {
			ans = name;
			return ans;
		}
	}
	int next = (name == Stan) ? Ollie : Stan;
	for (int i = 0; i < m; ++i) {
		if (value > num[i]) {
			if (dp(next, value-num[i]) == name) {
				ans = name;
				return ans;
			}
		}
	}
	ans = next;
	return ans;
}

int main() {
#ifdef Debug
	freopen("10404.in", "r", stdin);
#endif
	int i;
	while (scanf("%d", &n) == 1) {
		scanf("%d", &m);
		for (i = 0; i < m; ++i) {
			scanf("%d", &num[i]);
		}
		memset(d, -1, sizeof(d));
		solve();
		printf("%s wins\n", name[d[Stan][n]]);
	}
	return 0;
}
