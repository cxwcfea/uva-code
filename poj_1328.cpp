#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

#define MAXN 1001

struct Point {
	double x, y, radar_x;
};

Point points[MAXN];

void get_radar_x(Point &a, int d) {
	a.radar_x = a.x + sqrt(d*d-a.y*a.y);
}

bool comp(const Point &a, const Point &b) {
	return a.radar_x < b.radar_x;
}

bool is_cover(const Point &x, double c, double d) {
	double a = x.x-c;
	return a*a + x.y*x.y <= d*d;
}

int main() {
#ifdef Debug
	freopen("poj_1328.in", "r", stdin);
#endif
	int N, D, cases = 1;
	while (1) {
		scanf("%d%d", &N, &D);
		if (!N && !D) break;
		bool impossible = false;
		if (D <= 0) impossible = true;
		for (int i = 0; i < N; ++i) {
			scanf("%lf%lf", &points[i].x, &points[i].y);
			get_radar_x(points[i], D);
			if (points[i].y > D) impossible = true;
		}
		if (impossible) {
			printf("Case %d: %d\n", cases++, -1);
			continue;
		}
		sort(points, points+N, comp);
		double radar_x = points[0].radar_x;
		int result = 1;
		for (int i = 1; i < N; ++i) {
			if (!is_cover(points[i], radar_x, D)) {
				radar_x = points[i].radar_x;
				++result;
			}
		}
		printf("Case %d: %d\n", cases++, result);
	}
	return 0;
}
