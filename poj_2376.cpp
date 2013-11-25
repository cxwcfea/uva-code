#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

#define MAXN 25002

typedef pair<int, int> Interval;

Interval points[MAXN];

bool comp(const Interval &a, const Interval &b) {
	return a.first < b.first;
}

int main() {
#ifdef Debug
	freopen("poj_2376.in", "r", stdin);
#endif
	int N, T;
	scanf("%d%d", &N, &T);
	for (int i = 0; i < N; ++i) {
		scanf("%d%d", &points[i].first, &points[i].second);
	}
	sort(points, points+N);
	int start = 1;
	int len = 0;
	int result = 0;
	int selected_end = 0;
	for (int i = 0; i < N; ++i) {
		if (points[i].first > start) {
			if (!len) {
				result = -1;
				break;
			} else {
				++result;
				len = 0;
				if (selected_end >= T)
					break;
				start = selected_end + 1;
				selected_end = 0;
				if (points[i].first > start) {
					result = -1;
					break;
				}
			}
		}
		if (points[i].second < start) continue;
		int t = points[i].second - start + 1; 
		if (t > len) {
			len = t;
			selected_end = points[i].second;
		}
	}
	if (len > 0) {
		if (selected_end >= T)
			++result;
		else
			result = -1;
	}
	printf("%d\n", result);
	return 0;
}
