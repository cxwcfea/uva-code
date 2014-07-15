/*
 * =====================================================================================
 *
 *       Filename:  220.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/12/2014 18:05:20
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  cxwcfea(cxwcfea@163.com), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cstring>

const int kMax = 20;

char board[kMax][kMax];

int dir[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1} };

int num_of_black, num_of_white;

int changes[25][2];
char player;

void PrintBoard() {
	for (int i = 1; i < 9; ++i) {
		for (int j = 1; j < 9; ++j) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}

void CountBoard() {
	num_of_black = num_of_white = 0;
	for (int i = 1; i < 9; ++i) {
		for (int j = 1; j < 9; ++j) {
			if (board[i][j] == 'B') {
				++num_of_black;
			} else if (board[i][j] == 'W') {
				++num_of_white;	
			}
		}
	}
	printf("Black - %2d White - %2d\n", num_of_black, num_of_white);
}

bool CheckMove(int row, int col, char piece_type) {
	if (board[row][col] != '-') {
		return false;
	}
	int r, c;
	char enemy_type = 'B';
	if (piece_type == 'B') {
		enemy_type = 'W';
	}
	for (int i = 0; i < 8; ++i) {
		bool at_least_one_enemy = false;
		r = row + dir[i][0];
		c = col + dir[i][1];
		while (r > 0 && r < 9 && c > 0 && c < 9 && board[r][c] == enemy_type) {	
			r = r + dir[i][0];
			c = c + dir[i][1];
			at_least_one_enemy = true;
		}
		if (r > 0 && r < 9 && c > 0 && c < 9 && board[r][c] == piece_type && at_least_one_enemy) {
			return true;
		}	
	}

	return false;	
}

bool MakeMove(int row, int col, char piece_type) {
	if (board[row][col] != '-') {
		return false;
	}
	int r, c;
	char enemy_type = 'B';
	if (piece_type == 'B') {
		enemy_type = 'W';
	}

	bool have_move = false;
	for (int i = 0; i < 8; ++i) {
		r = row + dir[i][0];
		c = col + dir[i][1];

		int num_of_changes = 0;
		while (r > 0 && r < 9 && c > 0 && c < 9 && board[r][c] == enemy_type) {	
			changes[num_of_changes][0] = r;
			changes[num_of_changes][1] = c;
			++num_of_changes;
			r = r + dir[i][0];
			c = c + dir[i][1];
		}

		if (r > 0 && r < 9 && c > 0 && c < 9 && board[r][c] == piece_type && num_of_changes) {
			have_move = true;
			for (int i = 0; i < num_of_changes; ++i) {
				board[changes[i][0]][changes[i][1]] = piece_type;
			}
		}	
	}

	if (have_move) {
		board[row][col] = piece_type;
		CountBoard();
		return true;
	}

	return false;	
}

void ListLegal(char player) {
	bool can_move = false;
	for (int i = 1; i < 9; ++i) {
		for (int j = 1; j < 9; ++j) {
			if (CheckMove(i, j, player)) {
				if (!can_move) {
					can_move = true;
				} else {
					printf(" ");
				}
				printf("(%d,%d)", i, j);
			}
		}
	}
	
	if (!can_move)
		printf("No legal move.");

	printf("\n");
}

void ChangePlayer() {
	if (player == 'B') {
		player = 'W';
	} else {
		player = 'B';
	}
}

int main() {
#ifdef Debug
	freopen("220.in", "r", stdin);
#endif
	int n;
	char input[kMax];
	fgets(input, kMax, stdin);
	sscanf(input, "%d", &n);
	while (n--) {
		for (int i = 1; i < 9; ++i) {
			fgets(board[i]+1, kMax, stdin);
		}
		
		//PrintBoard();

		fgets(input, kMax, stdin);
		player = input[0];
		//printf("%c\n", player);
		while (true) {
			fgets(input, kMax, stdin);
			if (input[0] == 'Q') {
				PrintBoard();
				break;
			} else if (input[0] == 'L') {
				ListLegal(player);
			} else if (input[0] == 'M') {
				int r = input[1] - '0';
				int c = input[2] - '0';
				if (!MakeMove(r, c, player)) {
					ChangePlayer();
					MakeMove(r, c, player);
				}
				//PrintBoard();
				ChangePlayer();
				//printf("%c\n", player);
			}
		}

		if (n) {
			printf("\n");
		}
	}
	return 0;
}
