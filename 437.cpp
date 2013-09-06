#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>

using namespace std;

#define MAXN 31

struct Block {
	int x, y, z;
	int getWidth(int &type) {
		switch (type) {
			case 0:
				return x;
			case 1:
				return y;
			case 2:
				return z;
			default:
				return x;
		}
	}
	int getHeight(int &type) {
		switch (type) {
			case 0:
				return y;
			case 1:
				return z;
			case 2:
				return x;
			default:
				return y;
		}
	}
	int getValue(int &type) {
		switch (type) {
			case 0:
				return z;
			case 1:
				return x;
			case 2:
				return y;
			default:
				return z;
		}
	}
};

Block blocks[MAXN];
int n;
int d[MAXN][3];

int dp(int index, int type) {
	int &ans = d[index][type];
	if (ans >= 0) return ans;
	int width, height, w, h;
	ans = 0;
	for (int i = 0; i < n; ++i) {
		width = blocks[index].getWidth(type);
		height = blocks[index].getHeight(type);
		for (int j = 0; j < 3; ++j) {
			w = blocks[i].getWidth(j);
			h = blocks[i].getHeight(j);
			if ((w < width && h < height) || (w < height && h < width)) {
				ans = max(ans, dp(i, j)+blocks[i].getValue(j));	
			}
		}
	}
	return ans;
}

int main() {
#ifdef Debug
	freopen("437.in", "r", stdin);
#endif
	int i, cases = 1;
	while (1) {
		scanf("%d", &n);
		if (!n) break;
		for (i = 0; i < n; ++i) {
			scanf("%d%d%d", &blocks[i].x, &blocks[i].y, &blocks[i].z);
		}
		memset(d, -1, sizeof(d));
		blocks[n].x = blocks[n].y = blocks[n].z = INT_MAX;
		printf("Case %d: maximum height = %d\n", cases++, dp(n, 0));
	}	
	return 0;
}
