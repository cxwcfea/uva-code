/*
 * =====================================================================================
 *
 *       Filename:  806.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/04/2014 12:13:28
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
#include <algorithm>

const int kMax = 64 + 6;

int matrix[kMax][kMax];
int n;
int sequence[kMax*kMax];
int seq_len;
char input[kMax];

void changeToDecimal() {
    std::for_each(sequence, sequence+seq_len, [](int &v) {
            int r = v % 10;
            v /= 10;
            int level = 5;
            while (v) {
                r += v % 10 * level;
                v /= 10;
                level *= 5;
            }
            v = r;
    });
    std::sort(sequence, sequence+seq_len);
}

void solveSubMatrix(int r, int c, int size, int index, int level, int value) {
    bool white = true;
    bool black = true;
    for (int i = r; i < r + size; ++i) {
        for (int j = c; j < c + size; ++j) {
            if (matrix[i][j] == 0) {
                black = false;
            } else {
                white = false;
            }
        }
    }
    if (white) {
        return;
    }
    value = index * static_cast<int>(pow(10, level)) + value;
    if (black) {
        sequence[seq_len++] = value;
        return; 
    }
    int s = size/2;
    int l = level + 1;
    solveSubMatrix(r, c, s, 1, l, value); // NW
    solveSubMatrix(r, c+s, s, 2, l, value); // NE
    solveSubMatrix(r+s, c, s, 3, l, value); // SW
    solveSubMatrix(r+s, c+s, s, 4, l, value); // SE
}

void solveMatrix() {
    seq_len = 0;
    solveSubMatrix(0, 0, n, 0, -1, 0);
    changeToDecimal();
    if (seq_len > 0) {
        int cnt = 1;
        printf("%d", sequence[0]);
        for (int i = 1; i < seq_len; ++i) {
            if (cnt == 12) {
                printf("\n");
                cnt = 0;
                printf("%d", sequence[i]);
            } else {
                printf(" %d", sequence[i]);
            }
            ++cnt;
        }
        printf("\n");
    }
    printf("Total number of black nodes = %d\n", seq_len);
}

void solveSubSequence(int r, int c, int size, int value) {
    size /= 2;
    if (value < 5) {
        if (value == 2) {
            c += size;
        } else if (value == 3) {
            r += size;
        } else if (value == 4) {
            r += size;
            c += size;
        }
        for (int i = r; i < r + size; ++i) {
            for (int j = c; j < c + size; ++j) {
                matrix[i][j] = 1;
            }
        }
    } else {
        int v = value % 10;
        value /= 10;
        switch (v) {
            case 1:
                solveSubSequence(r, c, size, value);
                break;
            case 2:
                solveSubSequence(r, c + size, size, value);
                break;
            case 3:
                solveSubSequence(r + size, c, size, value);
                break;
            case 4:
                solveSubSequence(r+size, c+size, size, value);
                break;
        }
    }
}

void PrintMatrix() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) {
                printf(".");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

void solveSequence() {
    memset(matrix, 0, sizeof(matrix));
    if (seq_len == 1 && sequence[seq_len-1] == 0) {
        memset(matrix, 1, sizeof(matrix));
    } else if (seq_len > 0) {
        for (int i = 0; i < seq_len; ++i) {
            int v = sequence[i];
            int value = 0;
            int level = 0;
            while (v) {
                int t = v % 5;
                t *= static_cast<int>(pow(10, level++));
                value += t;
                v = v / 5;
            }
            solveSubSequence(0, 0, n, value);
        }
    }
    PrintMatrix(); 
}

int main() {
#ifdef Debug
    freopen("806.in", "r", stdin);
#endif
    int cases = 0;
    while (true) {
        fgets(input, kMax, stdin);
        sscanf(input, "%d", &n);
        if (n == 0) break;
        if (cases)
            printf("\n");

        printf("Image %d\n", ++cases);
        if (n > 0) {
            for (int i = 0; i < n; ++i) {
                fgets(input, kMax, stdin);
                for (int j = 0; j < n; ++j) {
                    matrix[i][j] = input[j] - '0';
                }
            }
            solveMatrix();
        } else {
            n = 0 - n;
            int v;
            seq_len = 0;
            while (scanf("%d", &v) && v != -1) {
                sequence[seq_len++] = v; 
            }
            getchar();
            solveSequence();
        }
    }
    return 0;
}
