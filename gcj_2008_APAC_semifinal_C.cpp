#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXM 16

int main() {
	freopen("gcj_2008_APAC_semifinal_C.in", "r", stdin);
	int N, M, X;
	double P;
	scanf("%d", &N);
	double dp[2][(1<<MAXM)+1];
	double *current = dp[0];
	double *bak = dp[1];
	for (int i = 0; i < N; ++i) {
		scanf("%d%lf%d", &M, &P, &X);
		int n = 1 << M;
		memset(current, 0, sizeof(double)*(n+1));
		current[n] = 1.0;
		for (int r = 0; r < M; ++r) {
			for (int j = 0; j <= n; ++j) {
				int k_upper_bound = std::min(j, n-j);
				double t = 0.0;
				for (int k = 0; k <= k_upper_bound; ++k) {
					t = std::max(t, P*current[j+k]+(1-P)*current[j-k]);
				}
				bak[j] = t;
			}
			std::swap(current, bak);
		}
		int c = (long long)X*n/1000000;
		printf("Case #%d: %.6f\n", i+1, current[c]);
	}
	return 0;
}
