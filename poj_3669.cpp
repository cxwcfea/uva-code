#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

#define MAXN 304

struct Node {
	int x, y, t;
};

int matrix[MAXN][MAXN];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int flag[MAXN][MAXN];

int bfs() {
	queue<Node> que;
	int ret = 0;		
	Node node;
	node.x = node.y = node.t = 0;
	flag[node.y][node.x] = 1;
	que.push(node);
	while (!que.empty()) {
		Node current = que.front();
		que.pop();
		if (matrix[current.y][current.x] == -1) {
			return current.t;
		}
		for (int j = 0; j < 4; ++j) {
			Node next;
			next.x = current.x+dir[j][0];
			next.y = current.y+dir[j][1];
			if (next.x >= 0 && next.y >= 0 && !flag[next.y][next.x]) {
				next.t = current.t+1;
				if (matrix[next.y][next.x] == -1 || matrix[next.y][next.x] > next.t) {
					flag[next.y][next.x] = 1;
					que.push(next);
				}
			}
		}
	}
	return -1;	
}

int main() {
#ifdef Debug
	freopen("poj_3669.in", "r", stdin);
#endif
	int M;
	memset(matrix, -1, sizeof(matrix));
	memset(flag, 0, sizeof(flag));
	scanf("%d", &M);
	int x, y, t, _x, _y;
	for (int i = 0; i < M; ++i) {
		scanf("%d%d%d", &x, &y, &t);
		if (matrix[y][x] == -1 || matrix[y][x] > t)
			matrix[y][x] = t;
		for (int j = 0; j < 4; ++j) {
			_x = x+dir[j][0];
			_y = y+dir[j][1];
			if (_x >= 0 && _y >= 0) {
				if (matrix[_y][_x] == -1 || matrix[_y][_x] > t) {
					matrix[_y][_x] = t;
				}
			}
		}
	}
	printf("%d\n", bfs());
	return 0;
}
