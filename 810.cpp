/*
 * =====================================================================================
 *
 *       Filename:  810.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/06/2014 17:06:35
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

const int kMax = 30;

int row, col, sr, sc, die_top, face_value;
char name[kMax];
int maze[kMax][kMax];
bool vis[kMax][kMax][8][8];
deque<pair<int, int>> path;
bool win;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void DebugOut() {
    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

pair<int, int> getNewDie(int dt, int fv, int dir) {
    switch (dir) {
        case 0:
            if (dt == 6) {
                return make_pair(fv, 1);
            }
            if (dt == 5) {
                return make_pair(fv, 2);
            }
            if (dt == 4) {
                return make_pair(fv, 3);
            }
            if (dt == 3) {
                return make_pair(fv, 4);
            }
            if (dt == 2) {
                return make_pair(fv, 5);
            }
            if (dt == 1) {
                return make_pair(fv, 6);
            }
            break;
        case 1:
            if (fv == 6) {
                if (dt == 2)
                    return make_pair(4, fv);
                if (dt == 4)
                    return make_pair(5, fv);
                if (dt == 5)
                    return make_pair(3, fv);
                if (dt == 3)
                    return make_pair(2, fv);
            }
            if (fv == 5) {
                if (dt == 3)
                    return make_pair(6, fv);
                if (dt == 6)
                    return make_pair(4, fv);
                if (dt == 4)
                    return make_pair(1, fv);
                if (dt == 1)
                    return make_pair(3, fv);
            }
            if (fv == 4) {
                if (dt == 6)
                    return make_pair(2, fv);
                if (dt == 2)
                    return make_pair(1, fv);
                if (dt == 1)
                    return make_pair(5, fv);
                if (dt == 5)
                    return make_pair(6, fv);
            }
            if (fv == 3) {
                if (dt == 6)
                    return make_pair(5, fv);
                if (dt == 5)
                    return make_pair(1, fv);
                if (dt == 1)
                    return make_pair(2, fv);
                if (dt == 2)
                    return make_pair(6, fv);
            }
            if (fv == 2) {
                if (dt == 6)
                    return make_pair(3, fv);
                if (dt == 3)
                    return make_pair(1, fv);
                if (dt == 1)
                    return make_pair(4, fv);
                if (dt == 4)
                    return make_pair(6, fv);
            }
            if (fv == 1) {
                if (dt == 4)
                    return make_pair(2, fv);
                if (dt == 2)
                    return make_pair(3, fv);
                if (dt == 3)
                    return make_pair(5, fv);
                if (dt == 5)
                    return make_pair(4, fv);
            }
            break;
        case 2:
            if (fv == 6) {
                return make_pair(1, dt);
            }
            if (fv == 5) {
                return make_pair(2, dt);
            }
            if (fv == 4) {
                return make_pair(3, dt);
            }
            if (fv == 3) {
                return make_pair(4, dt);
            }
            if (fv == 2) {
                return make_pair(5, dt);
            }
            if (fv == 1) {
                return make_pair(6, dt);
            }
            break;
        case 3:
            if (fv == 6) {
                if (dt == 4)
                    return make_pair(2, fv);
                if (dt == 2)
                    return make_pair(3, fv);
                if (dt == 3)
                    return make_pair(5, fv);
                if (dt == 5)
                    return make_pair(4, fv);
            }
            if (fv == 5) {
                if (dt == 6)
                    return make_pair(3, fv);
                if (dt == 3)
                    return make_pair(1, fv);
                if (dt == 1)
                    return make_pair(4, fv);
                if (dt == 4)
                    return make_pair(6, fv);
            }
            if (fv == 4) {
                if (dt == 6)
                    return make_pair(5, fv);
                if (dt == 5)
                    return make_pair(1, fv);
                if (dt == 1)
                    return make_pair(2, fv);
                if (dt == 2)
                    return make_pair(6, fv);
            }
            if (fv == 3) {
                if (dt == 6)
                    return make_pair(2, fv);
                if (dt == 2)
                    return make_pair(1, fv);
                if (dt == 1)
                    return make_pair(5, fv);
                if (dt == 5)
                    return make_pair(6, fv);
            }
            if (fv == 2) {
                if (dt == 3)
                    return make_pair(6, fv);
                if (dt == 6)
                    return make_pair(4, fv);
                if (dt == 4)
                    return make_pair(1, fv);
                if (dt == 1)
                    return make_pair(3, fv);
            }
            if (fv == 1) {
                if (dt == 2)
                    return make_pair(4, fv);
                if (dt == 4)
                    return make_pair(5, fv);
                if (dt == 5)
                    return make_pair(3, fv);
                if (dt == 3)
                    return make_pair(2, fv);
            }
            break;
    }
    return make_pair(-1, -1); // should never happen
}

void dfs(int r, int c, int dt, int fv) {
    if (r == sr && c == sc && !path.empty()) {
        win = true;
        return;
    }
    //printf("r %d c %d\n", r, c);
    vis[r][c][dt][fv] = true;
    path.push_back(make_pair(r, c));
    for (int i = 0; i < 4; ++i) {
        if (win) break;
        int rn = r + dr[i];
        int cn = c + dc[i];
        if (rn <= 0 || rn > row || cn <= 0 || cn > col || maze[rn][cn] == 0) continue;
        auto die = getNewDie(dt, fv, i);
        if ((!vis[rn][cn][die.first][die.second] || (rn == sr && cn == sc)) && (dt == maze[rn][cn] || maze[rn][cn] == -1)) {
            //printf("will try r %d c %d, after move die top %d face value %d\n", rn, cn, die.first, die.second);
            dfs(rn, cn, die.first, die.second);
        }
    }
    if (!win)
        path.pop_back();
}

void Solve() {
    //DebugOut();
    memset(vis, 0, sizeof(vis));
    path.clear();
    win = false;
    dfs(sr, sc, die_top, face_value);
    printf("%s\n", name);
    int cnt = 0;
    if (win) {
        printf("  (%d,%d)", sr, sc);
        path.pop_front();
        ++cnt;
        while (!path.empty()) {
            auto value = path.front();
            path.pop_front();
            if (cnt == 9) {
                printf(",\n  (%d,%d)", value.first, value.second);
                cnt = 0;
            } else {
                printf(",(%d,%d)", value.first, value.second);
            }
            ++cnt;
        }
        if (cnt == 9)
            printf(",\n  (%d,%d)\n", sr, sc);
        else
            printf(",(%d,%d)\n", sr, sc);
    } else {
        printf("  No Solution Possible\n");
    }
}

int main() {
#ifdef Debug
    freopen("810.in", "r", stdin);
#endif
    while (true) {
        scanf("%s", name);
        if (!strcmp(name, "END")) break;
        scanf("%d %d %d %d %d %d", &row, &col, &sr, &sc, &die_top, &face_value);
        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j) {
                scanf("%d", &maze[i][j]);
            }
        }
        Solve();
    }
    return 0;
}
