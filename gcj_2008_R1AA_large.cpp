#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

#define MAXN 801

long long v1[MAXN], v2[MAXN];

int main() {
	freopen("gcj_2008_R1AA.in", "r", stdin);
	int T, n;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		long long result = 0;
		scanf("%d", &n);
		for (int j = 0; j < n; ++j) {
			scanf("%lld", &v1[j]);
		}
		for (int j = 0; j < n; ++j) {
			scanf("%lld", &v2[j]);
		}
		sort(v1, v1+n);
		sort(v2, v2+n);
		for (int j = 0; j < n; ++j) {
			result += v1[j]*v2[n-j-1];
		}
		printf("Case #%d: %lld\n", i+1, result);
	}
	return 0;
}
