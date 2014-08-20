/*
 * =====================================================================================
 *
 *       Filename:  12504.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/19/2014 21:33:05
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
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int kMax = 110;
char input[kMax]; 

void ConstructDict(map<string, string> &dict) {
	char *token = strtok(input, "{,}\n");
	while (token != nullptr) {
		const char *pos = strchr(token, ':');
		string key {token, (size_t)(pos-token)};
		string value {pos+1};
		dict.insert(make_pair(move(key), move(value)));
		token = strtok(nullptr, "{,}\n");
	}
}

int main() {
#ifdef Debug
	freopen("12504.in", "r", stdin);
#endif
	int T;
	scanf("%d\n", &T);
	while (T--) {
		vector<string> add;
		vector<string> minus;
		vector<string> diff;
		map<string, string> old_dict;
		map<string, string> new_dict;
		fgets(input, kMax, stdin);
		ConstructDict(old_dict);
		fgets(input, kMax, stdin);
		ConstructDict(new_dict);
		auto old_iter = old_dict.begin();
		auto new_iter = new_dict.begin();
		while (old_iter != old_dict.end() && new_iter != new_dict.end()) {
			if (old_iter->first == new_iter->first) {
				if (old_iter->second != new_iter->second) {
					diff.push_back(old_iter->first);
				}
				++old_iter;
				++new_iter;	
			} else if (old_iter->first < new_iter->first) {
				minus.push_back(old_iter->first);
				++old_iter;
			} else {
				add.push_back(new_iter->first);
				++new_iter;
			}
		}
		while (old_iter != old_dict.end()) {
			minus.push_back(old_iter->first);	
			++old_iter;
		}
		while (new_iter != new_dict.end()) {
			add.push_back(new_iter->first);
			++new_iter;
		}
		
		if (add.empty() && minus.empty() && diff.empty()) {
			printf("No changes\n");
		} else {
			for (int i = 0; i < add.size(); ++i) {
				if (i == 0) {
					printf("+");
				}
				printf("%s", add[i].c_str());
				if (i < add.size()-1) {
					printf(",");
				} else {
					printf("\n");
				}
			}
			for (int i = 0; i < minus.size(); ++i) {
				if (i == 0) {
					printf("-");
				}
				printf("%s", minus[i].c_str());
				if (i < minus.size()-1) {
					printf(",");
				} else {
					printf("\n");
				}
			}
			for (int i = 0; i < diff.size(); ++i) {
				if (i == 0) {
					printf("*");
				}
				printf("%s", diff[i].c_str());
				if (i < diff.size()-1) {
					printf(",");
				} else {
					printf("\n");
				}
			}
		}
		printf("\n");
	}

	return 0;
}
