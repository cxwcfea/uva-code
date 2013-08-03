#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MAXN 52
#define MAXHASH 1003

typedef int State[MAXN][MAXN]; 

State st[8*MAXN];
int head[MAXHASH];
int next[8*MAXN];
char input[MAXN];
int n;

int hash(State &s) {
	int v = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (s[i][j]) {
				v = v*10 + (i*n+j);
				v %= MAXHASH;
			}
		}
	}
	return v;
}

void try_to_insert(int s) {
	int h = hash(st[s]);
	int u = head[h];
	while (u) {
		u = next[u];
	}
	next[s] = head[h];
	head[h] = s;
}

bool test_value(int s) {
	int h = hash(st[s]);
	int u = head[h];
	while (u) {
		if (memcmp(st[u], st[s], sizeof(st[u])) == 0) return false;
		u = next[u];
	}
	return true;
}

int main() {
#ifdef Debug
	freopen("141.in", "r", stdin);
#endif
	int i, len, r, c, p, newr, newc, count, insert_i;
	char sign, *q;
	bool found;
	while (1) {
		scanf("%d", &n);
		if (!n) break;
		memset(st, 0, sizeof(st));
		memset(head, 0, sizeof(head));
		memset(next, 0, sizeof(next));
		len = 2*n;
		found = false;
		getchar();
		try_to_insert(8*MAXN-1);
		count = 1;
		int pre = 0; 
		for (i = 1; i <= len; ++i) {
			fgets(input, MAXN, stdin);
			r = atoi(input); 
			q = strchr(input, ' ');
			while (*q == ' ')
				++q;
			c = atoi(q);
			q = strchr(q, ' ');
			while (*q == ' ')
				++q;
			sign = *q;
			if (found) continue;
			insert_i = count;
			for (int k = 0; k < 4; ++k) {
				if (found) break;
				if (!k) {
					memcpy(st[count], st[pre], sizeof(st[count]));
					if (sign == '+') {
						st[count][r][c] = 1;
					} else {
						st[count][r][c] = 0;
					}
				}
				if (!k) pre = count;
				if (!test_value(count)) {
					if (i % 2) p = 2;
					else p = 1;
					printf("Player %d wins on move %d\n", p, i);
					found = true;
				}
				++count;
				if (k == 3) break;
				memcpy(st[count], st[count-1], sizeof(st[count]));
				for (int l = 1; l <= n; ++l) {
					for (int m = 1; m <= n; ++m) {
						st[count][m][n-l+1] = st[count-1][l][m];
					}
				}
			}
			if (!found) {
				for (int k = 0; k < 4; ++k)
					try_to_insert(insert_i+k);
			}
		}
		if (!found) printf("Draw\n");
	}
	return 0;
}
