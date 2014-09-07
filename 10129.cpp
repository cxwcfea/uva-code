/*
 * =====================================================================================
 *
 *       Filename:  10129.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/07/2014 10:55:38
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
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

const int kMax = 1000 + 10;

int T, N;
struct Node {
    int in_d, out_d;
    bool valid;
    vector<int> adjacents;
    Node() : in_d(0), out_d(0) {}
    void init() {
        in_d = out_d = 0;
        adjacents.clear();
        valid = false;
    }
};
Node Graph[26];
char input[kMax];
bool vis[26];
set<int> nodes;
int connect_node;

void dfs(int n_id) {
    ++connect_node;
    vis[n_id] = true;
    for (auto &v : Graph[n_id].adjacents) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

bool Solve() {
    int start = -1, end = -1;
    for (int i = 0; i < 26; ++i) {
        Node &v = Graph[i];
        if (v.valid) {
            if (v.in_d != v.out_d) {
                if (v.in_d > v.out_d && (v.in_d - v.out_d) == 1) {
                    if (end >= 0)
                        return false;
                    end = i;
                } else if ((v.out_d - v.in_d) == 1) {
                    if (start >= 0)
                        return false;
                    start = i;
                } else {
                    return false;
                }
            }
        }
    }
    if (start < 0) {
        for (int i = 0; i < 26; ++i) {
            if (Graph[i].valid) {
                start = i;
                break;
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    connect_node = 0;
    dfs(start);
    if (connect_node == nodes.size()) 
        return true;
    else
        return false;
}

void DebugOut() {
    for (int i = 0; i < 26; ++i) {
        printf("%c (in:%d out:%d): ", i + 'a', Graph[i].in_d, Graph[i].out_d);
        for (auto &v : Graph[i].adjacents) {
            printf("%c ", v + 'a');
        }
        printf("\n");
    }
}

void init() {
    for (int i = 0; i < 26; ++i) {
        Graph[i].init();
    }
    nodes.clear();
}

int main() {
#ifdef Debug
    freopen("10129.in", "r", stdin);
#endif
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d\n", &N);  
        for (int i = 0; i < N; ++i) {
            scanf("%s", input);
            int begin = input[0] - 'a';
            int end = input[strlen(input)-1] - 'a';
            nodes.insert(begin);
            nodes.insert(end);
            Graph[begin].adjacents.push_back(end);
            Graph[begin].valid = true;
            Graph[end].valid = true;
            ++Graph[begin].out_d;
            ++Graph[end].in_d;
            //DebugOut();
        }
        //DebugOut();
        if (Solve())
            printf("Ordering is possible.\n");
        else
            printf("The door cannot be opened.\n");
    } 
    return 0;
}
