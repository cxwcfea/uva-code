#include<cstdio>
#include<cstdlib>
#include<queue>
#include<algorithm>

using namespace std;

#define MAXN 10010
typedef pair<int, int> Pair;

Pair s[MAXN];

bool compare(const Pair &a, const Pair &b) {
	return b.first < a.first;
}

int main() {
#ifdef Debug
	freopen("poj_2431.in", "r", stdin);
#endif
	int N, L, P;
	scanf("%d", &N);

	++N;
	s[0].first = 0;
	s[0].second = 0;
	for (int i = 1; i < N; ++i) {
		scanf("%d%d", &s[i].first, &s[i].second);
	}
	scanf("%d%d",  &L, &P);
	sort(s, s+N, compare);

	priority_queue<int> que;
	int d, result = 0;
	for (int i = 0; i < N; ++i) {
		d = L - s[i].first;
		
		while (P < d) {
			if (!que.empty()) {
				P += que.top();
				que.pop();
				++result;
			} else {
				printf("-1\n");
				return 0;
			}
		}

		P -= d;
		L = s[i].first;
		que.push(s[i].second);
	}
	printf("%d\n", result);

	return 0;
}
