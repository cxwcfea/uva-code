#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

#define MAXN 9

int v1[MAXN], v2[MAXN];

int main() {
	freopen("gcj_2008_R1AA.in", "r", stdin);
	int T, n;
	scanf("%d", &T);
	int index[MAXN];
	int result;
	for (int i = 0; i < T; ++i) {
		result = INT_MAX;
		scanf("%d", &n);
		for (int j = 0; j < n; ++j) {
			scanf("%d", &v1[j]);
		}
		for (int j = 0; j < n; ++j) {
			scanf("%d", &v2[j]);
		}
		for (int j = 0; j < n; ++j) {
			index[j] = j;
		}
		do {
			int temp = 0;
			for (int j = 0; j < n; ++j) {
				temp += v1[j] * v2[index[j]];	
			}
			if (temp < result) {
				result = temp;
			}
		} while (next_permutation(index, index+n));
		printf("Case #%d: %d\n", i+1, result);
	}
	return 0;
}
