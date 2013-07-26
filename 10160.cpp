#include<cstdio>
#include<climits>
#include<cstring>
#include<ctime>

using namespace std;

#define MAXN 36
typedef unsigned long long LL;
LL edge[MAXN];
LL helper[MAXN];
LL target;
int total_nodes;

bool check_subset(LL state, int step, int cur, int len) {
	if (state == target) return true;
	if (step == len) return false;
	for (int i = cur; i <= total_nodes; ++i) {
		if ((state|edge[i]) == state) continue;
		if ((state|helper[i]) != target) return false;
		if (check_subset(state|edge[i], step+1, i+1, len)) return true;
	}
	return false;
}

int main() {
#ifdef Debug
	freopen("10160.in", "r", stdin);
#endif
	int m, i, a, b;
	while (1) {
		scanf("%d%d", &total_nodes, &m);	
		if (!total_nodes && !m) break;
		memset(edge, 0, sizeof(edge));
		memset(helper, 0, sizeof(helper));
		for (i = 1; i <= total_nodes; ++i) {
			edge[i] |= (LL(1) << (i-1));
		}
		for (i = 0; i < m; ++i) {
			scanf("%d%d", &a, &b);
			edge[a] |= (LL(1) << (b-1));
			edge[b] |= (LL(1) << (a-1));
		}
		target = (LL(1) << total_nodes) - 1;
		helper[total_nodes] = edge[total_nodes];
		for (i = total_nodes-1; i > 0; --i) {
			helper[i] = (edge[i] | helper[i+1]);
		}

		for (i = 1; i <= total_nodes; ++i) {
			if (check_subset(0, 0, 1, i)) {
				printf("%d\n", i);
				break;
			}
		}
	}
#ifdef Debug
	printf("time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}

