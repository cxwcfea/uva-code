#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>

using namespace std;

#define MAXN 30000
int data[MAXN];

int main() {
#ifdef Debug
	freopen("10041.in", "r", stdin);
#endif
	int n, r, s, p, result;
	vector<int> relative;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		memset(data, 0, sizeof(data));
		scanf("%d", &r);
		for (int j = 0; j < r; ++j) {
			scanf("%d", &s);
			++data[s];
		}	
		relative.clear();
		for (int j = 0; j < MAXN; ++j) {
			while (data[j] > 0) {
				relative.push_back(j);
				--data[j];
			}
		}
		p = relative.size()/2;	
		result = 0;
		for (vector<int>::iterator iter = relative.begin(); iter != relative.end(); ++iter) {
			result += abs(relative[p]-*iter);
		}
		printf("%d\n", result);
	}
	return 0;
}
