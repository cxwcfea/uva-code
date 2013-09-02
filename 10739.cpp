#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define MAXN 1002

char input[MAXN];

int d[MAXN][MAXN];

int is_palindrome(int start, int len) {
	for (int i = 0; i < len/2; ++i) {
		if (input[start+i] != input[start+len-1-i])
			return 0;
	}
	return 1;
}

int dp(int start, int len) {
	int &ans = d[start][len];
	if (ans > 0) return ans;
	if (is_palindrome(start, len)) {
		ans = 0;
	} else {
		if (input[start] == input[start+len-1]) {
			ans = dp(start+1, len-2);
		} else {
			ans = dp(start, len-1)+1;
			ans = min(ans, dp(start+1, len-1)+1);
			ans = min(ans, dp(start+1, len-2)+1);
		}
	}
	return ans;
}

int main() {
#ifdef Debug
	freopen("10739.in", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; ++i) {
		scanf("%s", input);
		memset(d, 0, sizeof(d));
		printf("Case %d: %d\n", i+1, dp(0, strlen(input)));
	}
	return 0;
}
