/*
 * =====================================================================================
 *
 *       Filename:  10340.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/05/2014 15:42:33
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  cxwcfea(cxwcfea@163.com), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
#ifdef Debug
	freopen("10340.in", "r", stdin);
#endif
	string s, t;
	while (cin >> s >> t) {
		string::iterator sp = s.begin(), tp = t.begin();
		while (sp < s.end() && tp < t.end()) {
			if (*sp == *tp) {
				++sp;
				++tp;
			} else {
				++tp;
			}
		}
		if (sp == s.end()) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}
