#include <cstdio>
#include <cstring>
#include <algorithm>

int N, S;
int B[11];
bool done;

bool check(int *A, int n) {
	if (n == 1) {
		if (A[0] == S)
			return true;
		else
			return false;
	}
	int subset[11];
	for (int i = 0; i < n-1; ++i) {
		subset[i] = A[i]+A[i+1];
	}
	return check(subset, n-1);
}

void test_subset(int cur) {
	if (cur == N) {
		int subset[11];
		for (int i = 0; i < cur; ++i) {
			subset[i] = B[i];
		}
		do {
			if (check(subset, N)) {
				for (int i = 0; i < N; ++i) {
					printf("%d ", subset[i]);
				}
				printf("\n");
				done = true;
				break;
			}
		} while (std::next_permutation(subset, subset+N));
		return;
	}
	int s = cur ? B[cur-1]+1 : 1;
	for (int i = s; i <= 10; ++i) {
		if (done) return;
		B[cur] = i;
		test_subset(cur+1);
	}
}

int main() {
#ifdef Debug
	freopen("poj_3187.in", "r", stdin);
#endif
	scanf("%d%d", &N, &S);
	done = false;
	test_subset(0);
	return 0;
}
