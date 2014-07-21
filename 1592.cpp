/*
 * =====================================================================================
 *
 *       Filename:  1592.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/19/2014 15:35:17
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

const int kRows = 10005;
const int kCols = 12;
int n, m, cnt;

int matrix[kRows][kCols];

map<string, int> id_map;
map<pair<int,int>, int> check_map;

int ID(string &str) {
	if (id_map.count(str)) {
		return id_map[str];
	}
	id_map[str] = cnt++;
	return id_map[str];
}

void check() {
	for (int i = 0; i < m-1; ++i) {
		for (int j = i+1; j < m; ++j) {
			check_map.clear();
			for (int r = 0; r < n; ++r) {
				pair<int, int> key = make_pair(matrix[r][i], matrix[r][j]);
				if (check_map.count(key)) {
					printf("NO\n");
					printf("%d %d\n", check_map[key]+1, r+1);
					printf("%d %d\n", i+1, j+1);
					return;
				} else {
					check_map[key] = r;
				}
			}
		}
	}
	printf("YES\n");
}

int main() {
#ifdef Debug
	freopen("1592.in", "r", stdin);
#endif
	string input;
	while (getline(cin, input)) {
		cnt = 0;
		sscanf(input.c_str(), "%d %d", &n, &m);
		id_map.clear();
		for (int i = 0; i < n; ++i) {
			int j = 0;
			getline(cin, input);
			int pos;
			while ((pos = input.find(',')) != string::npos) {
				string sub_str = input.substr(0, pos);
				input = input.substr(pos+1);	
				matrix[i][j++] = ID(sub_str);
			}
			matrix[i][j] = ID(input);
		}
		check();	
	}
	return 0;
}
