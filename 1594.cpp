/*
 * =====================================================================================
 *
 *       Filename:  1594.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/12/2014 21:39:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int n;
vector<vector<int>> tuples;


void Print() {
	vector<int> &current = tuples.back();
	for (int i = 0; i < current.size(); ++i) {
		printf("%d ", current[i]);
	}
	printf("\n");
}

bool VecEqual(const vector<int> &a, const vector<int> &b) {
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	return true;
}

bool Resolve() {
	//Print();
	unordered_multimap<int, int> dict;
	while (true) {
		vector<int> temp(18);
		vector<int> &current = tuples.back();
		bool all_zero = true;
		long long key = 0;
		for (int i = 0; i < n - 1; ++i) {
			temp[i] = abs(current[i] - current[i+1]);
			if (temp[i]) {
				all_zero = false;
			}
			key += temp[i] * (i+1);
		}
		temp[n-1] = abs(current[n-1] - current[0]);
		if (temp[n-1]) {
			all_zero = false;
		}
		key += temp[n-1] * n;
		if (all_zero) {
			return true;
		}
		if (dict.count(key) > 0) {
			auto range = dict.equal_range(key);
			for (auto it = range.first; it != range.second; ++it) {
				if (VecEqual(tuples[it->second], temp)) {
					return false;
				}
			}
			dict.insert(pair<int,int>(key,tuples.size()));
			tuples.push_back(move(temp));
		} else {
			dict.insert(pair<int,int>(key,tuples.size()));
			tuples.push_back(move(temp));
		}
		//Print();
	}	
}

int main() {
#ifdef Debug
	freopen("1594.in", "r", stdin);
#endif
	tuples.reserve(1010);
	int T, t;
	scanf("%d", &T);
	while (T--) {
		tuples.clear();
		vector<int> temp;
		temp.reserve(18);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &t);
			temp.push_back(t);
		}
		tuples.push_back(move(temp));
		if (Resolve()) {
			printf("ZERO\n");
		} else {
			printf("LOOP\n");
		}
	}
	return 0;
}
