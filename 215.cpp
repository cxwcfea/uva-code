/*
 * =====================================================================================
 *
 *       Filename:  215.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/08/2014 17:02:07
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
#include <string>
#include <algorithm>

using namespace std;

const int kMax = 80;

struct Cell {
    long long value;
    string expression; 
    bool known;
    bool circular;
    void init() {
        known = false;
        circular = false;
        expression = "";
    }
};

Cell spreadsheet[20][10];
int row, col;
char input[kMax];
bool circular;
bool visiting[20][10];

void DebugOut() {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%lld ", spreadsheet[i][j].value);
        }
        printf("\n");
    }
}

void init() {
    memset(visiting, 0, sizeof(visiting));
    circular = false;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            spreadsheet[i][j].init();
        }
    }
}

int resolve(int i, int j) {
    visiting[i][j] = true;
    int ret = 0;  
    if (spreadsheet[i][j].known) {
        visiting[i][j] = false;
        return spreadsheet[i][j].value;
    }
    const char *pos = spreadsheet[i][j].expression.c_str();
    int r = -1;
    int c = -1;
    char sign  = '+';
    int value;
    while (*pos != ' ' && *pos != '\n') {
        if (isalpha(*pos)) {
            r = *pos - 'A';
            ++pos;
            c = atoi(pos);
            ++pos;
            if (visiting[r][c] || spreadsheet[r][c].circular) {
                spreadsheet[i][j].circular = true;
                spreadsheet[r][c].circular = true;
                circular = true;
                break;
            } else {
                value = resolve(r, c);
                if (spreadsheet[r][c].circular) {
                    spreadsheet[i][j].circular = true;
                    break;
                }
                if (sign == '+') {
                    ret += value;
                } else {
                    ret -= value;
                }
            }
        } else if (isdigit(*pos)) {
            value = atoi(pos);
            if (sign == '+') {
                ret += value;
            } else {
                ret -= value;
            }
            while (isdigit(*pos)) {
                ++pos;
            } 
        } else {
            sign = *pos;
            ++pos;
        }
    }
    if (!spreadsheet[i][j].circular) {
        spreadsheet[i][j].known = true;
        spreadsheet[i][j].value = ret;
    }
    visiting[i][j] = false;

    return ret;
}

void calculate() {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (!spreadsheet[i][j].known && !spreadsheet[i][j].circular) {
                resolve(i, j);
                //DebugOut();
            }
        }
    }
    if (!circular) {
        printf(" ");
        for (int i = 0; i < col; ++i) {
            printf("     %d", i);
        }
        printf("\n");
        for (int i = 0; i < row; ++i) {
            printf("%c", i+'A');
            for (int j = 0; j < col; ++j) {
                printf(" %5lld", spreadsheet[i][j].value);
            }
            printf("\n");
        }
    } else {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (spreadsheet[i][j].circular) {
                    printf("%c%d: %s", i+'A', j, spreadsheet[i][j].expression.c_str());
                }
            }
        }
    }
    printf("\n");
}

int main() {
#ifdef Debug
    freopen("215.in", "r", stdin);
#endif
    while (true) {
        fgets(input, kMax, stdin);
        sscanf(input, "%d %d", &row, &col);
        if (!row && !col) break;
        init();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                fgets(input, kMax, stdin);
                if (isalpha(input[0])) {
                    spreadsheet[i][j].expression = input;
                } else {
                    spreadsheet[i][j].value = atoi(input);
                    spreadsheet[i][j].known = true;
                }
            }
        }
        calculate();
    }

    return 0;
}
