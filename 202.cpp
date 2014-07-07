/*
 * =====================================================================================
 *
 *       Filename:  202.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/05/2014 11:01:05
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  cxwcfea(cxwcfea@163.com), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include <cstdio>
#include <vector>
#include <map>

using namespace std;

void calculate(int a, int b) {
	printf("%d/%d = ", a, b);
	map<int, int> dividend;
	vector<int> integer_part;
	vector<int> decimal_part;
	integer_part.reserve(10);
	decimal_part.reserve(200);
	bool calculate_decimal = false;
	int pos = 0;
	while (1) {
		if (a < b) {
			if (!calculate_decimal) {
				if (dividend.find(a) == dividend.end()) {
					dividend[a] = decimal_part.size();
				}
				calculate_decimal = true;
			}
			a *= 10;
		}
		int quotient = a / b;
		a = a % b;		
		if (calculate_decimal) {
			decimal_part.push_back(quotient);
			if (dividend.find(a) == dividend.end()) {
				dividend[a] = decimal_part.size();
			} else {
				pos = dividend[a];
				break;
			}
		} else {
			integer_part.push_back(quotient);
		}
		if (a == 0) {
			pos = decimal_part.size();
			break;
		}
	}
	if (integer_part.empty()) {
		printf("0");
	} else {
		for (auto &v : integer_part) {
			printf("%d", v);
		}
	}
	printf(".");
	for (int i = 0; i < decimal_part.size(); ++i) {
		if (i == pos) {
			printf("(");
		}
		printf("%d", decimal_part[i]);
		if (i == 49) {
			printf("...");
			break;
		}
	}
	if (pos == decimal_part.size()) {
		printf("(0)");
		--pos;
	} else {
		printf(")");
	}
	printf("\n");
	printf("   %d = number of digits in repeating cycle\n", (int)(decimal_part.size()-pos));
	printf("\n");
}

int main() {
#ifdef Debug
	freopen("202.in", "r", stdin);
#endif
	int a, b;
	while (scanf("%d %d", &a, &b) == 2) {
		getchar();
		calculate(a, b);
	}
	return 0;
}
