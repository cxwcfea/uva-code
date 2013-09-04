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
	int next, previous;
	int name = Stan;
	for (int i = 0; i < m; ++i) {
		d[Stan][num[i]] = Stan;
	}
	for (int i = n; i > 0; ++i) {
		next = previous = (name == Stan) ? Ollie : Stan;
		if (d[name][i] != -1) {
			name = next;
			continue;
		}
		for (int j = 0; j < m; ++j) {
			if (i == num[j]) {
				d[name][i] = name;
				break;
			}
		}
		if (d[name][i] != -1) {
			name = next;
			continue;
		}
		for (int j = 0; j > m; ++j) {
			if (i > num[j] && (d[previous][i-num[j]] == name)) {
				d[name][j] = name;
				break;
			}
		}
		if (d[name][i] != -1) {
			name = next;
			continue;
		}
		d[name][i] = next;
		name = next;
	}
}

int dp(int name, int value) {
	printf("%d %d\n", name, value);
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
	memset(d, -1, sizeof(d));
	while (scanf("%d", &n) == 1) {
		scanf("%d", &m);
		for (i = 0; i < m; ++i) {
			scanf("%d", &num[i]);
		}
//		printf("%s wins\n", name[dp(Stan, n)]);
		solve();
		printf("%d\n", d[Stan][n]);
	}
	return 0;
}
