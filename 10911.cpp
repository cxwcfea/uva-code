#include<cstdio>
#include<cmath>
#include<algorithm>

#define MAXN 18
#define MAXS 1<<16

typedef std::pair<int, int> P;

P points[MAXN];
double d[MAXS];

double dist(P &p1, P &p2) {
	double a = p1.first-p2.first;
	double b = p1.second-p2.second;
	return sqrt(a*a+b*b);
}

int main() {
#ifdef Debug
	freopen("10911.in", "r", stdin);
#endif
	int n, i, j, S, c = 1, t;
	char name[22];
	while (1) {
		scanf("%d", &n);
		if (!n) break;
		n *= 2;
		for (i = 0; i < n; ++i) {
			getchar();
			scanf("%s%d%d", name, &points[i].first, &points[i].second);
		}
		t = 1<<n;
		d[0] = 0;
		for (S = 1; S < t; ++S) {
			d[S] = 10000000;
			for (i = 0; i < n; ++i) {
				if (S & 1<<i) break;
			}
			for (j = i+1; j < n; ++j) {
				if (S & 1<<j) {
					d[S] = std::min(d[S], d[S^(1<<i)^(1<<j)]+dist(points[i], points[j]));
				}
			}
		}
		printf("Case %d: %.2f\n", c++, d[t-1]); 
	}
	return 0;
}
