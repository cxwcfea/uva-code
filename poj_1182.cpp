#include<cstdio>

#define MAXN 3*50002

int parent[MAXN];
int rank[MAXN];

void init() {
	for (int i = 0; i < MAXN; ++i) {
		parent[i] = i;
		rank[i] = 0;
	}
}

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
	int x = find(a);
	int y = find(b);
	if (x == y) return;
	if (rank[x] < rank[y]) {
		parent[x] = y;
	} else {
		parent[y] = x;
		if (rank[x] == rank[y]) ++rank[x];
	}
}

bool same(int a, int b) {
	return find(a) == find(b);
}

int main() {
#ifdef Debug
	freopen("poj_1182.in", "r", stdin);
#endif
	int N, K, D, X, Y, ret = 0;
	init();
	scanf("%d%d", &N, &K);
	int index1, index2;
	for (int i = 0; i < K; ++i) {
		scanf("%d%d%d", &D, &X, &Y);	
		if (X > N || Y > N) {
			++ret;
			continue;
		}
		index1 = 3*X;
		index2 = 3*Y;
		if (D == 1) {
			if (same(index1, index2+1) || same(index1, index2+2)) {
				++ret;
				continue;
			}
			unite(index1, index2);
			unite(index1+1, index2+1);
			unite(index1+2, index2+2);	
		} else if (D == 2) {
			if (same(index1, index2) || same(index1, index2+2)) {
				++ret;
				continue;
			}
			unite(index1, index2+1);
			unite(index1+1, index2+2);
			unite(index1+2, index2);
		}
	}
	printf("%d\n", ret);
	return 0;
}
