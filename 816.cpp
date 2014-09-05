/*
 * =====================================================================================
 *
 *       Filename:  816.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/05/2014 10:47:36
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
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int kMax = 50;

struct Node {
    int row, col, dir;
    Node(int r = 0, int c = 0, int d = 0) : row(r), col(c), dir(d) {}
};

char name[kMax];
char input[kMax];
int r0, c0, r1, c1, r2, c2;
bool has_edge[10][10][4][3];
int d0;
int d[10][10][4];
Node p[10][10][4];

const char *dir = "NESW";
const char *turn = "FLR";

int dir_id(const char ch) { return strchr(dir, ch) - dir; }
int turn_id(const char ch) { return strchr(turn, ch) - turn; }

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

Node Move(Node u, int type) {
    int dir = u.dir;
    if (type == 1) {
        dir = (u.dir + 3) % 4; 
    } else if (type == 2) {
        dir = (u.dir + 1) % 4;
    }
    return Node(u.row + dr[dir], u.col + dc[dir], dir); 
}

bool Valid(Node &n) {
    if (n.row <= 0 || n.row > 9 || n.col <= 0 || n.col > 9) return false;
    return true;
}

void PrintSolution(Node dest) {
    vector<Node> path;
    while (true) {
        path.push_back(dest);
        if (d[dest.row][dest.col][dest.dir] == 0) break;
        dest = p[dest.row][dest.col][dest.dir];
    }
    path.push_back(Node(r0, c0));
    int cnt = 0;
    for (vector<Node>::reverse_iterator iter = path.rbegin(); iter != path.rend(); ++iter) {
        if (cnt++ % 10 == 0)
            printf(" ");
        printf(" (%d,%d)", iter->row, iter->col);
        if (cnt % 10 == 0)
            printf("\n");
    }
    if (path.size() % 10 != 0)
        printf("\n");
}

void Solve() {
    printf("%s\n", name);
    memset(d, -1, sizeof(d));
    Node root(r1, c1, d0);
    queue<Node> que;
    que.push(root);
    d[r1][c1][d0] = 0;
    while (!que.empty()) {
        Node cur = que.front();
        //printf("current in (%d %d) from %c\n", cur.row, cur.col, dir[cur.dir]);
        que.pop();
        if (cur.row == r2 && cur.col == c2) {
            PrintSolution(cur);
            return;
        }
        for (int i = 0; i < 3; ++i) {
            //printf("try to turn %c ", turn[i]);  
            if (has_edge[cur.row][cur.col][cur.dir][i]) {
                //printf("successful\n");
                Node next = Move(cur, i);
                //printf("will goto (%d %d) dir %c\n", next.row, next.col, dir[next.dir]);
                if (Valid(next) && d[next.row][next.col][next.dir] < 0) {
                    //printf("valid\n");
                    d[next.row][next.col][next.dir] = d[cur.row][cur.col][cur.dir] + 1;
                    que.push(next);
                    p[next.row][next.col][next.dir] = cur;
                }
            }
        }
    }
    printf("  No Solution Possible\n");
}

int main() {
#ifdef Debug
    freopen("816.in", "r", stdin);
#endif
    while (true) {
        scanf("%s", name);
        if (!strcmp(name, "END")) break;
        fgets(input, kMax, stdin);
        char start_d;
        scanf("%d %d %c %d %d", &r0, &c0, &start_d, &r2, &c2);
        d0 = dir_id(start_d);
        r1 = r0 + dr[d0];
        c1 = c0 + dc[d0];
        memset(has_edge, 0, sizeof(has_edge));
        while (true) {
            int r, c;
            scanf("%d", &r);
            if (!r) break;
            scanf("%d", &c);
            while (scanf("%s", input) == 1 && input[0] != '*') {
                int len = strlen(input);
                int d = dir_id(input[0]);
                int turn;
                for (int i = 1; i < len; ++i) {
                    turn = turn_id(input[i]);
                    has_edge[r][c][d][turn] = true;
                } 
            }
        }
        Solve();
    }  

    return 0;
}

