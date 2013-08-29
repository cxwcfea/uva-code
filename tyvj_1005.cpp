#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define MAXM 101
#define MAXN 1001

int T, M;
int t, v;
int d[MAXM][MAXN];

int main() {
#ifdef Debug
	freopen("tyvj_1005.in", "r", stdin);
#endif
	int j;
	scanf("%d%d", &T, &M);
	memset(d[0], 0, sizeof(d[0]));
	for (int i = 1; i <= M; ++i) {
		scanf("%d%d", &t, &v);
		for (j = 0; j <= T; ++j) {
			d[i][j] = d[i-1][j];
			if (j >= t)
				d[i][j] = max(d[i][j], d[i-1][j-t]+v);
		}
	}
	printf("%d\n", d[M][T]);
	return 0;
}
