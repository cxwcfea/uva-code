#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

#define MAXN 20002

typedef long long ll;

priority_queue<ll, vector<ll>, greater<ll> > data;

int main() {
#ifdef Debug
	freopen("poj_3253.in", "r", stdin);
#endif
	int n, t;
	long long result = 0, temp;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &t);
		data.push(t);
	}
	while (data.size() > 1) {
		temp = 0;
		temp += data.top();
		data.pop();
		temp += data.top();
		data.pop();
		data.push(temp);
		result += temp;
	}
	printf("%lld\n", result);
	return 0;
}
