#include <cstdio>
#include <algorithm>

#define MAXE 10002
#define MAXN 1001
#define INF 10000000

struct Edge {
	int from, to, cost;
};

Edge edge1[MAXE];
Edge edge2[MAXE];
int d[MAXN];

int main() {
#ifdef Debug
	freopen("poj_3169.in", "r", stdin);
#endif
	int N, ML, MD;
	scanf("%d%d%d", &N, &ML, &MD);
	int i, A, B, D;
	for (i = 0; i < ML; ++i) {
		scanf("%d%d%d", &A, &B, &D);
		edge1[i] = (Edge){A, B, D};	
	}
	for (i = 0; i < MD; ++i) {
		scanf("%d%d%d", &A, &B, &D);
		edge2[i] = (Edge){A, B, D};	
	}
	d[0] = 0;
	for (i = 1; i < N; ++i) {
		d[i] = INF;	
	}
	for (i = 0; i < N; ++i) {
		for (int i = 0; i < N-1; ++i) {
			if (d[i+1] < INF) d[i] = std::min(d[i], d[i+1]);
		}	
		for (int i = 0; i < ML; ++i) {
			if (d[edge1[i].from-1] < INF)
				d[edge1[i].to-1] = std::min(d[edge1[i].to-1], d[edge1[i].from-1]+edge1[i].cost);
		}	
		for (int i = 0; i < MD; ++i) {
			if (d[edge2[i].to-1] < INF)
				d[edge2[i].from-1] = std::min(d[edge2[i].from-1], d[edge2[i].to-1]-edge2[i].cost);
		}	
	}
	int ret = d[N-1];
	if (d[0] < 0) {
		ret = -1;
	} else if (ret == INF) {
		ret = -2;
	} 
	printf("%d\n", ret);
	return 0;
}
