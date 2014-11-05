/*
 * =====================================================================================
 *
 *       Filename:  1343.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/04/2014 14:16:06
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
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

const int kNumSymbol = 24;

const int moves[8][7] = {
	{ 0, 2, 6, 11, 15, 20, 22 },     // A
	{ 1, 3, 8, 12, 17, 21, 23 },     // B
	{ 10, 9, 8, 7, 6, 5, 4 },        // C
	{ 19, 18, 17, 16, 15, 14, 13 },  // D
	{ 23, 21, 17, 12, 8, 3, 1 },     // E
	{ 22, 20, 15, 11, 6, 2, 0 },     // F
	{ 13, 14, 15, 16, 17, 18, 19 },  // G
	{ 4, 5, 6, 7, 8, 9, 10 }         // H
};

const int center[8] = { 6, 7, 8, 11, 12, 15, 16, 17 };
const int rev[8] = { 5, 4, 7, 6, 1, 0, 3, 2 };

int symbols[kNumSymbol];
int currentSymbol;
char ans_path[1000];

void move(int j) {
	int tmp = symbols[moves[j][0]];
	for (int i = 0; i < 6; ++i) {
		symbols[moves[j][i]] = symbols[moves[j][i+1]];
	}
	symbols[moves[j][6]] = tmp;
}

bool success() {
	bool ret = true;

	for (int i = 1; i < 8; ++i) {
		if (symbols[center[i]] != symbols[center[0]]) {
			ret = false;
			break;
		}
	}

	if (ret) currentSymbol = symbols[center[0]];
	return ret;
}

int diff(int target) {
	int ret = 0;

	for (int i = 0; i < 8; ++i) {
		if (symbols[center[i]] != target) {
			++ret;
		}
	}

	return ret;
}

int possible_move() {
	return min(min(diff(1), diff(2)), diff(3));
}

bool dfs(int d, int maxd) {
	if (success()) {
		ans_path[d] = '\0';
		return true;
	}

	if (d + possible_move() > maxd) return false;

	for (int i = 0; i < 8; ++i) {
		move(i);
		ans_path[d] = char(i + 'A');
		if (dfs(d+1, maxd)) return true;;
		move(rev[i]);
	}

	return false;
}

int main() {
#ifdef Debug
	freopen("1343.in", "r", stdin);
#endif
	while (true) {
		int i = 0;
		scanf("%d", &symbols[i]);
		if (!symbols[i]) break;
		for (++i; i < kNumSymbol; ++i) {
			scanf("%d", &symbols[i]);
		}

		if (success()) {
			printf("No moves needed\n");
			printf("%d\n", currentSymbol);
			continue;
		}

		for (i = 1; ; ++i) {
			if (dfs(0, i)) break;
		}
		printf("%s\n", ans_path);
		printf("%d\n", currentSymbol);
	}
	return 0;
}

