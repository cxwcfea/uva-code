#include <cstdio>
#include <algorithm>
#include <set>
#include <ctime>

using namespace std;

#define MAXN 50002
struct Section {
	int first, second, origin;
};

struct Stall {
	int last_pos;
	int index;
	bool operator<(const Stall &a) const  
    {  
        return last_pos < a.last_pos;  
    }
};

Section sections[MAXN];

bool comp(const Section &a, const Section &b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

int main() {
#ifdef Debug
	freopen("poj_3190.in", "r", stdin);
#endif
	int N;
	multiset<Stall> last_in_stall;
	int stalls[MAXN];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d%d", &sections[i].first, &sections[i].second);
		sections[i].origin = i;
	}
	sort(sections, sections+N, comp);
	Stall temp, stall;
	temp.index = 0;
	for (int i = 0; i < N; ++i) {
		temp.last_pos = sections[i].first;
		multiset<Stall>::iterator it = last_in_stall.lower_bound(temp);
		if (it == last_in_stall.begin()) {
			stall.index = last_in_stall.size()+1;
			stall.last_pos = sections[i].second;
			stalls[sections[i].origin] = stall.index;
			last_in_stall.insert(stall);
		} else {
			--it;
			stall = *it;
			stalls[sections[i].origin] = stall.index;
			stall.last_pos = sections[i].second;
			last_in_stall.erase(it);
			last_in_stall.insert(stall);
		}
	}
	printf("%d\n", (int)last_in_stall.size());
	for (int i = 0; i < N; ++i) {
		printf("%d\n", stalls[i]);
	}
#ifdef Debug
	printf("time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}
