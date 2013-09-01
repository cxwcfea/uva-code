// d[i][j]  表示i种面值的货币，支付总额为j，可能的支付种数。
// w[i] = i*i*i
// d[i][j] = d[i-1][j] + d[i][j-w[i]]  (j >= w[i])  
// d[i][j] = d[i-1][j] (j < w[i])
// 边界值，d[1][i] = 1, d[i][0] = 1
#include<cstdio>
#include<cstring>

using namespace std;

#define MAXN 22
#define MAXV 10001

long long d[MAXN][MAXV];
int w[MAXN];

void solve() {
	memset(d, 0, sizeof(d));
	int i, j;
	for (i = 1; i < MAXN; ++i) {
		w[i] = i*i*i;
	}
	for (j = 0; j < MAXV; ++j)
		d[1][j] = 1;
	for (i = 1; i < MAXN; ++i)
		d[i][0] = 1;
	for (i = 2; i < MAXN; ++i) {
		for (j = 1; j < w[i]; ++j) {
			d[i][j] = d[i-1][j];
		}
		for (j = w[i]; j < MAXV; ++j) {
			d[i][j] = d[i-1][j] + d[i][j-w[i]];
		}
	}
}

int main() {
#ifdef Debug
	freopen("11137.in", "r", stdin);
#endif
	solve();
	int v;
	while (scanf("%d", &v) == 1) {
		printf("%lld\n", d[21][v]);
	}
	return 0;
}
