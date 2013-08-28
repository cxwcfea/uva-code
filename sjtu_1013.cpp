#include<cstdio>
#include<cstring>

using namespace std;

#define MAXN 1000
#define MAXV 10000

int V, N;
int c[MAXN], w[MAXN], d[MAXV];

int main() {
#ifdef Debug
	freopen("sjtu.in", "r", stdin);
#endif
	scanf("%d%d", &V, &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d%d", &c[i], &w[i]);
	}
	memset(d, 0, sizeof(d));	
	for (int i = 1; i <= V; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i-c[j] >= 0 && d[i-c[j]]+w[j] > d[i]) d[i] = d[i-c[j]]+w[j];
		}
	}
	printf("%d\n", d[V]);
	return 0;
}
