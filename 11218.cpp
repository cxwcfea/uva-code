#include<cstdio>
#include<algorithm>

using namespace std;

#define MAXN 9
#define C_LEN 81

int max_score;
int b[MAXN];
int n;

struct Combination {
	int score;
	int a, b, c;
	void init(int _a, int _b, int _c) {
		a = _a;
		b = _b;
		c = _c;
	}
};

Combination comb[C_LEN];

bool check() {
	int temp[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	temp[comb[b[0]].a] = 1;
	temp[comb[b[0]].b] = 1;
	temp[comb[b[0]].c] = 1;
	temp[comb[b[1]].a] = 1;	
	temp[comb[b[1]].b] = 1;	
	temp[comb[b[1]].c] = 1;	
	temp[comb[b[2]].a] = 1;	
	temp[comb[b[2]].b] = 1;	
	temp[comb[b[2]].c] = 1;	
	for (int i = 1; i <= 9; ++i) {
		if (!temp[i]) return false;
	}
	return true;
}

void generate_subset(int cur) {
	int ts = 0;
	if (cur == 3) {
		if (check()) {
			ts = comb[b[0]].score + comb[b[1]].score + comb[b[2]].score;	
			if (ts > max_score) max_score = ts;
		}
		return;
	}
	int s = cur ? b[cur-1]+1 : 0;
	for (int i = s; i < n; ++i) {
		b[cur] = i;
		generate_subset(cur+1);
	}
}

int main() {
#ifdef Debug
	freopen("11218.in", "r", stdin);
#endif
	int a, b, c, s, ts, cases = 0;
	while (1) {
		scanf("%d", &n);
		if (!n) break;
		max_score = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d%d%d%d", &a, &b, &c, &s);
			comb[i].score = s;
			comb[i].init(a, b, c);
		}
		generate_subset(0);
		if (max_score > 0) {
			printf("Case %d: %d\n", ++cases, max_score);
		} else {
			printf("Case %d: -1\n", ++cases);
		}
	}
	return 0;
}
