#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define MAXN 10

int digits[MAXN];
int result[MAXN*10];

int main() {
#ifdef Debug
	freopen("993.in", "r", stdin);
#endif
	int n, num, j;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num);
		if (num < 10) {
			printf("%d\n", num);
			continue;
		}
		memset(digits, 0, sizeof(digits));
		for (int k = 2; k < 10; ++k) {
			while ((num % k) == 0) {
				num /= k;
				++digits[k];
				if (!num) break;
			}
		}
		if (num != 1) {
			printf("-1\n");
			continue;
		}
		memset(result, 0, sizeof(result));
		j = 0;
		while (digits[3] > 1) {
			result[j++] = 9;
			digits[3] -= 2;	
		}
		while (digits[2] > 2) {
			result[j++] = 8;
			digits[2] -= 3;
		}
		while (digits[7] > 0) {
			result[j++] = 7;
			--digits[7];
		}
		while (digits[2] > 0 && digits[3] > 0) {
			result[j++] = 6;
			--digits[2];
			--digits[3];
		}
		while (digits[5] > 0) {
			result[j++] = 5;
			--digits[5];
		}
		while (digits[2] > 1) {
			result[j++] = 4;
			digits[2] -= 2;
		}
		if (digits[3] == 1) {
			result[j++] = 3;
		}
		if (digits[2] == 1) {
			result[j++] = 2;
		}
		for (int k = j-1; k >= 0; --k) {
			printf("%d", result[k]);
		}
		printf("\n");
	}
	return 0;
}
