/*
 * =====================================================================================
 *
 *       Filename:  10562.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/09/2014 13:49:28
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
#include <algorithm>

const int kMax = 200 + 15;

char tree_map[kMax][kMax];
int max_row;

void Solve(int row, int start, int end) {
    int i = start;
    while (i < end) {
        if (!isspace(tree_map[row][i]) && tree_map[row][i] != '\0') {
            printf("%c(", tree_map[row][i]);
            if (row + 1 < max_row) {
                if (tree_map[row+1][i] == '|') {
                    int left = i, right = i;
                    while (tree_map[row+2][left] == '-') {
                        --left;
                    }
                    while (tree_map[row+2][right] == '-') {
                        ++right;
                    }
                    Solve(row+3, left+1, right);
                }
            }
            printf(")");
        }
        ++i;
    }
}

int main() {
#ifdef Debug
    freopen("10562.in", "r", stdin);
#endif
    int T;
    fgets(tree_map[0], kMax, stdin);   
    sscanf(tree_map[0], "%d", &T);
    while (T--) {
        memset(tree_map, 0, sizeof(tree_map));
        int i = 0; 
        char ch;
        while (true) {
            fgets(tree_map[i], kMax, stdin);   
            if (tree_map[i][0] == '#') break;
            ++i;
        }
        max_row = i;
        printf("(");
        if (max_row)
            Solve(0, 0, strlen(tree_map[0])); 
        printf(")\n");
    }
    return 0;
}
