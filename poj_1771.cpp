#include<cstdio>

#define MAXN 32

int floor[MAXN];
int stop[MAXN];
int times[MAXN];

int main() {
#ifdef Debug
	freopen("poj_1771.in", "r", stdin);
#endif
	int n, i, j, k;
	while (1) {
		scanf("%d", &n);
		if (!n) break;
		for (i = 0; i < n; ++i) {
			scanf("%d", &floor[i]);
		}
		j = 0;
		for (i = n-1; i >= 0; --i) {
			if (!j) {
				stop[j++] = floor[i];	
				times[i] = (floor[i]-1)*4;
			} else {
				if (stop[j-1] - floor[i] < 3) {
					stop[j++] = floor[i];
					times[i] = (floor[i]-1)*4;
					for (k = n-1; k > i; --k) {
						times[k] += 10;
					}
				} else {
					times[i] = 
				}
			}
		}
	}

	return 0;
}
