#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define MAXN 200

struct Move {
	int from, to;
	int big, small;
};

bool compare(const Move &a, const Move &b) {
	return a.small < b.small;
}

Move move[MAXN];
int visit[MAXN];

int main() {
#ifdef Debug
	freopen("poj_1083.in", "r", stdin);
#endif
	int T, N, i, j, k, moves, big, small;
	scanf("%d", &T);
	for (i = 0; i < T; ++i) {
		scanf("%d", &N);
		for (j = 0; j < N; ++j) {
			scanf("%d%d", &move[j].from, &move[j].to);
			if (move[j].from % 2) {
				move[j].from = move[j].from/2 + 1;
			} else {
				move[j].from = move[j].from/2;
			}
			if (move[j].to % 2) {
				move[j].to = move[j].to/2 + 1;
			} else {
				move[j].to = move[j].to/2;
			}
			if (move[j].from > move[j].to) {
				move[j].big = move[j].from;
				move[j].small = move[j].to;
			} else {
				move[j].big = move[j].to;
				move[j].small = move[j].from;
			}
		}
		sort(move, move+N, compare);
		memset(visit, 0, sizeof(visit));
		moves = 0;
		for (j = 0; j < N; ++j) {
			if (visit[j]) 
				continue;
			visit[j] = 1;
			big = move[j].big;
			small = move[j].small;
			++moves;
			for (k = j+1; k < N; ++k) {
				if (visit[k])
					continue;
				if (move[k].big < small) {
					small = move[k].small;
					visit[k] = 1;
				} else if (move[k].small > big) {
					big = move[k].big;
					visit[k] = 1;
				}
			}
		}
		printf("%d\n", moves*10);
	}
	return 0;
}
