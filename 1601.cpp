/*
 * =====================================================================================
 *
 *       Filename:  1601.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/14/2014 11:16:42
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
#include <cctype>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

const int kMax = 20;

int start[3], target[3];
char maze[kMax][kMax];
int corridors[kMax*kMax][5];
int numCorridors;
int id[kMax][kMax];
int w, h, n;
int dx[] = {1, -1, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0};
int degree[kMax*kMax];
int d[kMax*kMax][kMax*kMax][kMax*kMax];

inline int ID(int a, int b, int c) {
    return (a << 16) | (b << 8) | c;
}

bool conflict(int a, int b, int a2, int b2) {
    return (a2 == b2 || (a == b2 && b == a2));
}

void bfs() {
    queue<int> que;
    que.push(ID(start[0], start[1], start[2]));
    d[start[0]][start[1]][start[2]] = 0;
    while (!que.empty()) {
        int u = que.front(); que.pop();
        int a = (u >> 16) & 0xff;
        int b = (u >> 8) & 0xff;
        int c = u & 0xff;
        if (a == target[0] && b == target[1] && c == target[2])
            return;
        for (int i = 0; i < degree[a]; ++i) {
            int a2 = corridors[a][i];
            for (int j = 0; j < degree[b]; ++j) {
                int b2 = corridors[b][j];
                if (conflict(a, b, a2, b2)) continue;
                for (int k = 0; k < degree[c]; ++k) {
                    int c2 = corridors[c][k];
                    if (conflict(a, c, a2, c2)) continue;
                    if (conflict(b, c, b2, c2)) continue;
                    if (d[a2][b2][c2] < 0) {
                        d[a2][b2][c2] = d[a][b][c] + 1;
                        que.push(ID(a2, b2, c2));
                    }
                }
            }
        }
    }
}

int main() {
#ifdef Debug
    freopen("1601.in", "r", stdin);
#endif
    while (scanf("%d%d%d\n", &w, &h, &n) == 3 && n) {
        for (int i = 0; i < h; ++i) {
            fgets(maze[i], kMax, stdin);
        }
        int x[400], y[400];
        numCorridors = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (maze[i][j] != '#') {
                    x[numCorridors] = i;
                    y[numCorridors] = j;
                    id[i][j] = numCorridors;
                    if (isupper(maze[i][j]))
                        target[maze[i][j]-'A'] = numCorridors;
                    else if (islower(maze[i][j]))
                        start[maze[i][j]-'a'] = numCorridors;
                    ++numCorridors;
                }
            }
        }
        for (int i = 0; i < numCorridors; ++i) {
            degree[i] = 0;
            for (int j = 0; j < 5; ++j) {
                int nx = x[i] + dx[j];
                int ny = y[i] + dy[j];
                if (maze[nx][ny] != '#') {
                    corridors[i][degree[i]++] = id[nx][ny];
                }
            }
        }

        if (n <= 2) {
            corridors[numCorridors][0] = start[2] = target[2] = numCorridors;
            degree[numCorridors++] = 1;
        }
        if (n <= 1) {
            corridors[numCorridors][0] = start[1] = target[1] = numCorridors;
            degree[numCorridors++] = 1;
        }
        memset(d, -1, sizeof(d));
        bfs();
        printf("%d\n", d[target[0]][target[1]][target[2]]);
    }
    return 0;
}
