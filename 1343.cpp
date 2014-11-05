/*
 * =====================================================================================
 *
 *       Filename:  1343.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/04/2014 14:16:06
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  cxwcfea(cxwcfea@163.com), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <string>
#include <set>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int kNumSymbol = 24;

struct StateNode {
	int state[kNumSymbol];
	int numMoves;
	string path;
};

pair<int, int> move_a[7] = { {2, 0},{6, 2},{11, 6},{15, 11},{20, 15},{22, 20},{0, 22} };
pair<int, int> move_b[7] = { {3, 1},{8, 3},{12, 8},{17, 12},{21, 17},{23, 21},{1, 23} };
pair<int, int> move_c[7] = { {9, 10},{8, 9},{7, 8},{6, 7},{5, 6},{4, 5},{10, 4} };
pair<int, int> move_d[7] = { {18, 19},{17, 18},{16, 17},{15, 16},{14, 15},{13, 14},{19, 13} };
pair<int, int> move_e[7] = { {1, 3},{3, 8},{8, 12},{12, 17},{17, 21},{21, 23},{23, 1} };
pair<int, int> move_f[7] = { {0, 2},{2, 6},{6, 11},{11, 15},{15, 20},{20, 22},{22, 0} };
pair<int, int> move_g[7] = { {19, 18},{18, 17},{17, 16},{16, 15},{15, 14},{14, 13},{13, 19} };
pair<int, int> move_h[7] = { {10, 9},{9, 8},{8, 7},{7, 6},{6, 5},{5, 4},{4, 10} };
vector<pair<int, int>*> moves;
int position[8] = { 6, 7, 8, 11, 12, 15, 16, 17 };

set<int> state;
int symbols[kNumSymbol];
int currentSymbol;

void init() {
	moves.push_back(move_a);
	moves.push_back(move_b);
	moves.push_back(move_c);
	moves.push_back(move_d);
	moves.push_back(move_e);
	moves.push_back(move_f);
	moves.push_back(move_g);
	moves.push_back(move_h);
}

bool success(int *current_symbol) {
	bool ret = true;

	for (int i = 0; i < 8; ++i) {
		if (current_symbol[position[i]] != current_symbol[position[0]]) {
			ret = false;
			break;
		}
	}

	if (ret) currentSymbol = current_symbol[position[0]];
	return ret;
}	

int getState(int *current_symbol, int symbol) {
	int val = 0;
	for (int i = 0; i < kNumSymbol; ++i) {
		if (current_symbol[i] == symbol) {
			val |= 1 << i;
		}
	}
	return val;
}

int getState2(int *current_symbol) {
	int val = 0;
	for (int i = 0; i < 8; ++i) {
		val = val * 10 + current_symbol[position[i]];	
	}
	return val;
}

void print_state(int *the_state) {
	for (int i = 0; i < kNumSymbol; ++i) {
		printf("%d ", the_state[i]);
	}
	printf("\n");
}

void bfs() {
	queue<StateNode> que;
	StateNode root;
	memcpy(root.state, symbols, sizeof(root.state));
	root.numMoves = 0;
	que.push(move(root));
	state.insert(getState2(root.state));
	//state.insert(getState(root.state, 1));
	//state.insert(getState(root.state, 2));
	//state.insert(getState(root.state, 3));
	
	while (!que.empty()) {
		StateNode u = que.front(); que.pop();

		if (success(u.state)) {
			if (u.path.size())
				printf("%s\n", u.path.c_str());
			else
				printf("No moves needed\n");
			printf("%d\n", currentSymbol);
			return;
		}

		for (int j = 0; j < moves.size(); ++j) {
			StateNode next;
			memcpy(next.state, u.state, sizeof(next.state));
			for (int i = 0; i < 7; ++i) {
				next.state[moves[j][i].second] = u.state[moves[j][i].first];
			}

			int next_state = getState2(next.state);
			//int next_state_1 = getState(next.state, 1);
			//int next_state_2 = getState(next.state, 2);
			//int next_state_3 = getState(next.state, 3);
			//if (!state.count(next_state_1) || !state.count(next_state_2) || !state.count(next_state_3)) {
			if (!state.count(next_state)) {
				//state.insert(next_state_1);
				//state.insert(next_state_2);
				//state.insert(next_state_3);
				state.insert(next_state);
				next.numMoves = u.numMoves + 1;
				next.path = u.path + char(j + 'A');
				que.push(move(next));
			}
		}
	}
}

int main() {
#ifdef Debug
	freopen("1343.in", "r", stdin);
#endif
	init();
	while (true) {
		int i = 0;
		scanf("%d", &symbols[i]);
		if (!symbols[i]) break;
		for (++i; i < kNumSymbol; ++i) {
			scanf("%d", &symbols[i]);
		}
		state.clear();
		bfs();
	}
	return 0;
}

