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
int first[MAXN], d[MAXN], d2[MAXN];

int main() {
#ifdef Debug
	freopen("poj_3255.in", "r", stdin);
#endif
	int done[MAXN];
	memset(done, 0, sizeof(done));
	priority_queue<int, vector<pii>, greater<pii> > que;
	scanf("%d%d", &N, &R);
	for (int i = 0; i < N; ++i) {
		first[i] = -1;
		d[i] = (i == 0) ? 0 : INF;
		d2[i] = (i == 0) ? 0 : INF;
	}
	int R2 = 2*R;
	for (int i = 0; i < R2; ++i) {
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
		--u[i];
		--v[i];
		u[i+1] = v[i];
		v[i+1] = u[i];
		w[i+1] = w[i];
		next1[i] = first[u[i]];
		first[u[i]] = i;
		++i;
		next1[i] = first[u[i]];
		first[u[i]] = i;
	}
	que.push(make_pair(d[0], 0));
	while (!que.empty()) {
		pii c = que.top();
		que.pop();
		int x = c.second;
		if (done[x]) continue;
		done[x] = 1;
		for (int e = first[x]; e != -1; e = next1[e]) {
			int t = d[x] + w[e];
			if (d[v[e]] > t) {
				swap(d[v[e]], t);
				que.push(make_pair(d[v[e]], v[e]));
			} 
			if (d2[v[e]] > t && d[v[e]] < t) {
				d2[v[e]] = t; 
				que.push(pii(d2[v[e]], v[e]));
			}
		}
	}
	printf("%d\n", d2[N-1]);
	return 0;
}
