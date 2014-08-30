/*
 * =====================================================================================
 *
 *       Filename:  699.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/30/2014 11:08:30
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

const int kMax = 150;

int data[kMax];

void CreateNode(int pos) {
    int value;
    scanf("%d", &value);
    if (value != -1) {
        data[pos] += value;
        CreateNode(pos-1);
        CreateNode(pos+1);
    }
}

bool ReadData() {
    memset(data, 0, sizeof(data));
    int value;
    scanf("%d", &value);
    if (value == -1) {
        return false;
    }
    int root = kMax / 2;
    data[root] = value; 
    CreateNode(root-1);
    CreateNode(root+1);
    return true;
}

int main() {
#ifdef Debug
    freopen("699.in", "r", stdin);
#endif
    int T = 0;
    while (true) {
        if (!ReadData()) {
            break;
        }
        printf("Case %d:\n", ++T);
        int i = 0;
        while (data[i] == 0) {
            ++i;
        }
        printf("%d", data[i++]);
        while (data[i] != 0) {
            printf(" %d", data[i]);
            ++i;
        }
        printf("\n\n");
    }
    return 0;
}
