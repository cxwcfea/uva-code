#include<cstdio>
#include<algorithm>

using namespace std;

#define MAXN 9
#define C_LEN 81

int digit[MAXN];
int max_score;

struct Combination {
	int score;
	int value;
	void init(int a, int b, int c) {
		value = a*100 + b*10 + c;
	}
};

Combination comb[C_LEN];

bool check() {
	if (!((digit[0] < digit[1]) && (digit[1] < digit[2]))) {
		return false;
	}
	if (!((digit[3] < digit[4]) && (digit[4] < digit[5]))) {
		return false;
	}
	if (!((digit[6] < digit[7]) && (digit[7] < digit[8]))) {
		return false;
	}
	return true;
}

void init() {
	for (int i = 1; i <= 9; ++i)
		digit[i-1] = i; 
}

bool check2() {
	
}

void generate_subset(int cur, int *b) {
	if (cur > 2) return;
	if (cur == 2) {

	}
}

int main() {
#ifdef Debug
	freopen("11218.in", "r", stdin);
#endif
	int n, a, b, c, s, ts, cases = 0;
	while (1) {
		scanf("%d", &n);
		if (!n) break;
		max_score = 0;
		init();
		for (int i = 0; i < n; ++i) {
			scanf("%d%d%d%d", &a, &b, &c, &s);
			comb[i].score = s;
			comb[i].init(a, b, c);
		}
		do {
			if (!check()) continue;
			a = digit[0]*100 + digit[1]*10 + digit[2];
			b = digit[3]*100 + digit[4]*10 + digit[5];
			c = digit[6]*100 + digit[7]*10 + digit[8];
			ts = s = 0;
			for (int i = 0; i < n; ++i) {
				if (comb[i].value == a || comb[i].value == b || comb[i].value == c) {
					++s;
					ts += comb[i].score;
				}
				if (s == 3) break;
			}
			if (s == 3) {
				if (ts > max_score) max_score = ts;
			}
		} while (next_permutation(digit, digit+MAXN));
		if (max_score > 0) {
			printf("Case %d: %d\n", ++cases, max_score);
		} else {
			printf("Case %d: -1\n", ++cases);
		}
	}
	return 0;
}
