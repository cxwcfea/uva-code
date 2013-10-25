#include<cstdio>
#include<cstring>

#define MAXN 7490

int type[5] = {1, 5, 10, 25, 50};

int d[MAXN];

int main() {
#ifdef Debug
	freopen("674.in", "r", stdin);
#endif
	int n;
	memset(d, 0, sizeof(d));
	d[0] = 1;
	for (int i = 0; i < 5; ++i) {
		for (int j = 1; j <= MAXN; ++j) {
			if (j >= type[i]) {
				d[j] += d[j - type[i]];
			}
		}
	}
	while (scanf("%d", &n) == 1) {
		printf("%d\n", d[n]);
	}
	return 0;
}
