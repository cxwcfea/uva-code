/*
 * =====================================================================================
 *
 *       Filename:  208.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/15/2014 14:11:06
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

const int kMax = 22;

int graph[kMax][kMax];
int dest, cnt;
int vis[kMax];
int reach_map[kMax];
int path[kMax];
int d[kMax][kMax];

void can_reach() {
	memcpy(d, graph, sizeof(graph));
	for (int k = 1; k < kMax; ++k) {
		for (int i = 1; i < kMax; ++i) {
			for (int j = 1; j < kMax; ++j) {
				d[i][j] = d[i][j] || (d[i][k] && d[k][j]);
			}
		}
	}
}

void dfs(int u, int depth) {
	path[depth] = u;
	if (u == dest) {
		++cnt;
		for (int i = 0; i < depth; ++i) {
			printf("%d ", path[i]);
		}
		printf("%d\n", path[depth]);
		return;	
	}
	for (int i = 2; i < kMax; ++i) {
		if (!vis[i] && graph[u][i] && d[i][dest]) {
			vis[i] = 1;
			dfs(i, depth+1);
			vis[i] = 0;
		}
	}
}

void resolve() {
	cnt = 0;
	can_reach();
	memset(vis, 0, sizeof(vis));
	vis[1] = 1;
	dfs(1, 0);
}

int main() {
#ifdef Debug
	freopen("208_1.in", "r", stdin);
#endif
	int cases = 0;
	while (scanf("%d", &dest) == 1) {
		memset(graph, 0, sizeof(graph));
		int u, v;
		while (scanf("%d %d", &u, &v) == 2 && u && v) {
			graph[u][v] = 1;
			graph[v][u] = 1;
		}
		printf("CASE %d:\n", ++cases);
		resolve();
		printf("There are %d routes from the firestation to streetcorner %d.\n", cnt, dest);
	}	
	return 0;
}

