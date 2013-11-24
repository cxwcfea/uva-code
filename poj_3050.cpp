#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

int dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

vector<vector<int> > steps;
int grid[5][5];
set<int> result;

void get_subset() {
	for (int j1 = 0; j1 < 4; ++j1) {
		for (int j2 = 0; j2 < 4; ++j2) {
			for (int j3 = 0; j3 < 4; ++j3) {
				for (int j4 = 0; j4 < 4; ++j4) {
					for (int j5 = 0; j5 < 4; ++j5) {
						vector<int> v;
						v.reserve(5);
						v.push_back(j1);
						v.push_back(j2);
						v.push_back(j3);
						v.push_back(j4);
						v.push_back(j5);
						steps.push_back(v);
					}
				}
			}
		}
	}
}

void solve(int &x, int &y, vector<int> &move_step) {
	int _x = x;
	int _y = y;
	int ret = 0;
	ret = ret * 10 + grid[x][y];
	for (int i = 0; i < 5; ++i) {
		_x += dir[move_step[i]][0];
		_y += dir[move_step[i]][1];
		if (_x < 0 || _y < 0 || _x > 4 || _y > 4) {
			return;
		}
		ret = ret * 10 + grid[_x][_y];
	}
	result.insert(ret);
}

int main() {
#ifdef Debug
	freopen("poj_3050.in", "r", stdin);
#endif
	get_subset();

	for (int i = 0; i < 5; ++i) {
		scanf("%d%d%d%d%d", &grid[i][0], &grid[i][1], &grid[i][2], &grid[i][3], &grid[i][4]);
	}

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			for (int k = 0; k < steps.size(); ++k) {
				solve(i, j, steps[k]);	
			}
		}
	}

	printf("%d\n", result.size());
	return 0;
}
