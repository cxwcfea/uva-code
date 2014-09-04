/*
 * =====================================================================================
 *
 *       Filename:  1103.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/02/2014 15:14:32
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
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int kMax = 205;
const int kLen = 55;

int data[kMax][kMax];
int temp_data[kMax][kMax];
char input[kLen];
int H, W, Width;
int current;
int image_row, image_col;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
const char* code = "WAKJSD";

int getDigitForHex(char ch) {
    if (isdigit(ch)) {
        return ch - '0';
    }
    return ch - 'a' + 10;
}

void translateDigit(int num, int row, int col) {
    int cnt = 0;
    while (num || cnt < 4) {
        data[row][--col] = num % 2;
        num /= 2;
        ++cnt;
    }
}

void DebugOutput() {
    /*
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < Width; ++j) {
            printf("%c", data[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
      */
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < Width; ++j) {
            printf("%d", temp_data[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void ReadImage() {
    for (int i = 0; i < H; ++i) {
        int cur = 0;
        fgets(input, kLen, stdin);
        for (int j = 0; j < W; ++j) {
            cur += 4;
            translateDigit(getDigitForHex(input[j]), i, cur);
        }
    }
}

void FindSymbol(int r, int c, int &start_r, int &end_r, int &start_c, int &end_c) {
    if (r < 0 || r >= H || c < 0 || c >= Width || data[r][c] != 1) return;
    data[r][c] = current;
    if (r > end_r) {
        end_r = r;
    }
    if (c < start_c) {
        start_c = c;
    }
    if (c > end_c) {
        end_c = c;
    }

    for (int i = 0; i < 4; ++i) {
        FindSymbol(r+dr[i], c+dc[i], start_r, end_r, start_c, end_c);
    }
}

bool dfs(int r, int c) {
    if (r < 0 || r >= image_row || c < 0 || c >= image_col) {
        return false;
    }
    if (temp_data[r][c] != 0) {
        if (temp_data[r][c] == current || temp_data[r][c] == '~') {
            return true;
        }
        return false;
    }

    bool ret = true;
    temp_data[r][c] = '~';
    for (int i = 0; i < 4; ++i) {
        ret = dfs(r+dr[i], c+dc[i]) && ret;
    }

    return ret;
}

int IdentifySymbol() {
    int ret = 0;
    for (int i = 0; i < image_row; ++i) {
        for (int j = 0; j < image_col; ++j) {
            if (temp_data[i][j] == 0) {
                if (dfs(i, j)) {
                    ++ret;
                }
            } 
        }
    }
    return ret;
}

void CopyImage(int r1, int r2, int c1, int c2) {
    image_row = r2 - r1 + 1;
    image_col = c2 - c1 + 1;
    int r = 0;
    for (int i = r1; i <= r2; ++i) {
        int c = 0;
        for (int j = c1; j <= c2; ++j) {
            if (data[i][j] == 0 || data[i][j] == current)
                temp_data[r][c] = data[i][j];
            else
                temp_data[r][c] = 0;
            ++c;
        }
        ++r;
    } 
}

void dfs_p(int r, int c, int cnt) {
    if (r < 0 || r >= H || c < 0 || c >= Width || temp_data[r][c]) return;
    temp_data[r][c] = cnt;
    for (int i = 0; i < 4; ++i) {
        if (data[r][c] == data[r+dr[i]][c+dc[i]])
            dfs_p(r + dr[i], c + dc[i], cnt);
    }
}

void paint() {
    memset(temp_data, 0, sizeof(temp_data));
    int color = 1;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < Width; ++j) {
            if (!temp_data[i][j]) {
                dfs_p(i, j, color++); 
            }
        }
    }
}

int main() {
#ifdef Debug
    freopen("1103.in", "r", stdin);
#endif
    vector<char> symbols;
    symbols.reserve(30);
    int T = 0;
    while (true) {
        fgets(input, kLen, stdin);
        sscanf(input, "%d %d", &H, &W);
        if (!H && !W) break;
        Width = 4 * W;
        current = 2;
        symbols.clear();
        image_row = image_col = 0;
        ReadImage();
        int start_r, end_r, start_c, end_c;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < Width; ++j) {
                if (data[i][j] == 1) {
                    start_r = i;
                    end_r = i;
                    start_c = j;
                    end_c = j;
                    FindSymbol(i, j, start_r, end_r, start_c, end_c);
                    CopyImage(start_r, end_r, start_c, end_c);
                    //DebugOutput();
                    int id = IdentifySymbol();
                    symbols.push_back(code[id]);
                    ++current;
                }
            }
        }
        sort(symbols.begin(), symbols.end());        
        printf("Case %d: ", ++T); 
        for (vector<char>::const_iterator iter = symbols.begin(); iter != symbols.end(); ++iter) {
            printf("%c", *iter);
        }
        printf("\n");
    }
    return 0;
}
