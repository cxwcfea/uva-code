#include<cstdio>

int main() {
#ifdef Debug
	freopen("10718.in", "r", stdin);
#endif
	unsigned int n, l, u, max, temp;
	int i, j, m;
	while (scanf("%u%u%u", &n, &l, &u) == 3) {
		if (l == u) {
			printf("%u\n", l);
			continue;
		}
		max = 0;
		for (i = 0; i < 32; ++i) {
			if ((1u << i) > u) break;
		}
		for (m = 0; m < 32; ++m) {
			if ((1u << m) > l) break;
		}
		for (j = i-1; j >= 0; --j) {
			temp = 1u << j;
			if (!(temp & n)) {
				max |= temp;
			}
		}
		for (j = m-1; (j >= 0) && (max < l); --j) {
			temp = 1u << j;
			if (temp & l) {
				max |= temp;
			}
		}
		if (max > u) {
			unsigned int helper = 0;
			for (j = i-1; j >= 0; --j) {
				temp = 1u << j;
				if (((temp&max) && ((helper|temp) <= u)) || (helper|temp) <= l) {
					helper |= temp;
				}
			}
			max = helper;
		}
		printf("%u\n", max);
	}
	return 0;
}
