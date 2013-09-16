#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>

using namespace std;

#define MAXN 203

char digits[MAXN];
long long num[MAXN][MAXN];
long long d[MAXN];

int main() {
#ifdef Debug
	freopen("11258.in", "r", stdin);
#endif
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		getchar();
		scanf("%s", digits+1);
		memset(num, -1, sizeof(num));
		memset(d, 0, sizeof(d));
		int len = strlen(digits+1);
		for (int l = 1; l <= 10; ++l) {
			for (int i = 1, j = l; j <= len; ++i, ++j) {
				printf("i:%d j:%d\n", i, j);
				num[i][j] = 0;
				for (int k = i; k <= j; ++k) {
					num[i][j] = num[i][j]*10 + (digits[k]-'0');
				}
				if (num[i][j] > INT_MAX) {
					num[i][j] = 0;
				}
			}
		}
		for (int i = 1; i <= len; ++i) {
			for (int j = 1; j <= 10 && j <= i; ++j) {
				d[i] = max(d[i], d[i-j]+num[i-j+1][i]);
			}
		}
		printf("%lld\n", d[len]);
	}
	return 0;
}
