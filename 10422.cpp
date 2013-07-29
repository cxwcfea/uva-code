#include<cstdio>

#define MAXN 5
#define MAXSTATE 1000000

typedef int State[25];

int dir[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {-1, -2}};
State st[MAXSTATE], goal;
char input[8];

int main() {
#ifdef Debug
	freopen("10422.in", "r", stdin);
#endif
	int n, j, k;
	//goal = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, -1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (j = 0; j < MAXN; ++j) {
			scanf("%s", input);
			for (k = 0; k < MAXN; ++k) {
				if (input[k] != ' ') {
					st[1][j*5+k] = input[k]-'0';
				} else {
					st[1][j*5+k] = -1;
				}
			}		
		}
		for (j = 0; j < MAXN; ++j) {
			for (k = 0; k < MAXN; ++k) {
				printf("%d ", st[1][j*5+k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
