#include<cstdio>
#include<cstring>

#define MAXHASHSIZE 1000003
#define MAXN 1000000

int head[MAXHASHSIZE];
int next[MAXN];
int st[MAXN];

int hash(int v) {
	/*
	int s = 0;
	while (v) {
		s += v%10;
		v /= 10;
	}
	*/
	return v % MAXHASHSIZE;
}

bool try_to_insert(int v) {
	int h = hash(st[v]);
	int u = head[h];	
	while (u) {
		if (st[v] == st[u]) return false;
		u = next[u];
	}
	next[v] = head[h];
	head[h] = v;
	return true;
}

int resolve() {
	int s, t, p = 1, v;
	memset(head, 0, sizeof(head));
	memset(next, 0, sizeof(next));
	try_to_insert(p);
	while (1) {
		s = 0;
		v = st[p];
		while (v) {
			t = v%10;
			s += t*t;
			v /= 10; 
		}
		st[++p] = s;
		if (s == 1) return 1;
		if (!try_to_insert(p)) return 0;
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
		st[1] = value;
		if (resolve()) {
			printf("Case #%d: %d is a Happy number.\n", i+1, value);
		} else {
			printf("Case #%d: %d is an Unhappy number.\n", i+1, value);
		}
	}
	return 0;
}
