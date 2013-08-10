//贪心， 最小时间不会有蚂蚁相遇，选择距离中点最近的左右两只蚂蚁中距离左右两头最长的。最大时间从中点分开后左右两边蚂蚁都往中间走，有蚂蚁相遇，但是相遇的蚂蚁可以认为只是调换身份，不会影响行进方向，所以选最左端和最右端距离最远的
#include<cstdio>
#include<algorithm>

using namespace std;

#define MAXN 1000003

int data[MAXN];

int main() {
#ifdef Debug
	freopen("10714.in", "r", stdin);
#endif
	int n, pole_len, ant_num, mid, min, max, temp;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &pole_len, &ant_num);
		max = min = 0;
		for (int j = 0; j < ant_num; ++j) {
			scanf("%d", &data[j]);
		}
		if (pole_len % 2) {
			mid = (pole_len + 1) / 2;
		} else {
			mid = pole_len / 2;
		}
		sort(data, data+ant_num);
		int j = 0;
		max = pole_len - data[0];
		temp = data[ant_num-1];
		if (temp > max) max = temp;
		while (data[j] <= mid) {
			++j;
		}
		if (j > 0) {
			min = data[j-1];
		}
		if (j < ant_num) {
			temp = pole_len -data[j];
			if (temp > min) min = temp;	
		}
		printf("%d %d\n", min, max);
	}
	return 0;
}
