/*
 * =====================================================================================
 *
 *       Filename:  127.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/23/2014 15:11:07
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
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

using Pair = pair<char, char>;
using ListIter = list<vector<Pair>>::iterator;
char cards[4][26][4];
char input[5];
list<vector<Pair>> piles;

void DebugOut() {
    for (auto &v : piles) {
        for (auto &vv : v) {
            printf("%c%c ", vv.first, vv.second);
        }
        printf("\n");
    }
    printf("\n");
}

bool Adjust(ListIter prev, ListIter next) {
    bool ret = false;
    Pair &first = prev->back();
    Pair &second = next->back();
    if (first.first == second.first || first.second == second.second) {
        prev->push_back(move(second));
        next->pop_back();
        if (next->empty()) {
            next= piles.erase(next);
        }
        ret = true;
        //DebugOut();
    }
    return ret;
}

bool Check(ListIter iter) {
    bool adjusted = false;
    auto dist = distance(piles.begin(), iter);
    if (dist >= 3) {
        ListIter prev = iter;
        advance(prev, -3);
        adjusted = Adjust(prev, iter); 
    }
    
    if (!adjusted && dist >= 1) {
        ListIter prev = iter;
        advance(prev, -1);
        adjusted = Adjust(prev, iter); 
    } 
        
    return adjusted;
}

void Solve() {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 26; ++j) {
            vector<Pair> pile;
            pile.emplace_back(cards[i][j][0], cards[i][j][1]);
            piles.push_back(move(pile));
            bool adjusted = Check(--piles.end());
            //DebugOut();
            while (adjusted) {
                for (auto iter = piles.begin(); iter != piles.end(); ++iter) {
                    adjusted = Check(iter);
                    if (adjusted) {
                        //DebugOut();
                        break;
                    }
                }
            }
        }
    }
    if (piles.size() > 1)
        printf("%lu piles remaining:", piles.size());
    else
        printf("%lu pile remaining:", piles.size());
    for (auto &v : piles) {
        printf(" %lu", v.size());
    }
    printf("\n");
}

int main() {
#ifdef Debug
    freopen("127.in", "r", stdin);
#endif
    int line = 0, cnt = 0;
    while (true) {
        scanf("%s", input);
        if (input[0] == '#') break;
        strncpy(cards[line][cnt], input, 4);
        ++cnt;    
        if (cnt == 26) {
            ++line;
            if (line == 2) {
                //DebugOut();
                Solve();
                line = 0;
                piles.clear();
            }
            cnt = 0;
        }
    } 
    return 0;
}
