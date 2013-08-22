#include<cstdio>
#include<algorithm>
#include<queue>
#include<functional>

using namespace std;

#define MAXN 5000

int main() {
#ifdef Debug
	freopen("10954.in", "r", stdin);
#endif
	int n, i, cost, data, a, b;
	priority_queue<int, vector<int>, greater<int> > que;
	while (1) {
		scanf("%d", &n);
		if (!n) break;
		for (i = 0; i < n; ++i) {
			scanf("%d", &data);
			que.push(data);
		}
		cost = 0;
		while (que.size() > 1) {
			a = que.top();
			que.pop();
			b = que.top();
			que.pop();			
			a += b;
			cost += a;
			que.push(a);
		}
		que.pop();
		printf("%d\n", cost);
	}
	return 0;
}
