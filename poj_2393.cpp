#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

#define MAXN 10002

struct Price
{
	int price, index;
};

struct Order
{
	int price, count;
};

Price prices[MAXN];
Order orders[MAXN];

bool comp(const Price &a, const Price &b)
{
	return a.price < b.price;
}

int main()
{
#ifdef Debug
	freopen("poj_2393.in", "r", stdin);
#endif
	int N, S;
	long long result = 0;
	scanf("%d%d", &N, &S);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d%d", &orders[i].price, &orders[i].count); 
		prices[i].index = i;
		prices[i].price = orders[i].price+(N-1-i)*S;
	}
	sort(prices, prices+N, comp);
	int min_cur = 0;
	for (int i = N-1; i >= 0; --i)
	{
		while (prices[min_cur].index > i)
		{
			++min_cur;
		}
		result += (long long)(prices[min_cur].price-(N-1-i)*S)*orders[i].count;
	}
	printf("%lld\n", result);
	return 0;
}

