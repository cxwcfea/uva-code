#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

#define MAXN 205

int d;
int result_amound[MAXN];
int cup[3];

struct Node {
	int v[3];
	int dist_amount;
    bool operator<(const Node &other) const {
        return dist_amount > other.dist_amount;
    }
};

int dist[MAXN][MAXN];
bool vis[MAXN][MAXN];

void update(const Node &n) {
    for (int i = 0; i < 3; ++i) {
        if (result_amound[n.v[i]] < 0 || result_amound[n.v[i]] > n.dist_amount) {
            result_amound[n.v[i]] = n.dist_amount;
        }
    } 
}

void resolve() {
    priority_queue<Node> nodes;
    memset(result_amound, -1, sizeof(result_amound));
    memset(dist, -1, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    Node start;
    start.v[0] = start.v[1] = 0;
    start.v[2] = cup[2];
    start.dist_amount = 0;
    nodes.push(move(start));
    dist[0][0] = 0;
	while (!nodes.empty()) {
        Node u = nodes.top();
        nodes.pop();
        if (vis[u.v[0]][u.v[1]]) continue;
        vis[u.v[0]][u.v[1]] = true;
        update(u);
		if (result_amound[d] >= 0) {
			return;
		}
		for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i != j && u.v[i] && u.v[j] != cup[j]) {
                    int amount = min(cup[j], u.v[i] + u.v[j]) - u.v[j];
                    Node n;
                    memcpy(&n, &u, sizeof(u)); 
                    n.v[i] -= amount;
                    n.v[j] += amount;
                    n.dist_amount += amount;
                    int &D = dist[n.v[0]][n.v[1]];
                    if (D < 0 || n.dist_amount < D) {
                        D = n.dist_amount;
                        nodes.push(move(n));
                    }
                }
            }
		}
	}
}

int main() {
#ifdef Debug
	freopen("10603.in", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d%d", &cup[0], &cup[1], &cup[2], &d);
		resolve();
        for (int i = d; i >= 0; --i) {
            if (result_amound[i] >= 0) {
                printf("%d %d\n", result_amound[i], i);
                break;
            }
        }
	}
#ifdef Debug
	printf("time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}
