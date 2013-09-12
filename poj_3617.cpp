#include<cstdio>

#define MAXN 2002

int N;
char letters[MAXN];
char result[MAXN];

int main() {
#ifdef Debug
	freopen("poj_3617.in", "r", stdin);
#endif
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		getchar();
		scanf("%c", &letters[i]);
	}
	int left = 0, right = N-1, j = 1;
	while (left <= right) {
		if (letters[left] < letters[right]) {
			result[j++] = letters[left++];
		} else if (letters[left] > letters[right]) {
			result[j++] = letters[right--];
		} else {
			int l = left+1, r = right-1;
			while (l <= r && letters[l] == letters[r]) {
				++l, --r;
			}
			if (l > r) {
				result[j++] = letters[left++];
			} else if (letters[l] < letters[r]) {
				result[j++] = letters[left++];
			} else {
				result[j++] = letters[right--];
			}
		}
	}
	for (int i = 1; i < j; ++i) {
		printf("%c", result[i]);
		if ((i%80) == 0) printf("\n");
	}
	printf("\n");
	return 0;
}
