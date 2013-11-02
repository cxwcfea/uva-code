#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

#define MAXN 5001
#define MAXE 200001
#define INF 26000000
typedef pair<int, int> pii;

int N, R;
int u[MAXE], v[MAXE], w[MAXE], next1[MAXE]; // u, v, w represents a line's begin point, end point, weight
int first[MAXN], dist[MAXN], dist2[MAXN];

int main() {
#ifdef Debug
	freopen("poj_3255.in", "r", stdin);
#endif
	priority_queue<int, vector<pii>, greater<pii> > que;
	scanf("%d%d", &N, &R);
	for (int i = 1; i <= N; ++i) {
		first[i] = -1;
		dist[i] = (i == 1) ? 0 : INF;
		dist2[i] = INF;
	}
	int R2 = 2 * R;
	for (int i = 0; i < R2; ++i) {
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
		u[i+1] = v[i];
		v[i+1] = u[i];
		w[i+1] = w[i];
		next1[i] = first[u[i]];
		first[u[i]] = i;
		++i;
		next1[i] = first[u[i]];
		first[u[i]] = i;
	}
	que.push(make_pair(dist[1], 1));
	while (!que.empty()) {
		pii c = que.top();
		que.pop();
		int x = c.second;
		int d = c.first;
		if (dist2[x] < d) continue;
		for (int e = first[x]; e != -1; e = next1[e]) {
			int d2 = d + w[e];
			if (dist[v[e]] > d2) {
				swap(dist[v[e]], d2);
				que.push(make_pair(dist[v[e]], v[e]));
			} 
			if (dist2[v[e]] > d2 && dist[v[e]] < d2) {
				dist2[v[e]] = d2; 
				que.push(pii(dist2[v[e]], v[e]));
			}
		}
	}
	printf("%d\n", dist2[N]);
	return 0;
}
