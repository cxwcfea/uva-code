#include <cstdio>

#define MAXN 7

int sizes[MAXN];

int main()
{
#ifdef Debug
	freopen("poj_1017.in", "r", stdin);
#endif
	int ret;
	while (1)
	{
		scanf("%d%d%d%d%d%d", &sizes[1], &sizes[2], &sizes[3], &sizes[4], &sizes[5], &sizes[6]);
		if (!sizes[1] && !sizes[2] && !sizes[3] && !sizes[4] && !sizes[5] && !sizes[6]) break;
		ret = 0;
		ret += sizes[6];
		ret += sizes[5];
		int un_used_1 = 11 * sizes[5];
		ret += sizes[4];
		un_used_1 += 20 * sizes[4];
		int un_used_2 = 5 * sizes[4];
		int temp = sizes[3]%4;
		ret += sizes[3]/4 + 1;	
		switch (temp)
		{
			case 0:
				ret -= 1;
				break;
			case 1:
				un_used_2 += 5;
				un_used_1 += 27;
				break;
			case 2:
				un_used_2 += 3;
				un_used_1 += 18;
				break;
			case 3:
				un_used_2 += 1;
				un_used_1 += 9;
				break;
			default:
				break;
		}
		if (sizes[2] <= un_used_2)
		{
			un_used_2 -= sizes[2];
			un_used_1 -= sizes[2]*4;
		}
		else
		{
			int t = sizes[2] - un_used_2;
			temp = t%9;
			ret += t/9;
			if (temp)
			{
				ret++;
				un_used_1 += 36-temp*4;
			}
			un_used_1 -= 4*un_used_2;
			un_used_2 = 0;
		}
		if (sizes[1] > un_used_1)
		{
			int t = sizes[1]-un_used_1;
			temp = t%36;
			ret += t/36;
			if (temp)
				++ret;
		}
		printf("%d\n", ret);	
	}
	return 0;
}

