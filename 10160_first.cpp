#include<cstdio>
#include<climits>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<queue>

using namespace std;

#define MAXN 36
typedef unsigned long long LL;
int cities[MAXN];
int matrix[MAXN][MAXN];
int min_value;
int degree[MAXN];
int total_nodes;
LL edge[MAXN];
LL target;

void check_subset(int cur, int *index, int n, LL state) {
	LL current_state = 0;
	if (cur) {
		current_state = (state|edge[cities[index[cur-1]]]);	
		if ((current_state == target)) {
			if (min_value > cur) {
				min_value = cur;
			}
			return;
		}
	}

	int s = cur ? index[cur-1]+1 : 0;
	for (int i = s; i < n; ++i) {
		if (cur + 1 >= min_value) return;
		int ok = 1;
		if (current_state&(LL(1) << cities[i])) { 
			ok = 0;
			if (degree[cities[i]] > 2) {
				int value = 0;
				for (int j = 1; j <= total_nodes; ++j) {
					if (matrix[cities[i]][j] && !(current_state&(LL(1) << j))) {
						++value;
						if (value == 2) {
							ok = 1;
							break;
						}
					}
				}
			}
		}
		if ((current_state|edge[cities[i]]) == current_state) ok = 0;
		if (ok) {
			index[cur] = i;
			check_subset(cur+1, index, n, current_state);
		}
	}
}

void get_degree(int n) {
	int value; 
	for (int i = 1; i <= n; ++i) {
		value = 0;
		for (int j = 1; j <= n; ++j) {
			if (matrix[i][j]) {
				++value;
			}
		}
		degree[i] = value;
	}
}

int compare(const void *a, const void *b) {
	int _a = *((int*)a);
	int _b = *((int*)b);
	int d1 = degree[_a];
	int d2 = degree[_b];
	return d2 - d1;
}

int main() {
#ifdef Debug
	freopen("10160.in", "r", stdin);
#endif
	int index[MAXN];
	int m, i, j, a, b, result;
	while (1) {
		scanf("%d%d", &total_nodes, &m);	
		if (!total_nodes && !m) break;
		memset(matrix, 0, sizeof(matrix));
		memset(edge, 0, sizeof(edge));
		for (i = 0; i < m; ++i) {
			scanf("%d%d", &a, &b);
			edge[a] |= (LL(1) << b);
			edge[b] |= (LL(1) << a);
			matrix[a][b] = matrix[b][a] = 1;
		}
		get_degree(total_nodes);
		for (i = 1; i <= total_nodes; ++i) {
			edge[i] |= (LL(1) << i);
		}

		result = 0;
		int num_checked = 0;
		int visit[MAXN] = {0};
		queue<int> q;
		int current;
		while (num_checked != total_nodes) {
			min_value = MAXN;
			int temp = 0;
			for (i = 1; i <= total_nodes; ++i) {
				if (!visit[i]) {
					q.push(i);
					visit[i] = 1;	
					break;			
				}
			}
			while (!q.empty()) {
				current = q.front();
				q.pop();
				cities[temp++] = current;
				++num_checked;
				for (j = 1; j <= total_nodes; ++j) {
					if (matrix[current][j] && !visit[j]) {
						q.push(j);
						visit[j] = 1;	
					}
				}
			}
			target = 0;
			for (j = 0; j < temp; ++j) {
				target |= (LL(1) << cities[j]);
			}
			qsort(cities, temp, sizeof(int), compare);
			check_subset(0, index, temp, 0);	
			result += min_value;
		}

		printf("%d\n", result);
	}
#ifdef Debug
	printf("time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}

