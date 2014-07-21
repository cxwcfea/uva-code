/*
 * =====================================================================================
 *
 *       Filename:  400.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/18/2014 22:29:44
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  cxwcfea(cxwcfea@163.com), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#include <iterator>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
#ifdef Debug
	freopen("400.in", "r", stdin);
#endif
	int n;
	vector<string> names(105);
	string input;
	while (cin >> n) {
		names.clear();
		int len = 0;
		for (int i = 0; i < n; ++i) {
			cin >> input;
			if (len < input.size()) {
				len = input.size();
			}
			names.push_back(move(input));
		}
		sort(begin(names), end(names));
		int col = 60 / (len + 2);
		if (col == 0)
			col = 1;
		int row = ceil(n / (double)col);
		//cout << "len:" << len << " row:" << row << " col:" << col << endl;
		for (int i = 0; i < 60; ++i) {
			printf("-");
		}
		printf("\n");
		for (int i = 0; i < row; ++i) {
			int pos = i;
			for (int j = 0; j < col; ++j) {
				if (pos < names.size()) {
					while (names[pos].size() < len) {
						names[pos] += " ";
					}
					printf("%s", names[pos].c_str());
					if (j < col-1) {
						printf("  ");
					}
					pos += row;
				} else {
					break;
				}
			}
			printf("\n");
		}
	}
	return 0;
}

