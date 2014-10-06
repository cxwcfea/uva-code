/*
 * =====================================================================================
 *
 *       Filename:  12166.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/19/2014 13:57:54
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
#include <cmath>
#include <cctype>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int kMax = 1000000;

char input[kMax];
int T;

struct Node {
    int value;
    map<long long, long long> possible_value;  // map: first is the possible value, second is the minimal change which need to get this possible value
    Node(int v = 0) : value{v}, end_pos{0}, num_of_value{0} {}
    int end_pos;
    int num_of_value;  // how many node contained in the tree which the root is this node .
};

Node Traverse(char *pos) {
    if (*pos != '[') {
        int value = atoi(pos);
        //printf("value : %d\n", value);
        Node ret; 
        ret.possible_value[value] = 0;
        char *p = pos;
        while (isdigit(*p)) ++p;
        ret.end_pos = p - input;
        ret.num_of_value = 1;
        return ret;
    }
    Node left = Traverse(pos+1);
    Node right = Traverse(input+left.end_pos+1);

    Node ret;
    ret.end_pos = right.end_pos + 1;
    ret.num_of_value = left.num_of_value + right.num_of_value;
    for (auto &v : left.possible_value) {
        if (right.possible_value.count(v.first)) {
            ret.possible_value[v.first*2] = v.second + right.possible_value[v.first];
        } else {
            ret.possible_value[v.first*2] = right.num_of_value + v.second; // since right child do not contain this value, so we need change all the nodes in right child to get this value
        }
    }
    for (auto &v : right.possible_value) {
        if (left.possible_value.count(v.first)) {
            ret.possible_value[v.first*2] = v.second + left.possible_value[v.first];
        } else {
            ret.possible_value[v.first*2] = left.num_of_value + v.second;
        }
    }

    return ret;
}

void Solve() {
    int n = 0;
    Node root = Traverse(input); 
    int min_change = 1000000000;
    for (auto &v : root.possible_value) {
        if (v.second < min_change) {
            min_change = v.second;
        }
    }
    printf("%d\n", min_change);
}

int main() {
#ifdef Debug
    freopen("12166.in", "r", stdin);
#endif
    fgets(input, kMax, stdin);
    sscanf(input, "%d", &T);
    for (int i = 0; i < T; ++i) {
        fgets(input, kMax, stdin);
        Solve();
    }
    return 0;
}
