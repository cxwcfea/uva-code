#include <cstdio>
#include <cstring>

#define MAXN 52
#define MAXHASH 1003

typedef int State[MAXN][MAXN]; 

State st[2*MAXN];
int head[MAXHASH];
int next[2*MAXN];

int hash(State &s) {
	//for (int i = 0;
}

int main() {
#ifdef Debug
	freopen("141.in", "r", stdin);
#endif
	int n, i, len, r, c;
	char sign;
	while (1) {
		scanf("%d", &n);
		if (!n) break;
		memset(st, 0, sizeof(st));
		memset(head, 0, sizeof(head));
		memset(next, 0, sizeof(next));
		len = 2*n;
		for (i = 1; i <= len; ++i) {
			scanf("%d%d%c", &r, &c, &sign);
			memcpy(st[i], st[i-1], sizeof(st[i]));
			if (sign == '+') {
				st[i][r][c] = 1;
			} else {
				st[i][r][c] = 0;
			}
		}
	}
	return 0;
}
