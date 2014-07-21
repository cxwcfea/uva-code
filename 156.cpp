/*
 * =====================================================================================
 *
 *       Filename:  156.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/18/2014 11:40:56
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  cxwcfea(cxwcfea@163.com), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cctype>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
#ifdef Debug
	freopen("156.in", "r", stdin);
#endif
	map<string, int> anagrams;
	map<string, string> dict;
	string input;
	string word;
	while (getline(cin, input)) {
		stringstream input_stream(input);
		while (input_stream >> word) {
			if (word == "#") {
				break;
			}
			string key = word;
			for (auto &ch : key) {
				ch = tolower(ch);
			}
			sort(key.begin(), key.end());	
			if (anagrams.find(key) == anagrams.end()) {
				anagrams[key] = 1;
			} else {
				++anagrams[key];
			}
			dict[word] = key;
		}
	}
	for (auto &a : dict) {
		if (anagrams[a.second] == 1) {
			cout << a.first << endl;
		}
	}
	return 0;
}


