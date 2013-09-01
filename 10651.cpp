#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define MAXN (1 << 12)

int d[MAXN];

int get_ones(int t) {
	int ret = 0;
	for (int i = 1; i < 4096; i *= 2) {
		if (t & i) 
			++ret;
	}
	return ret;
}

int can_move(int t) {
	for (int i = 0; i < 12; ++i) {
		if (i > 1) {
			if (((1 << i) & t) && ((1 << i-1) & t) && !((1 << i-2) & t))
				return 1;
		}
		if (i < 10) {
			if (((1 << i) & t) && ((1 << i+1) & t) && !((1 << i+2) & t))
				return 1;
		}
	}
	return 0;
}

int dp(int n) {
	int &ans = d[n];
	unsigned int a, b, c;
	int temp;
	if (ans) return ans;
	ans = 100;
	if (can_move(n)) {
		for (int i = 0; i < 12; ++i) {
			if (i > 1) {
				a = 1 << i;
				b = 1 << i-1;
				c = 1 << i-2;
				if ((a & n) && (b & n) && !(c & n)) {
					a |= b;
					a = ~a;
					temp = n & a;
					temp |= c;
					ans = min(ans, dp(temp));
				}
			}
			if (i < 10) {
				a = 1 << i;
				b = 1 << i+1;
				c = 1 << i+2;
				if ((a & n) && (b & n) && !(c & n)) {
					a |= b;
					a = ~a;
					temp = n & a;
					temp |= c;
					ans = min(ans, dp(temp));
				}
			}
			
		}
	} else {
		ans = get_ones(n);
	}
	return ans;
}

char input[13];

int main() {
#ifdef Debug
	freopen("10651.in", "r", stdin);
#endif
	int i, j, cases, value; 
	memset(d, 0, sizeof(d));
	scanf("%d", &cases);
	getchar();
	for (i = 0; i < cases; ++i) {
		scanf("%s", input);
		value = 0;
		for (j = 0; j < 12; ++j) {
			if (input[j] == 'o') {
				value |= (1 << j);
			}
		}
		printf("%d\n", dp(value));
	}
	return 0;
}
