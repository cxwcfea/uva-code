#include <cstdio>
#include <algorithm>

#define MAXN 20002
#define MAXR 50002

int par[MAXN], rank[MAXN];

struct Edge {
	int from, to, cost;
};

bool comp(const Edge &a, const Edge &b) {
	return a.cost < b.cost;
}

Edge edge[MAXR];

void initialize_set(int n) {
	for (int i = 0; i < n; ++i) {
		par[i] = i;
		rank[i] = 0;
	}	
}

int find(int x) {
	if (par[x] == x)
		return x;
	return par[x] = find(par[x]);
}

bool same(int a, int b) {
	return find(a) == find(b);
}

void unite(int a, int b) {
	int x = find(a);
	int y = find(b);
	if (x == y) return;
	if (rank[x] > rank[y]) {
		par[y] = x;
	} else {
		par[x] = y;
		if (rank[x] == rank[y]) ++rank[y];
	}
}

int main() {
#ifdef Debug
	freopen("poj_3723.in", "r", stdin);
#endif
	int cases;
	int N, M, R, n;	
	int x, y, v;
	scanf("%d", &cases);
	for (int i = 0; i < cases; ++i) {
		scanf("%d%d%d", &N, &M, &R);
		n = N+M;
		initialize_set(n+1);
		for (int j = 0; j < R; ++j) {
			scanf("%d%d%d", &x, &y, &v);
			int t = 10000-v;
			//edge[j] = {x, y+N, t};
			edge[j].from = x;
			edge[j].to = y+N;
			edge[j].cost = t;
		}
		std::sort(edge, edge+R, comp);
		int ret = 0;
		for (int k = 0; k < R; ++k) {
			if (!same(edge[k].to, edge[k].from)) {
				unite(edge[k].to, edge[k].from);
				ret += edge[k].cost;
			}
		}
		for (int k = 0; k < n; ++k) {
			if (!same(n, k)) {
				ret += 10000;
				unite(n, k);
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}
