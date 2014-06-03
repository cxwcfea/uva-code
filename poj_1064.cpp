#include <cstdio>
#include <cmath>

#define MAXN 10002
#define INFINIT 10000002

double values[MAXN];

int main() {
#ifdef Debug
	freopen("poj_1064.in", "r", stdin);
#endif
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; ++i) {
		scanf("%lf", &values[i]);
	}
	int times = 100;
	double lb = 0, ub = INFINIT;
	while (times--) {
		double md = (lb + ub) / 2;
		int num = 0;
		for (int i = 0; i < N; ++i) {
			num += (int)(values[i] / md);
		}
		if (num >= K) {
			lb = md;
		} else {
			ub = md;
		}
	}
	printf("%.02f\n", floor(ub * 100) / 100);	
	return 0;
}

