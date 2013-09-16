#include<cstdio>
#include<algorithm>

using namespace std;

#define MAXN 1002

int p[MAXN];

int main() {
#ifdef Debug
	freopen("poj_3069.in", "r", stdin);
#endif
	int r, n, i, j, cur, left, mid, ans;
	while (1) {
		scanf("%d%d", &r, &n);
		if (r == -1 && n == -1) break;
		for (i = 0; i < n; ++i) {
			scanf("%d", &p[i]);
		}
		sort(p, p+n);
		left = n;
		cur = ans = 0;
		while (left > 0) {
			++ans;
			mid = p[cur] + r;
			while (left && p[cur] <= mid) {
				++cur;
				--left;
			}
			mid = p[cur-1]+r;
			while (left && p[cur] <= mid) {
				++cur;
				--left;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
