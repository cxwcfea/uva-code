#include<cstdio>
#include<cstdlib>

#define MAXN 100003

long long data[MAXN];

long long my_abs(long long v) {
	if (v >= 0) {
		return v;
	} else {
		return 0LL - v;
	}
}

int main() {
#ifdef Debug
	freopen("11054.in", "r", stdin);
#endif
	int n, i, j, k; // j -> seller index, k -> buyer index
	long long amount, move;
	while (1) {
		scanf("%d", &n);
		if (!n) break;
		for (i = 0; i < n; ++i) {
			scanf("%lld", &data[i]);
		}
		j = k = 0;
		move = 0LL;
		while (data[j] >= 0) ++j;
		while (data[k] <= 0) ++k;
		amount = my_abs(data[j]);
		while (j < n) {
			if (amount > data[k]) {
				amount -= data[k];
				move += (long long)abs(k-j) * data[k];
				++k;
				while (data[k] <= 0) ++k;
			} else {
				data[k] -= amount;	
				move += (long long)abs(k-j) * amount;
				++j;
				while (data[j] >= 0 && j < n) ++j;
				if (j == n) break;
				amount = my_abs(data[j]);
				while (data[k] <= 0) ++k;
			}
		}
		printf("%lld\n", move);
	}
	return 0;
}
