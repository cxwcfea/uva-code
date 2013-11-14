#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAXN 41

using namespace std;

int matrix[MAXN][MAXN];
int last1[MAXN];
char input[50];

int main() {
	freopen("gcj_2009_R2A.in", "r", stdin);
	int T, N;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		memset(last1, 0, sizeof(last1));
		int result = 0;
		scanf("%d", &N);	
		for (int j = 0; j < N; j++) {
			scanf("%s", input);
			for (int k = 0; k < N; ++k) {
				if (input[k] == '1') {
					last1[j] = k;
				}
			}
		}
		for (int j = 0; j < N; ++j) {
			for (int k = j; k < N; ++k) {
				if (last1[k] <= j) {
					for (int l = k; l > j; --l) {
						swap(last1[l], last1[l-1]);
						++result;
					}
					break;
				}
			}
		}
		printf("Case #%d: %d\n", i+1, result);
	}
	return 0;
}
