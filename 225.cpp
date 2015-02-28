/*
 * =====================================================================================
 *
 *       Filename:  225.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/28/2014 15:50:58
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  cxwcfea(cxwcfea@163.com), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <utility>

const int kMaxN = 250; 
const int halfStep = 105;

int n, k;
int graph[kMaxN][kMaxN];
int sum[halfStep];
//  e n s w 
const int dir[4][2] = { {1, 0}, {0, 1}, {0, -1}, {-1, 0} };
const char dirSeq[5] = "ensw";

char path[kMaxN];
int num_of_result;

bool canMove(int curX, int curY, int d, int step) {
	for (int i = 1; i <= step; ++i) {
		curX += dir[d][0];
		curY += dir[d][1];
		if (abs(curX) > halfStep || abs(curY) > halfStep) continue;
		if (graph[curX+halfStep][curY+halfStep] == -1) return false;
	}

	if (abs(curX)+abs(curY) > sum[20]-sum[step]) return false;

	return true;
}


void dfs(int curX, int curY, int step, int curDIR) {
	if (step > n) {
		if (!curX && !curY) {
			printf("%s\n", path);
			++num_of_result;
		}
		return;
	}
	for (int i = 0; i < 4; ++i) {
		if (curDIR == i || curDIR + i == 3) continue;
		if (canMove(curX, curY, i, step)) {
			path[step-1] = dirSeq[i];
			int x = curX + dir[i][0] * step;
			int y = curY + dir[i][1] * step;
			if (graph[x+halfStep][y+halfStep]) continue; 
			graph[x+halfStep][y+halfStep] = 1;
			dfs(x, y, step+1, i);
			graph[x+halfStep][y+halfStep] = 0;
		}
	}
}

void solve() {
	num_of_result = 0;
	//  e n s w 
	dfs(0, 0, 1, -1);
}

int main() {
#ifdef Debug
	freopen("225.in", "r", stdin);
#endif
	sum[0] = 0;
	for (int i = 1; i < 25; ++i) {
		sum[i] = sum[i-1] + i;
	}
	int cases = 0;
	scanf("%d", &cases);
	while (cases--) {
		scanf("%d%d", &n, &k);	
		memset(graph, 0, sizeof(graph));
		int a, b;
		for (int i = 0; i < k; ++i) {
			scanf("%d%d", &a, &b);
			if (abs(a) > halfStep || abs(b) > halfStep) continue;
			graph[halfStep+a][halfStep+b] = -1;
		}
		solve();
		printf("Found %d golygon(s).\n\n", num_of_result);
	}
	return 0;
}
