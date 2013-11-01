#include<cstdio>
#include<queue>

using namespace std;

#define MAXN 5002
#define INF 26000000
typedef pair<int, int> pii;

int N, R;
int first[MAXN], u[MAXN], v[MAXN], w[MAXN], next[MAXN]; // u, v, w represents a line's begin point, end point, weight
int s[MAXN], d[MAXN];

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
		s[i] = (i == 0) ? 0 : INF;
	}
	for (int i = 0; i < R; ++i) {
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
		next[i] = first[u[i]];
		first[u[i]] = i;
	}
	que.push(make_pair(s[0], 0));
	while (!que.empty()) {
		pii u = que.top();
		que.pop();
		int x = u.second;
		if (done[x]) continue;
		done[x] = true;
		for (int e = first[x]; e != -1; e = next[e]) {
			if (s[v[e]] > s[x] + w[e]) {
				d[v[e]] = s[v[e]];
				s[v[e]] = s[x] + w[e];
				que.push(make_pair(s[v[e]], v[e]);
			} else if (d[v[e]] > s[x] + w[e]) {
				d[v[e]] = s[x] + w[e];
			}
		}
	}
	return 0;
}
