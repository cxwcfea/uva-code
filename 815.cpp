/*
 * =====================================================================================
 *
 *       Filename:  815.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/14/2014 11:18:01
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  cxwcfea(cxwcfea@163.com), 
 *   Organization:  
 *
 * =====================================================================================
 */


/*
hint:
12 25 27 34 37 45 51 83 94

10000

33x100+20x100+18x100+11x100+8x100 = 9000
1000/600
  */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int kMax = 35;

vector<int> regions;
int m, n, water;

void resolve() {
	double sum = 0;
	sort(regions.begin(), regions.end());
	double limit = water / 100.0;
	double water_level;
	//printf("water:%d limit:%f\n", water, limit);
	int i;
	for (i = 1; i < regions.size(); ++i) {
		int temp = (regions[i] - regions[i-1]) * i;
		if (sum + temp > limit)
			break;
		sum += temp;	
	}
	sum = limit - sum;
	water_level = regions[i-1] + (sum / i);

	int num_of_low_region = 0;
	for (i = 0; i < regions.size(); ++i) {
		if (regions[i] >= water_level) {
			break;
		}
		++num_of_low_region;	
	}
	//printf("num_of_low_region:%d, size:%d\n", num_of_low_region, regions.size());
	printf("Water level is %.2f meters.\n", water_level);
	printf("%.2f percent of the region is under water.\n", (double)num_of_low_region / (double)regions.size() * 100);
	printf("\n");
}

int main() {
#ifdef Debug
	freopen("815.in", "r", stdin);
#endif
	int value, cases = 0;
	regions.reserve(1000);
	while (scanf("%d %d", &m, &n) == 2 && m && n) {
		regions.clear();
		printf("Region %d\n", ++cases);
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%d", &value);
				regions.push_back(value);
			}
		}
		scanf("%d", &water);
		resolve();
	}
	return 0;
}
