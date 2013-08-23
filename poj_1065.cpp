#include<cstdio>
#include<cstdlib>

#define MAXN 5000

struct Stick {
	int length;
	int weight;
};

Stick s[MAXN];

int check_list[MAXN];

int compare(const void *a, const void *b) {
	Stick *_a = (Stick*)a;
	Stick *_b = (Stick*)b;
	if (_a->length == _b->length) {
		return _a->weight - _b->weight;
	}
	return _a->length - _b->length;
}

int main() {
#ifdef Debug
	freopen("poj_1065.in", "r", stdin);
#endif
	int n, j, k, T, check_list_i, cost, match;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		scanf("%d", &n);
		for (j = 0; j < n; ++j) {
			scanf("%d%d", &s[j].length, &s[j].weight);
		}	
		qsort(s, n, sizeof(Stick), compare);
		cost = check_list_i = 0;
		for (j = 0; j < n; ++j) {
			match = 0;
			for (k = 0; k < check_list_i; ++k) {
				if (s[j].weight >= check_list[k]) {
					match = 1;
					check_list[k] = s[j].weight;
					break;
				}
			}
			if (!match) {
				check_list[check_list_i++] = s[j].weight;
				++cost;
			}
		}
		printf("%d\n", cost);
		/*
		for (int j = 0; j < n; ++j) {
			printf("(%d %d) ", s[j].length, s[j].weight);
		}
		printf("\n");
		*/
	}
	return 0;
}
