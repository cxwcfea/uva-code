/*
 * =====================================================================================
 *
 *       Filename:  1602.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/07/2014 15:00:06
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  cxwcfea(cxwcfea@163.com), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <set>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

const int kMax = 10;

struct Cell {
	int x, y;

	Cell(int x_, int y_) : x{x_}, y{y_} {}
	
	bool operator<(const Cell &rhs) const {
		return (x < rhs.x || (x == rhs.x && y < rhs.y));
	}
};

using Polyomino = set<Cell>;

int dx[] = {1, -1 , 0, 0};
int dy[] = {0, 0, 1, -1};
set<Polyomino> polys[kMax+1];
int ans[kMax+1][kMax+1][kMax+1];

Polyomino normalize(const Polyomino &p) {
	Polyomino p2;
	int minX = p.begin()->x, minY = p.begin()->y;
	for (auto &cell : p) {
		minX = min(cell.x, minX);
		minY = min(cell.y, minY);
	}
	for (auto &cell : p) {
		p2.emplace(cell.x - minX, cell.y - minY);
	}
	return p2;
}

Polyomino rotate(const Polyomino &p) {
	Polyomino p2;

	for (auto &cell : p) {
		p2.emplace(cell.y, -cell.x);
	}

	return normalize(p2);
}

Polyomino flip(const Polyomino &p) {
	Polyomino p2;

	for (auto &cell : p) {
		p2.emplace(cell.x, -cell.y);
	}
	
	return normalize(p2);
}

void check_polyomino(const Polyomino &p, const Cell &c) {
	Polyomino p2 = p;
	p2.insert(c);
	p2 = normalize(p2);

	int n = p2.size();
	for (int i = 0; i < 4; ++i) {
		if (polys[n].count(p2)) return;
		p2 = rotate(p2);
	}

	p2 = flip(p2);
	for (int i = 0; i < 4; ++i) {
		if (polys[n].count(p2)) return;
		p2 = rotate(p2);
	}

	polys[n].insert(p2);
}

void generate() {
	Polyomino p0;
	p0.emplace(0, 0);
	polys[1].insert(p0);
	
	for (int i = 2; i <= kMax; ++i) {
		for (auto &p : polys[i-1]) {
			for (auto &cell : p) {
				for (int dir = 0; dir < 4; ++dir) {
					Cell newc(cell.x+dx[dir], cell.y+dy[dir]);
					if (!p.count(newc)) {
						check_polyomino(p, newc);
					}
				}
			}
		}
	}

	for (int i = 1; i <= kMax; ++i) {
		set<Polyomino> poly = polys[i];
		for (int w = 1; w <= kMax; ++w) {
			for (int h = 1; h <= kMax; ++h) {
				int cnt = 0;
				for (auto &p : poly) {
					int maxX = 0;
					int maxY = 0;
					for (auto &cell : p) {
						maxX = max(cell.x, maxX);
						maxY = max(cell.y, maxY);
					}
					if (min(maxX, maxY) < min(w, h) && max(maxX, maxY) < max(w, h)) {
						++cnt;
					}
				}
				ans[i][w][h] = cnt;
			}
		}
	}	
}

int main() {
#ifdef Debug
	freopen("1602.in", "r", stdin);
#endif
	generate();

	int n, w, h;
	while (scanf("%d %d %d", &n, &w, &h) == 3) {
		printf("%d\n", ans[n][w][h]);
	}
	return 0;
}

