#include <cstdio>
#include <climits>
#include <algorithm>

#define MAXN 105

int A[MAXN];
int d[MAXN][MAXN];

int main() {
	freopen("gcj_2009_R1C.in", "r", stdin);
	int N, P, Q;
	scanf("%d", &N);
	A[0] = 0;
	for (int i = 0; i < N; ++i) {
		scanf("%d%d", &P, &Q);
		for (int j = 0; j < Q; ++j) {
			d[j][j+1] = 0;
		}
		for (int j = 1; j <= Q; ++j) {
			scanf("%d", &A[j]);
		}
		A[Q+1] = P+1;
		Q += 2;
		for (int w = 2; w < Q; ++w) {
			for (int i = 0; i + w < Q; ++i) {
				int j = i+w;
				int t = INT_MAX;
				for (int k = i+1; k < j; ++k) {
					t = std::min(t, d[i][k]+d[k][j]);
				}
				d[i][j] = t + A[j]-A[i]-2;
			}
		}
		printf("Case #%d: %d\n", i+1, d[0][Q-1]);
	}	
	return 0;
}
