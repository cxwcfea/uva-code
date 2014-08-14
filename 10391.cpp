/*
 * =====================================================================================
 *
 *       Filename:  10391.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/13/2014 20:26:48
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  cxwcfea(cxwcfea@163.com), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <set>
#include <map>
#include <string>
#include <vector>

using namespace std;

char buf[200];
vector<string> words;

bool IsPrefix(const string &src, const string &dest) {
	if (dest.find(src) == 0)
		return true;
	return false;
}

int main() {
#ifdef Debug
	freopen("10391.in", "r", stdin);
#endif
	words.reserve(120010);
	while (scanf("%s", buf) == 1) {
		words.emplace_back(buf);
	}

	set<string> compound_word;
	map<string, vector<string>> dict;
	vector<string> current_value; 
	for (auto iter = words.begin(); iter != words.end(); ++iter) {
		auto it = iter + 1;
		for (; it != words.end(); ++it) {
			if (IsPrefix(*iter, *it)) {
				current_value.push_back(*it);
			} else {
				dict[*iter] = move(current_value);
				break;
			}
		}
		if (it == words.end()) {
			dict[*iter] = move(current_value);
		}
	}

	for (auto iter = dict.begin(); iter != dict.end(); ++iter) {
		vector<string> &value = iter->second;
		if (value.size()) {
			//printf("%s is a prefix\n", (iter->first).c_str());
			for (auto it = value.begin(); it != value.end(); ++it) {
				string sub = (*it).substr((iter->first).size());
				if (dict.find(sub) != dict.end()) {
					compound_word.insert(*it);
					/*
					if (*it == "ali") {
						printf("found it %s\n", (iter->first).c_str());
					}  */
					//printf("compound word contain %s is %s\n", (iter->first).c_str(), (*it).c_str());
				}
			}
		}
	}
	for (auto iter = compound_word.begin(); iter != compound_word.end(); ++iter) {
		printf("%s\n", (*iter).c_str());
	}

	return 0;
}
