/*
 * =====================================================================================
 *
 *       Filename:  804.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/29/2014 14:58:26
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
#include <cctype>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

const int kMax = 100 + 3;

struct Transition {
    map<int,int> inputs;
    map<int,int> outputs; 
    void init() {
        inputs.clear();
        outputs.clear();
    }
};

int NP, NT, NF;
int places[kMax];
Transition transitions[kMax];

void DebugOut() {
    for (int i = 1; i <= NP; ++i) {
        printf("%d (%d) ", i, places[i]);
    }
    printf("\n");

    for (int i = 1; i <= NT; ++i) {
        for (auto &v : transitions[i].inputs) {
            printf("-%d(%d) ", v.first, v.second);
        }
        printf("\n");
        printf("\n");
        for (auto &v : transitions[i].outputs) {
            printf("%d(%d) ", v.first, v.second);
        }
        printf("\n");
        printf("\n");
    }
    printf("\n");
}

void Simulate(int n) {
    bool live = true;
    int loop_num = NF;
    while (loop_num--) {
        bool dead = true;
        for (int i = 1; i <= NT; ++i) {
            int valid = true;
            for (auto &v : transitions[i].inputs) {
                if (places[v.first] < v.second) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                dead = false; 
                for (auto &v : transitions[i].inputs) {
                    places[v.first] -= v.second;
                }
                for (auto &v : transitions[i].outputs) {
                    places[v.first] += v.second;
                }
                break;
            }
        }
        if (dead) {
            live = false;
            ++loop_num;
            break;
        }
    }
    if (live) {
        printf("Case %d: still live after %d transitions\n", n, NF);
    } else {
        printf("Case %d: dead after %d transitions\n", n, NF-loop_num);
    }
    printf("Places with tokens:");
    for (int i = 1; i <= NP; ++i) {
        if (places[i]) {
            printf(" %d (%d)", i, places[i]);
        }
    }
    printf("\n\n");
}

int main() {
#ifdef Debug
    freopen("804.in", "r", stdin);
#endif
    int value;
    int n = 0;
    while (scanf("%d", &NP) == 1 && NP) {
        for (int i = 1; i <= NP; ++i) {
            scanf("%d", &places[i]);
        }
        scanf("%d", &NT);
        for (int i = 1; i <= NT; ++i) {
            transitions[i].init();
            while (true) {
                scanf("%d", &value);
                if (!value) break;
                if (value < 0) {
                    value = 0 - value;
                    transitions[i].inputs[value] += 1;
                } else {
                    transitions[i].outputs[value] += 1;
                }
            }
        }
        scanf("%d", &NF);
        //DebugOut();
        Simulate(++n);
    } 
    return 0;
}
