#include<cstdio>
#include<algorithm>

using namespace std;

#define MAXN 1001
#define TOTAL 500000

int nums[MAXN];
int sums[TOTAL];

int main() {
#ifdef Debug
	freopen("10487.in", "r", stdin);
#endif
	int n, m, i, j, k, temp, result, cases = 0;
	while (1) {
		scanf("%d", &n);
		if (!n) break;
		printf("Case %d:\n", ++cases);	
		j = 0;
		for (i = 0; i < n; ++i) {
			scanf("%d", &nums[i]);
			for (k = 0; k < i; ++k) {
				sums[j++] = nums[i] + nums[k];
			}
		}
		sort(sums, sums+j);
		scanf("%d", &m);
		for (i = 0; i < m; ++i) {
			scanf("%d", &temp);
			int *p = lower_bound(sums, sums+j, temp);
			if (p == sums+j) result = *(p-1);
			else {
				if (p == sums || ((*p)-temp) <= (temp-*(p-1))) result = *p;
				else result = *(p-1);
			}
			printf("Closest sum to %d is %d.\n", temp, result);	
		}
	}
	return 0;
}
