#include<cstdio>
#include<cstring>

#define MAXN 750 

int st[MAXN];

int resolve(int v) {
	int s, t;
	memset(st, 0, sizeof(st));
	while (1) {
		s = 0;
		while (v) {
			t = v%10;
			s += t*t;
			v /= 10; 
		}
		v = s;
		if (v == 1) return 1;
		if (st[v]) {
			return 0;
		} else {
			st[v] = 1;
		}
	}	
}

int main() {
#ifdef Debug
	freopen("10591.in", "r", stdin);
#endif
	int n, value;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &value);
		if (resolve(value)) {
			printf("Case #%d: %d is a Happy number.\n", i+1, value);
		} else {
			printf("Case #%d: %d is an Unhappy number.\n", i+1, value);
		}
	}
	return 0;
}
