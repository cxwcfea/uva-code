#include<cstdio>
#include<map>

using namespace std;

int main() {
#ifdef Debug
	freopen("10763.in", "r", stdin);
#endif
	int n, matched, origin, target;
	multimap<int, int> theMap;
	multimap<int, int>::iterator iter;
	while (1) {
		scanf("%d", &n);
		if (!n) break;
		if (n%2) {
			for (int i = 0; i < n; ++i) {
				scanf("%d%d", &origin, &target);
			}
			printf("NO\n");
			continue;
		}
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &origin, &target);
			matched = 0;
			for (iter = theMap.find(target); iter != theMap.end() && iter->first == target; ++iter) {
				if (iter->second == origin) {
					theMap.erase(iter);
					matched = 1;
					break;
				}
			}
			if (!matched) {
				theMap.insert(make_pair(origin, target));
			}
		}
		if (theMap.empty()) {
			printf("YES\n");
		} else {
			printf("NO\n");
			theMap.clear();
		}
	}
	return 0;
}
