/*
 * =====================================================================================
 *
 *       Filename:  1595.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/14/2014 20:27:27
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  cxwcfea(cxwcfea@163.com), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

const int INF = 20000;

int main() {
#ifdef Debug
	freopen("1595.in", "r", stdin);
#endif
	int T, N, x, y;
	scanf("%d", &T);
	while (T--) {
		double center = INF;
		bool possible = true;
		unordered_map<int, vector<int>> point_map;
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) {
			scanf("%d %d", &x, &y);
			vector<int> &value = point_map[y];
			value.push_back(x);	
		}
		for (auto iter = point_map.begin(); iter != point_map.end(); ++iter) {
			vector<int> &value = iter->second;
			double sum = 0;
			for (auto it = value.begin(); it != value.end(); ++it) {
				sum += *it;
			}
			double mid = sum / value.size();
			if (center == INF) {
				center = mid;
			} else if (mid != center) {
				possible = false;
				break;
			}
			set<double> test_table;
			for (auto it = value.begin(); it != value.end(); ++it) {
				double v = fabs(center - *it);
				auto search = test_table.find(v);
				if (search != test_table.end()) {
					test_table.erase(search);
				} else {
					test_table.insert(v);
				}	
			}
			if (test_table.size() > 1 || (test_table.size() == 1 && !test_table.count(0.0))) {
				possible = false;
				break;
			}
		}	
		if (possible)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
