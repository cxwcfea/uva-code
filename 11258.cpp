#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>

using namespace std;

#define MAXN 203

char digits[MAXN];
long long d[MAXN][MAXN];
long long v[MAXN][MAXN];

long long getInt(int i, int j) {
	long long &ans = v[i][j];
	if (ans != -1) return ans;
	char *p = digits+i;
	char *end = digits+j;
	ans = 0;
	while (p <= end) {	
		ans *= 10;
		ans += *p-'0';
		if (ans > INT_MAX) {
			ans = -2;
			break;
		}
		++p;
	}
	return ans;
}

long long dp(int i, int j) {
	long long &ans = d[i][j];
	if (ans != -1) {
		return ans;
	}
	ans = getInt(i, j);
	if (ans >= 0) return ans;
	ans = 0;
	for (int _i = i; _i < j; ++_i) {
		long long a = dp(i, _i);
		long long b = dp(_i+1, j);
		ans = max(ans, a+b); 
	}
	return ans;
}

int main() {
#ifdef Debug
	freopen("11258.in", "r", stdin);
#endif
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		getchar();
		scanf("%s", digits);
		memset(d, -1, sizeof(d));
		memset(v, -1, sizeof(v));
		printf("%lld\n", dp(0, strlen(digits)-1));
	}
	return 0;
}
