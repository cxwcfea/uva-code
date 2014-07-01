/*
 * =====================================================================================
 *
 *       Filename:  1225.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/01/2014 22:03:44
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  cxwcfea(cxwcfea@163.com), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int digits[10];

void updateDigits(int v) {
	while (v) {
		int n = v%10;
		++digits[n];
		v /= 10;
	}
}

void printDigits() {
	printf("%d", digits[0]);
	for (int i = 1; i < 10; ++i) {
		printf(" %d", digits[i]);
	}
	printf("\n");
}

int main() {
#ifdef Debug
	freopen("1225.in", "r", stdin);
#endif
	const int MAXN = 30;
	memset(digits, 0, sizeof digits);
	int T;
	scanf("%d", &T);
	vector<int> cases;
	cases.reserve(T);
	while (T--) {
		int n;
		scanf("%d", &n);
		cases.push_back(n);
	}
	sort(cases.begin(), cases.end(), greater<int>());
	for (int i = 1; !cases.empty(); ++i) {
		updateDigits(i);
		if (i == cases.back()) {
			printDigits();
			cases.pop_back();
		}
	}
	return 0;
}
