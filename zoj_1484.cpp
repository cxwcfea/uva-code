#include<cstdio>
#include<climits>

#define MAXN 5001

int data[MAXN];
int temp[MAXN];
int helper[MAXN];
int ans;
int min_inverse;

void count_inverse(int x, int y) {
	int m;
	if (y-x > 1) {
		m = x + (y-x)/2;
		count_inverse(x, m);
		count_inverse(m, y);
		int p = x, q = m, i = x;
		while (p < m || q < y) {
			if (q >= y || (p < m && temp[p] <= temp[q]))
				helper[i++] = temp[p++];
			else {
				helper[i++] = temp[q++];
				ans += m-p;
			}
		}
		for (i = x; i < y; ++i) {
			temp[i] = helper[i];
		}
	}
}

int main() {
#ifdef Debug
	freopen("zoj_1484.in", "r", stdin);
#endif
	int n, i, j, t;
	while (scanf("%d", &n) == 1)  {
		for (i = 0; i < n; ++i) {
			scanf("%d", &data[i]);
			temp[i] = data[i];
		}
		ans = 0;
		count_inverse(0, n);
		min_inverse = ans;
		for (i = 0; i < n; ++i) {
			ans = ans - data[i] + n - data[i] - 1;
			if (ans < min_inverse) min_inverse = ans;
		}
		printf("%d\n", min_inverse);
	}
	return 0;
}
