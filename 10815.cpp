/*
 * =====================================================================================
 *
 *       Filename:  10815.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/17/2014 22:30:03
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  cxwcfea(cxwcfea@163.com), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cctype>
#include <set>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
#ifdef Debug
	freopen("10815.in", "r", stdin);
#endif

	set<string> word_dict;	
	string input;
	string word;
	while (getline(cin, input)) {
		for (auto &ch : input) {
			if (isalpha(ch))
				ch = tolower(ch);
			else
				ch = ' ';
		}
		stringstream sin(input);
		while (sin >> word) {
			word_dict.insert(word);
		}
	}
	for (auto w : word_dict) {
		printf("%s\n", w.c_str());
	}

	return 0;
}
