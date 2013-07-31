#include<cstdio>
#include<ctime>
#include<cstring>

#define MAXN 5
#define MAXSTATE 1000000
#define MAXHASHSIZE 1000003
#define STEP 8

typedef int State[25];

int dir[STEP][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
State st[MAXSTATE];
State goal = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, -1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
char input[STEP];
int head[MAXHASHSIZE];
int next[MAXSTATE];
int dist[MAXSTATE];

int hash(State &s) {
	int value = 0;
	for (int i = 0; i < 25; ++i) {
		value = value * 10 + s[i];
	}
	if (value < 0) value = 0-value;
	return value % MAXHASHSIZE;
}

bool try_to_insert(int s) {
	int h = hash(st[s]);
	int n = head[h];	
	while (n) {
		if (memcmp(st[s], st[n], sizeof(st[s])) == 0) return false;
		n = next[n];
	}
	next[s] = head[h];
	head[h] = s;
	return true;
}

int resolve() {
	memset(head, 0, sizeof(head));
	memset(next, 0, sizeof(next));	
	memset(dist, 0, sizeof(dist));
	int front = 1, rear = 2, i, j, x, y, newx, newy, p;
	try_to_insert(1);
	while (front < rear) {
		State &current = st[front];
		if (memcmp(current, goal, sizeof(current)) == 0) return dist[front]; 
		if (dist[front] == 10) {
			++front;
			continue;
		}
		for (j = 0; j < 25; ++j) {
			if (current[j] == -1) break;
		}
		x = j/5;
		y = j%5;
		for (i = 0; i < STEP; ++i) {
			newx = x+dir[i][0];
			newy = y+dir[i][1];
			if (newx < 0 || newx > 4 || newy < 0 || newy > 4) continue;
			p = newx*5+newy;
			State &t = st[rear];
			memcpy(&t, &current, sizeof(current));
			t[j] = t[p];
			t[p] = -1;
			if (try_to_insert(rear)) {
				dist[rear] = dist[front]+1;
				++rear;
			}
		}
		++front;
	}
	return 11;
}

int main() {
#ifdef Debug
	freopen("10422.in", "r", stdin);
#endif
	int n, j, k, result;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; ++i) {
		for (j = 0; j < MAXN; ++j) {
			fgets(input, STEP, stdin);
			for (k = 0; k < MAXN; ++k) {
				if (input[k] != ' ') {
					st[1][j*5+k] = input[k]-'0';
				} else {
					st[1][j*5+k] = -1;
				}
			}		
		}
		result = resolve();
		if (result > 10) {
			printf("Unsolvable in less than 11 move(s).\n");
		} else {
			printf("Solvable in %d move(s).\n", result);
		}
	}
#ifdef Debug
	printf("time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}
