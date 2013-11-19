#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int digits[10];
int B[10];
set<int> keys;
int subset1[10];
int subset2[10];
int result;

int getIntValue(int size, int *A) {
	int ret = 0;
	for (int i = 0; i < size; ++i) {
		ret = ret*10+A[i];
	}
	return ret;
}

int getMaxValue(int size, int *A) {
	int ret = 0;
	for (int i = size-1; i >= 0; --i) {
		ret = ret*10+A[i];
	}
	return ret;
}

int getMinValue(int size, int *A) {
	if (!A[0] && size > 1) {
		swap(A[0], A[1]);
	}
	return getIntValue(size, A);
}

void calculate(int size1, int size2) {
	int value1, value2;
	if (size1 != size2) {
		if (size1 > size2) {
			value1 = getMinValue(size1, subset1);
			value2 = getMaxValue(size2, subset2);
		} else {
			value1 = getMinValue(size2, subset2);
			value2 = getMaxValue(size1, subset1);
		}
		int t = value1-value2;
		if (result > t) {
			result = t;
		}
		return;
	}
	do {
		if (!subset1[0] && size1 > 1) continue;
		value1 = getIntValue(size1, subset1);
		sort(subset2, subset2+size2);
		do {
			if (!subset2[0] && size2 > 1) continue;
			value2 = getIntValue(size2, subset2);
			int t = abs(value1-value2);
			if (result > t) {
				result = t;
			}
		} while (next_permutation(subset2, subset2+size2));	
	} while (next_permutation(subset1, subset1+size1));	
}

void build_subset(int n, int cur) {
	if (cur == n) {
		int size1 = 0, size2 = 0;
		for (int i = 0; i < n; ++i) {
			if (B[i] == 1) {
				subset1[size1++] = digits[i];
			} else {
				subset2[size2++] = digits[i];
			}
		}
		if (((size1 == size2) || abs(size1-size2) == 1) && !keys.count(size1)) {
			if (size1 != size2) {
				keys.insert(size1);
				keys.insert(size2);
			}
			calculate(size1, size2); 
		}
		return;
	}
	B[cur] = 1;
	build_subset(n, cur+1);
	B[cur] = 0;
	build_subset(n, cur+1);
}

int main() {
#ifdef Debug
	freopen("poj_2718.in", "r", stdin);
#endif
	int T, n;
	char temp;
	scanf("%d", &T);
	getchar();
	for (int i = 0; i < T; ++i) {
		memset(B, -1, sizeof(B));
		n = 0;
		keys.clear();
		result = 999999999;
		while ((temp = getchar()) != '\n') {
			if (temp != ' ')
				digits[n++] = temp-'0';
		}
		build_subset(n, 0);	
		printf("%d\n", result);
	}
	return 0;
}
