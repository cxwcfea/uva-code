/*
 * =====================================================================================
 *
 *       Filename:  814.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/23/2014 17:37:34
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
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

const int kMax = 80;
const string padding = "     ";
char input[kMax];

vector<string> MTA_cache;
map<string, vector<string>> receivers_map;
map<string, set<string>> MTA_user_list;

void PrintMTAForDebug() {
	cout << endl;
	for (auto &v : MTA_user_list) {
		cout << "user in MTA: " << v.first << endl;
		for (auto &user : v.second) {
			cout << user << endl;
		}
	}	
	cout << endl;
}

void ReadMTA() {
	int n;
	while (true) {
		scanf("%s", input);
		if (input[0] == '*') {
			return;
		}

		scanf("%s", input);
		string mta_name(input);
		set<string> &user_list = MTA_user_list[mta_name];
		scanf("%s", input);	
		n = atoi(input);
		for (int i = 0; i < n; ++i) {
			scanf("%s", input);
			string user(input);
			user_list.insert(user);
		}
	}
}

string User(const string &address) {
	size_t pos = address.find('@');
	return address.substr(0, pos);
}

string MTA(const string &address) {
	size_t pos = address.find('@');
	return address.substr(pos+1);
}

void StrimToNewline() {
	char ch;
	while ((ch = getchar()) != '\r' && ch != '\n')
		;
	return;
}

void PrintContents(vector<string> &contents) {
	for (auto &v : contents) {
		printf("%s%s", padding.c_str(), v.c_str());
	}
	printf("%s250\n", padding.c_str());
}

void Resolve(const string &sender) {
	//cout << "Resolve " << sender << endl;
	MTA_cache.clear();
	receivers_map.clear();
	string sender_mta = MTA(sender);
	set<string> receiver_cache;
	while (true) {
		scanf("%s", input);
		if (input[0] == '*')
			break;

		string address(input);
		if (receiver_cache.find(address) != receiver_cache.end()) {
			continue;
		}
		receiver_cache.insert(address);
		string mta = MTA(address);
		vector<string> &receivers = receivers_map[mta];
		receivers.push_back(move(address));
		if (receivers.size() == 1) {
			MTA_cache.push_back(move(mta));
		}
	}
	StrimToNewline();
	vector<string> contents;
	string content;
	while (true) {
		fgets(input, kMax, stdin);
		if (input[0] == '*')
			break;

		contents.emplace_back(input);
	}
	contents.emplace_back(".\n");
	for (auto &v : MTA_cache) {
		int count = 0;
		printf("Connection between %s and %s\n", sender_mta.c_str(), v.c_str());
		printf("%sHELO %s\n", padding.c_str(), sender_mta.c_str());
		printf("%s%d\n", padding.c_str(), 250);	
		printf("%sMAIL FROM:<%s>\n", padding.c_str(), sender.c_str());
		printf("%s%d\n", padding.c_str(), 250);	
		for (auto &receiver : receivers_map[v]) {
			printf("%sRCPT TO:<%s>\n", padding.c_str(), receiver.c_str());
			string user = User(receiver);
			set<string> &user_list = MTA_user_list[v];
			if (user_list.find(user) != user_list.end()) {
				printf("%s%d\n", padding.c_str(), 250);	
				++count;
			} else {
				printf("%s%d\n", padding.c_str(), 550);	
			}
		}
		if (count > 0) {
			printf("%sDATA\n", padding.c_str());
			printf("%s354\n", padding.c_str());
			PrintContents(contents);
		}
		printf("%sQUIT\n", padding.c_str());
		printf("%s221\n", padding.c_str());
	}
}

int main() {
#ifdef Debug
	freopen("814.in", "r", stdin);
#endif
	ReadMTA();
	while (true) {
		scanf("%s", input);
		if (input[0] == '*') {
			break;
		}
		string sender(input);
		Resolve(sender);
	}
	return 0;
}

