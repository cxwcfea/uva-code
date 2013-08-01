#include<cstdio>
#include<cstring>
#include<ctime>

#define MAXN 90
#define LEN 15

char input[MAXN];
int value[LEN]; 
int vis[LEN];
int max_value;

int resolve(int n) {
	int v, i, j;
	for (i = max_value; ; ++i) {
		memset(vis, 0, sizeof(vis));
		for (j = 0; j < n; ++j) {
			v = (i/value[j])%n;
			if (vis[v]) break;
			vis[v] = 1;
		}
		if (j == n) {
			return i;
		}
	}
}

int main() {
#ifdef Debug
	freopen("188.in", "r", stdin);
#endif
	memset(value, 0, sizeof(value));
	char *p;
	int v, i, result; 
	max_value = 0;
	while (fgets(input, MAXN, stdin)) {
		p = input;
		v = 0;
		i = 0;
		while ((*p) != '\0' && (*p) != '\n') {
			if ((*p) == ' ') {
				if (v > 0) {
					value[i++] = v;
					if (v > max_value) max_value = v;
					v = 0;
				}
				++p;
			} else {
				v = v*32 + ((*p)-'a')+1;
				++p;
			}
		}
		if (v > 0) {
			value[i++] = v;
			if (v > max_value) max_value = v;
		}
		result = resolve(i);
		printf("%s", input);
		printf("%d\n\n", result);
	}
#ifdef Debug
	printf("time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}
