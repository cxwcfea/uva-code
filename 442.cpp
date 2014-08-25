/*
 * =====================================================================================
 *
 *       Filename:  442.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/25/2014 21:39:52
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
#include <stack>
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
#include <string>

using namespace std;

pair<int, int> matrixs[26];

int main() {
#ifdef Debug
    freopen("442.in", "r", stdin);
#endif
    int n;
    scanf("%d\n", &n);
    char m;
    int row, col;
    for (int i = 0; i < n; ++i) {
        scanf("%c %d %d\n", &m, &row, &col);
        int pos = m - 'A';
        matrixs[pos].first = row;
        matrixs[pos].second = col;
    }
    stack<pair<int, int> > parser;
    string input;
    while (cin >> input) {
        //printf("%s\n", input.c_str());
        int index = 0;
        int len = input.length();
        int count = 0;
        bool error = false;
        while (index < len) {
            if (isalpha(input[index])) {
                parser.push(matrixs[input[index]-'A']);
            } else if (input[index] == ')') {
                pair<int, int> a = parser.top();
                parser.pop();
                pair<int, int> b = parser.top();
                parser.pop();
                if (b.second != a.first) {
                    error = true;
                    break;
                }
                count += b.first * b.second * a.second;
                parser.push(make_pair(b.first, a.second));
            }
            ++index;
        }
        if (error)
            printf("error\n");
        else
            printf("%d\n", count);
    }
    /*
    for (int i = 0; i < n; ++i) {
        printf("%c %d %d\n", i+'A', matrixs[i].first, matrixs[i].second);
    }
  */
    return 0;
}
