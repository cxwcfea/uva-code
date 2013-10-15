#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

#define MAXN 10010
typedef pair<int, int> P;

P s[MAXN];

bool compare(const P &a, const P &b) {
	return b.first-a.first;
}

int compare1(const void *a, const void *b) {
	P *_a = (P*)a;
	P *_b = (P*)b;
	return _b->first - _a->first;
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
		scanf("%d%d", &(s[i].first), &(s[i].second));
	}
	scanf("%d%d",  &L, &P);
	//sort(s, s+17, compare);
	qsort(s, N, sizeof(P), compare1); 

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
				printf("%d\n", -1);
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
