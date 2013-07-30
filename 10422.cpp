#include<cstdio>
#include<cstring>

#define MAXN 5
#define MAXSTATE 1000000
#define MAXHASHSIZE 1000003
#define STEP 8

typedef int State[25];

int dir[STEP][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {-1, -2}};
State goal = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, -1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
char input[STEP];
int head[MAXHASHSIZE];
int next[MAXSTATE];

struct ChessState {
	State s;
	int move;
	int space;
};	

ChessState st[MAXSTATE];

void init_lookup_table() {
	memset(head, 0, sizeof(head));
	memset(next, 0, sizeof(next));	
}

int hash(State &s) {
	int value = 0;
	for (int i = 0; i < 25; ++i) {
		value = value * 10 + s[i];
	}
	return value % MAXHASHSIZE;
}

bool try_to_insert(int s) {
	int h = hash(st[s].s);
	int n = head[h];	
	while (n) {
		if (memcmp(st[s].s, st[n].s, sizeof(st[s].s)) == 0) return false;
		n = next[n];
	}
	next[s] = head[h];
	head[h] = s;
	return true;
}

int resovle() {
	init_lookup_table();
	int front = 1, rear = 2, i, x, y;
	st[1].move = 0;
	while (front < rear) {
		if (current.move == 11) break;
		ChessState &current = st[front];
		++front;
		if (memcmp(current.s, goal, sizeof(goal)) == 0) return current.move; 
		for (i = 0; i < STEP; ++i) {
				
		}	
	}
	return 11;
}

int main() {
#ifdef Debug
	freopen("10422.in", "r", stdin);
#endif
	int n, j, k, temp;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; ++i) {
		for (j = 0; j < MAXN; ++j) {
			fgets(input, STEP, stdin);
			for (k = 0; k < MAXN; ++k) {
				if (input[k] != ' ') {
					st[1].s[j*5+k] = input[k]-'0';
				} else {
					temp = j*5+k
					st[1].s[temp] = -1;
					st[1].space = temp; 
				}
			}		
		}
		for (j = 0; j < MAXN; ++j) {
			for (k = 0; k < MAXN; ++k) {
				printf("%d ", st[1].s[j*5+k]);
			}
			printf("\n");
		}
		printf("%d\n", hash(st[1].s));
		printf("\n");
	}
	return 0;
}
