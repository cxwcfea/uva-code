/*
 * =====================================================================================
 *
 *       Filename:  1603.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/13/2014 15:45:06
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
#include <string>
#include <utility>
#include <algorithm>

const int kMaxSquareNum = 60; // 25+16+9+4+1 = 55;
const int kMaxMatchStickNum = 60; // 2 * 5 * (5 + 1);

int k, n, result;
int size[kMaxSquareNum];  // num of matchSticks in a square i
bool contains[kMaxSquareNum][kMaxMatchStickNum]; // whether square i contains matchStick j
int fullSize[kMaxSquareNum];  // num of matchSticks in a complete square i
int exists[kMaxMatchStickNum];
int square_id;

inline int row_matchStick_id(int x, int y) {
	return (2 * n + 1) * y + x;
}

inline int col_matchStick_id(int x, int y) {
	return (2 * n + 1) * y + n + x;
}

inline int num_of_matchStick() {
	return 2 * n * (n + 1);
}

void init() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < num_of_matchStick(); ++i) {
		exists[i] = 1;
	}
	int v;
	for (int i = 0; i < k; ++i) {
		scanf("%d", &v);
		exists[v-1] = 0;
	}
	square_id = 0;
	memset(contains, 0, sizeof(contains));
	for (int i = 1; i <= n; ++i) {
		for (int x = 0; x <= n - i; ++x) {
			for (int y = 0; y <= n - i; ++y) {
				fullSize[square_id] = 4 * i;
				size[square_id] = 0;
				for (int j = 0; j < i; ++j) {
					int up = row_matchStick_id(x+j, y);
					int down = row_matchStick_id(x+j, y+i);
					int left = col_matchStick_id(x, y+j);
					int right = col_matchStick_id(x+i, y+j);
					contains[square_id][up] = true;
					contains[square_id][down] = true;
					contains[square_id][left] = true;
					contains[square_id][right] = true;
					size[square_id] += exists[up] + exists[down] + exists[left] + exists[right];
				}	
				++square_id;
			}
		}
	}
}

int findCompleteSqure() {
	for (int i = 0; i < square_id; ++i) {
		if (size[i] == fullSize[i])
			return i;
	}
	return -1;
}

void dfs(int depth) {
	if (depth >= result) return;

	int s_id = findCompleteSqure();
	if (s_id == -1) {
		result = depth;
		return;
	}
	for (int i = 0; i < num_of_matchStick(); ++i) {
		if (contains[s_id][i]) {
			for (int j = 0; j < square_id; ++j) {
				if (contains[j][i]) {
					--size[j];
				}
			}
			dfs(depth+1);
			for (int j = 0; j < square_id; ++j) {
				if (contains[j][i]) {
					++size[j];
				}
			}
		}
	}
}

int main() {
#ifdef Debug
	freopen("1603.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T); 
	while (T--) {
		init();	
		result = n * n;
		dfs(0);
		printf("%d\n", result);
	}
	return 0;
}

